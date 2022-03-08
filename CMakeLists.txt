cmake_minimum_required(VERSION 3.20)
project(GameOfLife C)

set(CMAKE_C_STANDARD 99)

add_executable(GameOfLife main.c gameOfLife.c gameOfLife.h)
