#
# Copyright (c) 2015 Will Dignazio
#

#
# Project Information
#
cmake_minimum_required(VERSION 2.8)
project(twilio-c)

#
# Building and Installation
#
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra -pedantic")

#
# Source and Output
#
add_library(twilioc encode.c rest.c twilio.c)
target_include_directories(twilioc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
