# pico
Raspberry Pi Pico experiments

https://www.raspberrypi.com/products/raspberry-pi-pico/

## Micropython

[See README in folder micropython](./micropython)

## How to build the C++ examples

Install the pico-sdk and set the environment variable PICO_SDK_PATH pointing there.

On Windows with "Developer Command Prompt for VS 2017" execute:
```
mkdir build
cd build
cmake -G "NMake Makefiles" ..
nmake
```

Alternatively, launch VisualStudio Code from this shell with the CMake Tools configured for "cmake.generator": "NMake Makefiles".

## Pin-Out

<img src="./pico-gpios.png" /> 
