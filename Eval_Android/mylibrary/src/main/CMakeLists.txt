cmake_minimum_required(VERSION 3.10)

find_library(log-lib
        log)

#
# native-lib
#
project(native-lib)

add_library(
        native-lib
        SHARED
        cpp/native-lib.cpp
)

target_include_directories(native-lib
        PRIVATE
        ../../../../include)

target_compile_options(native-lib
        PUBLIC
        $<$<CONFIG:SanitizeCheck>:-g>
        )

target_link_options(native-lib
        PUBLIC
        $<$<CONFIG:SanitizeCheck>:-fsanitize=address -fno-omit-frame-pointer>
        )

add_subdirectory(libX)
add_subdirectory(libY)

target_link_libraries(native-lib
        X
        Y
        ${log-lib})

