cmake_minimum_required(VERSION 3.23)
project(CS_HW)

set(CMAKE_CXX_STANDARD 14)

set(PROJECT_HEADERS
        MovieRentalSystem.h
        Node.h
        SortedLinkedList.h
        )
set(PROJECT_SOURCES
        main.cpp
        MovieRentalSystem.cpp
        )

add_executable(CS_HW ${PROJECT_SOURCES} ${PROJECT_HEADERS})
