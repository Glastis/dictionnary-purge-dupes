cmake_minimum_required(VERSION 3.16)
project(purge_dupes C)

set(CMAKE_C_STANDARD 90)

add_executable(purge_dupes
        main.c              headers/main.h
        file.c              headers/file.h
        headers/const.h
        )