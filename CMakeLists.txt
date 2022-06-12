cmake_minimum_required(VERSION 3.20)
project(WDC65C02)

set(CMAKE_CXX_STANDARD 20)

add_executable(WDC65C02 main.cpp BUS.cpp BUS.h ROM.cpp ROM.h VIA.cpp VIA.h ACIA.cpp ACIA.h CPU.cpp CPU.h)
