cmake_minimum_required(VERSION 3.10)

project(native-lib)

find_library(log-lib
        log)


add_library(
        native-lib
        SHARED
        cpp/native-lib.cpp

        #        src/main/cpp/native-lib.cpp
)

target_include_directories(native-lib
        PRIVATE
        ../../../../include)

add_subdirectory(libX)
add_subdirectory(libY)

target_link_libraries(native-lib
        X
        Y
        ${log-lib})

