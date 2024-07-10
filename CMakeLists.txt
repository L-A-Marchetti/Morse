cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(morse C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(morse
	morse.cpp
	)

target_link_libraries(morse pico_stdlib)

pico_enable_stdio_usb(morse 1)
pico_enable_stdio_uart(morse 0)

pico_add_extra_outputs(morse)