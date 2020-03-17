cmake_minimum_required(VERSION 3.15)
project(feature_abstraction_test C)

set(CMAKE_C_STANDARD 11)

add_executable(feature_abstraction_test main.c feature.h feature_name.c feature_leds.c feature_leds2.c)