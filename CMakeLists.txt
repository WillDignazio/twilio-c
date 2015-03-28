cmake_minimum_required(VERSION 2.8)
project(twilio-c)

add_library(twilioc encode.c rest.c twilio.c)
target_include_directories(twilioc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
