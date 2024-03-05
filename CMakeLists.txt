cmake_minimum_required(VERSION 3.1)

project(ultrasonic_lib)

find_library(wiringPi_lib wiringPi)

include_directories(${CMAKE_SOURCE_DIR}/inc)

aux_source_directory(${CMAKE_SOURCE_DIR}/src DIR_SRCS)

add_library(ultrasonic ${DIR_SRCS})

target_link_libraries(ultrasonic ${wiringPi_lib})

install(TARGETS ultrasonic DESTINATION /usr/lib)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/inc/ DESTINATION /usr/include)
