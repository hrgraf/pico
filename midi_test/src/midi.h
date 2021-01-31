#ifndef MIDI_H
#define MIDI_H

// MIDI Status Bytes
#define MIDI_NONE            0x0

#define MIDI_NOTEOFF         0x80
#define MIDI_NOTEON          0x90
#define MIDI_POLYKEYPRESSURE 0xA0   // AKA Polyphonic Aftertouch
#define MIDI_CONTROLCHANGE   0xB0
#define MIDI_PROGRAMCHANGE   0xC0
#define MIDI_CHANNELPRESSURE 0xD0   // AKA Aftertouch
#define MIDI_PITCHBEND       0xE0

// Sysex and more
#define MIDI_SYSEX           0xF0
#define MIDI_SYSTEMCOMMON    0xF1   // Undefined System Common
#define MIDI_SONGPOSITION    0xF2
#define MIDI_SONGSELECT      0xF3
#define MIDI_F4              0xF4   // UNDEFINED IN MIDI SPEC
#define MIDI_F5              0xF5   // UNDEFINED IN MIDI SPEC
#define MIDI_TUNEREQUEST     0xF6
#define MIDI_EOX             0xF7   // End OF SysEx
#define MIDI_TIMINGCLOCK     0xF8
#define MIDI_F9              0xF9   // UNDEFINED IN MIDI SPEC
#define MIDI_START           0xFA
#define MIDI_CONTINUE        0xFB   // NOTE SPELLING
#define MIDI_STOP            0xFC
#define MIDI_FD              0xFD   // UNDEFINED IN MIDI SPEC
#define MIDI_ACTIVESENSING   0xFE   // This signal may be sent by a MIDI transmitter when there is no other activity.
#define MIDI_SYSTEMRESET     0xFF


// control numbers for MIDI_CONTROL_CHANGE (MIDI status byte 0xB0)
// note: not a complete list

//MSBs
#define MIDI_BANK_CHANGE            0x00
#define MIDI_MODULATION_WHEEL       0x01
#define MIDI_BREATH_CONTROL         0x02
#define MIDI_UNDEFINED_CC03         0x03
#define MIDI_FOOT_CONTROLLER        0x04
#define MIDI_PORTAMENTO_TIME        0x05
#define MIDI_DATA_ENTRY             0x06
#define MIDI_CHANNEL_VOLUME         0x07
#define MIDI_BALANCE                0x08
#define MIDI_UNDEFINED_CC09         0x09
#define MIDI_PAN                    0x0A
#define MIDI_EXPRESSION             0x0B
#define MIDI_EFFECT_CONTROL1        0x0C
#define MIDI_EFFECT_CONTROL2        0x0D
#define MIDI_UNDEFINED_CC0E         0x0E
#define MIDI_UNDEFINED_CC0F         0x0F
#define MIDI_GENERAL_PURPOSE_1      0x10
#define MIDI_GENERAL_PURPOSE_2      0x11
#define MIDI_GENERAL_PURPOSE_3      0x12
#define MIDI_GENERAL_PURPOSE_4      0x13
#define MIDI_UNDEFINED_CC14         0x14
#define MIDI_UNDEFINED_CC15         0x15
#define MIDI_UNDEFINED_CC16         0x16
#define MIDI_UNDEFINED_CC17         0x17
#define MIDI_UNDEFINED_CC18         0x18
#define MIDI_UNDEFINED_CC19         0x19
#define MIDI_UNDEFINED_CC1A         0x1A
#define MIDI_UNDEFINED_CC1B         0x1B
#define MIDI_UNDEFINED_CC1C         0x1C
#define MIDI_UNDEFINED_CC1D         0x1D
#define MIDI_UNDEFINED_CC1E         0x1E
#define MIDI_UNDEFINED_CC1F         0x1F
//[0x20:0x3F] are LSBs
#define MIDI_LSB                    0x20


#define MIDI_SUSTAIN                0x40
#define MIDI_PORTAMENTO             0x41
#define MIDI_SOSTENUTO              0x42
#define MIDI_SOFT                   0x43
#define MIDI_HOLD_2                 0x45
#define MIDI_GENERAL_PURPOSE_5      0x50
#define MIDI_GENERAL_PURPOSE_6      0x51
#define MIDI_GENERAL_PURPOSE_7      0x52
#define MIDI_GENERAL_PURPOSE_8      0x53


#define MIDI_EXTERNAL_EFFECTS_DEPTH 0x5B
#define MIDI_TREMELO_DEPTH          0x5C
#define MIDI_CHORUS_DEPTH           0x5D
#define MIDI_CELESTE_DEPTH          0x5E
#define MIDI_PHASER_DEPTH           0x5F
#define MIDI_DATA_INCREMENT         0x60
#define MIDI_DATA_DECREMENT         0x61
#define MIDI_NONREG_PARAM_NUM_MSB   0x62
#define MIDI_NONREG_PARAM_NUM_LSB   0x63
#define MIDI_REG_PARAM_NUM_MSB      0x64
#define MIDI_REG_PARAM_NUM_LSB      0x65

#define MIDI_ALL_SOUND_OFF          0x78
#define MIDI_RESET_ALL_CONTROLLERS  0x79
#define MIDI_LOCAL_CONTROL          0x7A
#define MIDI_ALL_NOTES_OFF          0x7B
#define MIDI_OMNI_MODE_OFF          0x7C
#define MIDI_OMNI_MODE_ON           0x7D
#define MIDI_MONO_MODE_ON           0x7E
#define MIDI_POLY_MODE_ON           0x7F

#endif
