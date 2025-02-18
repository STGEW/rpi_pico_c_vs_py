cmake_minimum_required(VERSION 3.13)


set( PICO_SDK_PATH "/home/$ENV{USER}/build/pico/pico-sdk" )
include(${PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(gpio_blinking C CXX ASM)
pico_sdk_init()

add_executable(gpio_blinking main.c)
target_link_libraries(gpio_blinking pico_stdlib)

pico_add_extra_outputs(gpio_blinking)
