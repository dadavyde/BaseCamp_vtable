cmake_minimum_required (VERSION 3.1)

project (Vtable)

set (SOURCES
            main.cpp
            base.cpp
            derived.cpp
            )

add_executable (${CMAKE_PROJECT_NAME} ${SOURCES})

