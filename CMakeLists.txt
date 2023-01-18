cmake_minimum_required(VERSION 3.18)
project(RecursiveDescent)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_library(catch2 INTERFACE)
target_include_directories(catch2 INTERFACE catch2/)

add_executable(RecursiveDescent
               main.cpp
               src/Common/Args.cpp
               src/Common/Args.h
               src/Parser.cpp
               src/Parser.h
               src/Descent/Common/NonTerminalSymbols.h
               src/Descent/Common/TerminalSymbols.h
               src/Descent/Common/IFunction.cpp
               src/Descent/Common/IFunction.h
               src/Descent/Common/Utils.h
               src/Descent/Prog.h
               src/Descent/Type.h
               src/Descent/Var.h
               src/Descent/Exp.h
               src/Descent/T.h
               src/Descent/F.h
               src/Descent/Listst.h
               src/Descent/Write.h
               src/Descent/Read.h
               src/Descent/Assign.h)

add_subdirectory(tests)
