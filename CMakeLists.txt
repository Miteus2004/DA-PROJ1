cmake_minimum_required(VERSION 3.27)
project(DA_PROJ1)

set(CMAKE_CXX_STANDARD 17)

add_executable(DA_PROJ1 src/main.cpp
        src/City.cpp
        src/City.h
        src/FileReader.cpp
        src/FileReader.h
        src/Menu.cpp
        src/Menu.h
        src/Pipe.cpp
        src/Pipe.h
        src/Point.cpp
        src/Point.h
        src/Reservoir.cpp
        src/Reservoir.h
        src/Station.cpp
        src/Station.h
        src/EdmondsKarp.h)
