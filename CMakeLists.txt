cmake_minimum_required(VERSION 3.19)
project(KitsuneLib)

set(CMAKE_CXX_STANDARD 20)

set(LIB_DIRS
        src/Common
        src/WinProcess
        src/String
        src/Time
        )

include_directories(${LIB_DIRS})

if (WIN32)
    link_libraries(psapi)
else ()
endif ()

add_library(KitsuneLib
        src/Common/TypeDef/TypeDef.h
        src/WinProcess/WinProcess.h src/WinProcess/WinProcess.cpp
        src/String/StringUtil.h src/String/StringUtil.cpp src/String/kstring.cpp src/String/kstring.h
        #src/Time/DateFormat.h src/Time/DateFormat.cpp
        )