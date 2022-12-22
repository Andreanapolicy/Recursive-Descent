cmake_minimum_required(VERSION 3.23)
project(RecursiveDescent)

set(CMAKE_CXX_STANDARD 20)

add_executable(RecursiveDescent main.cpp src/Common/NonTerminalSymbols.h src/Common/TerminalSymbols.h)
