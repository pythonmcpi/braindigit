cmake_minimum_required(VERSION 3.12)
project(braindigit)

set(CMAKE_CXX_STANDARD 14)

include_directories(h)

add_executable(braindigit
        h/Common.h
        h/CPPTranspiler.h
        h/CTranspiler.h
        h/Flags.h
        h/Interpreter.h
        h/PythonTranspiler.h
        h/RubyTranspiler.h
        h/System.h
        h/TextColour.h
        src/CPPTranspiler.cpp
        src/CTranspiler.cpp
        src/Flags.cpp
        src/Interpreter.cpp
        src/main.cpp
        src/PythonTranspiler.cpp
        src/RubyTranspiler.cpp
        src/System.cpp)
