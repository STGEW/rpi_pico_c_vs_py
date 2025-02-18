cmake_minimum_required(VERSION 3.13)

set( PICO_SDK_PATH "/home/$ENV{USER}/build/pico/pico-sdk" )
include(${PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(factorial)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# rest of your project
add_executable(factorial main.c)
target_link_libraries(factorial pico_stdlib)

pico_add_extra_outputs(factorial)
