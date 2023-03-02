cmake_minimum_required(VERSION 3.20)
project(LabOrganizer)

set(CMAKE_CXX_STANDARD 14)

add_executable(LabOrganizer main.cpp LabOrganizer.cpp LabOrganizer.h Chemical.cpp Chemical.h Cabinet.cpp Cabinet.h)
