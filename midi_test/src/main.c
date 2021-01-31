//--------------------------------------------------------------------+
// Pico MIDI Test by H.R.Graf
//
// Works out-of-the-box on Raspberry Pi Pico using USB-MIDI
// No MIDI DIN circuit needed.
//
// Received Note On/Off control built-in LED and are sent back on channel 2
// with slight change in pitch (to demonstrate active functionality).
//
//--------------------------------------------------------------------+

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "bsp/board.h"
#include "tusb.h"

#include "midi.h"

//--------------------------------------------------------------------+
// MACRO CONSTANT TYPEDEF PROTYPES
//--------------------------------------------------------------------+

/* Blink pattern
 * - 250 ms  : device not mounted
 * - 1000 ms : device mounted
 * - 2500 ms : device is suspended
 */
enum  {
  BLINK_NOT_MOUNTED = 250,
  BLINK_MOUNTED = 1000,
  BLINK_SUSPENDED = 2500,
};

static uint32_t blink_interval_ms = BLINK_NOT_MOUNTED;

//--------------------------------------------------------------------+
// BLINKING TASK
//--------------------------------------------------------------------+

static void led_blinking_task(void)
{
  static uint32_t start_ms = 0;
  static bool led_state = false;

  // Blink every interval ms
  if ( board_millis() - start_ms < blink_interval_ms) return; // not enough time
  start_ms += blink_interval_ms;

  board_led_write(led_state);
  led_state = 1 - led_state; // toggle
}

//--------------------------------------------------------------------+
// MIDI Task
//--------------------------------------------------------------------+

static void handleMidiEv(char *buf, int len)
{
    static char msg[4];
    if (! len)
        return;

    char channel = 2;
    char status = buf[0];
    switch (status & 0xF0)
    {
    case MIDI_NOTEOFF:
        if (len != 3)
            return;
        board_led_write(false);
        msg[0] = MIDI_NOTEOFF | channel;
        msg[1] = buf[1] + 1; // key
        msg[2] = buf[2]; // velocity
        tud_midi_write(0, msg, 3);
        break;

    case MIDI_NOTEON:
        if (len != 3)
            return;
        board_led_write(true);
        msg[0] = MIDI_NOTEON | channel;
        msg[1] = buf[1] + 1; // key
        msg[2] = buf[2]; // velocity
        tud_midi_write(0, msg, 3);
        break;
    }
}

static int getMidiEvLen(char status)
{
    int len = 0;
    switch (status & 0xF0)
    {
    case MIDI_NOTEOFF:         len = 3; break;
    case MIDI_NOTEON:          len = 3; break;
    case MIDI_POLYKEYPRESSURE: len = 3; break;
    case MIDI_PROGRAMCHANGE:   len = 2; break;
    case MIDI_CHANNELPRESSURE: len = 2; break;
    case MIDI_PITCHBEND:       len = 3; break;
    }
    return len;
}

static void midi_task(void)
{
    static char recvBuf[20];
    static int  recvPos = 0;
    
    // get (more) data
    if (recvPos < sizeof(recvBuf))
    {
        //int len = tud_midi_available();
        int len = tud_midi_read(&recvBuf[recvPos], sizeof(recvBuf) - recvPos);
        recvPos += len;
    }

    // parse data
    int i = 0;
    while (i < recvPos)
    {
        if (recvBuf[i] & 0x80) // status
        {
            int len = getMidiEvLen(recvBuf[i]);
            if (len > 0)
            {
                if ((i + len) > recvPos)
                    break; // not enough data yet

                // handle midi event
                handleMidiEv(&recvBuf[i], len);
                i += len;
            }
            else
                i++; // skip
        }
        else
            i++; // skip
    }

    if (i >= recvPos)
    {
        recvPos = 0; // all consumed
    }
    else if (i > 0) // partly consumed
    {
        recvPos -= i;

        // shift down
        for (int j = 0; j < recvPos; j++)
            recvBuf[j] = recvBuf[j + i];
    }
}

//--------------------------------------------------------------------+
// MAIN
//--------------------------------------------------------------------+

int main(void)
{
  board_init();

  tusb_init();

  while (1)
  {
    tud_task(); // tinyusb device task
    if (blink_interval_ms != BLINK_MOUNTED)
      led_blinking_task();
    midi_task();
  }


  return 0;
}

//--------------------------------------------------------------------+
// Device callbacks
//--------------------------------------------------------------------+

// Invoked when device is mounted
void tud_mount_cb(void)
{
  blink_interval_ms = BLINK_MOUNTED;
}

// Invoked when device is unmounted
void tud_umount_cb(void)
{
  blink_interval_ms = BLINK_NOT_MOUNTED;
}

// Invoked when usb bus is suspended
// remote_wakeup_en : if host allow us  to perform remote wakeup
// Within 7ms, device must draw an average of current less than 2.5 mA from bus
void tud_suspend_cb(bool remote_wakeup_en)
{
  (void) remote_wakeup_en;
  blink_interval_ms = BLINK_SUSPENDED;
}

// Invoked when usb bus is resumed
void tud_resume_cb(void)
{
  blink_interval_ms = BLINK_MOUNTED;
}

//--------------------------------------------------------------------+
