cmake_minimum_required(VERSION 3.13)

set( PICO_SDK_PATH "/home/$ENV{USER}/build/pico/pico-sdk" )
include(${PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(summation C CXX ASM)

pico_sdk_init()

add_executable(summation main.c)
target_link_libraries(summation pico_stdlib)

pico_add_extra_outputs(summation)
