cmake_minimum_required(VERSION 3.13)

set( PICO_SDK_PATH "/home/$ENV{USER}/build/pico/pico-sdk" )
include(${PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(matrix_mult C CXX ASM)

pico_sdk_init()

add_executable(matrix_mult main.c)
target_link_libraries(matrix_mult pico_stdlib)

pico_add_extra_outputs(matrix_mult)
