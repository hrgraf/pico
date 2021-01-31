# How to build on Windows with "Developer Command Prompt for VS 2017":
#   mkdir build
#   cd build
#   cmake -G "NMake Makefiles" ..
#   nmake

cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(midi_test_project)

pico_sdk_init()

#add_definitions(-DBOARD=raspberry_pi_pico)
#include_directories(src)

add_executable(midi_test
    src/usb_descriptors.c
    src/main.c
    )

target_include_directories(midi_test PRIVATE
    src)
    
# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(midi_test pico_stdlib tinyusb_device tinyusb_board)

# create map/bin/hex file etc.
pico_add_extra_outputs(midi_test)


