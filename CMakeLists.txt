cmake_minimum_required(VERSION 3.19)
project(KitsuneLib)

set(CMAKE_CXX_STANDARD 20)

set(LIB_DIRS
        src/Common
        src/WinUtils
        src/String
        src/Time
        src/Random
        )

include_directories(${LIB_DIRS})

if (WIN32)
    link_libraries(psapi)
else ()
endif ()

add_library(KitsuneLib
        src/Common/TypeDef/TypeDef.h
        src/WinUtils/WinProcess.h src/WinUtils/WinProcess.cpp src/WinUtils/WinAdmin.h src/WinUtils/WinAdmin.cpp
        src/String/StringUtil.h src/String/StringUtil.cpp src/String/KString.cpp src/String/KString.h
        src/Time/DateFormat.h src/Time/DateFormat.cpp
        src/Random/Random.h src/Random/Random.cpp
        )