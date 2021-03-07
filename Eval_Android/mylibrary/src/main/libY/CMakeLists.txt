cmake_minimum_required(VERSION 3.10)

#
# libY (Shared Library)
#
project(Y
        VERSION 1.0.0
        DESCRIPTION "Y first version"
        LANGUAGES CXX
        )

add_library(Y
        SHARED
        ../../../../../src/Y/libY.cc)

target_compile_features(Y
        PRIVATE
        cxx_std_11)

target_include_directories(Y
        PRIVATE
        ../../../../../include)

target_compile_options(Y
        PUBLIC
        $<$<CONFIG:SanitizeCheck>:-g>
        )

target_link_options(Y
        PUBLIC
        $<$<CONFIG:SanitizeCheck>:-fsanitize=address -fno-omit-frame-pointer>
        )

