cmake_minimum_required(VERSION 3.30)
project(Lab4 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Lab4
    cai_functions.c
    cai_functions.h
    main.c)
