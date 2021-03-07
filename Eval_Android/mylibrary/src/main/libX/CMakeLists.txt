cmake_minimum_required(VERSION 3.10)

#
# libX (Shared Library)
#
project(X
        VERSION 1.0.0
        DESCRIPTION "libX first version"
        LANGUAGES CXX
        )

add_library(X
        SHARED
        ../../../../../src/X/libX.cc)

# ライブラリのビルドをC++11規格で実行するように指定
#target_compile_features(X
#        PRIVATE
#        cxx_std_11)

target_include_directories(X
        PRIVATE
        ../../../../../include)

target_compile_options(X
        PUBLIC
        $<$<CONFIG:SanitizeCheck>:-g>
        )

target_link_options(X
        PUBLIC
        $<$<CONFIG:SanitizeCheck>:-fsanitize=address -fno-omit-frame-pointer>
        )

#target_compile_options(X
#        PUBLIC
#        -fsanitize=address -fno-omit-frame-pointer
#        )
#
#set_target_properties(X
#        PROPERTIES
#        LINK_FLAGS -fsanitize=address)

# MEMO : このようにして cmake中で使える変数を定義できる
set_target_properties(X
        PROPERTIES
        VERSION ${PROJECT_VERSION}
        )
