cmake_minimum_required(VERSION 3.18)
project(RecursiveDescent)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(RecursiveDescent main.cpp src/Common/NonTerminalSymbols.h src/Prog.h src/Type.h src/Var.h src/Exp.h src/T.h src/F.h src/Common/TerminalSymbols.h)
