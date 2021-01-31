# How to build on Windows with "Developer Command Prompt for VS 2017":
#   mkdir build
#   cd build
#   cmake -G "NMake Makefiles" ..
#   nmake

cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(test_project)

pico_sdk_init()

add_executable(test
    test.c
    )

# enable USB
pico_enable_stdio_usb(test 1)

# enable UART
pico_enable_stdio_uart(test 1)

# create map/bin/hex file etc.
pico_add_extra_outputs(test)

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(test pico_stdlib)

