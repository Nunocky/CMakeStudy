cmake_minimum_required(VERSION 3.10)


# TODO libX, libYをサブフォルダに分割したほうが読みやすくなる (オプションの書き換えが面倒になるが)

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
  ../src/X/libX.cc)

# ライブラリのビルドをC++11規格で実行するように指定
target_compile_features(X
  PRIVATE
  cxx_std_11)

target_include_directories(X
  PRIVATE
  ../include)

target_compile_options(X
  PUBLIC
  $<$<CONFIG:SanitizeCheck>:-g>
  )

target_link_options(X
  PUBLIC
  $<$<CONFIG:SanitizeCheck>:-fsanitize=address -fno-omit-frame-pointer>
  )

# MEMO : このようにして cmake中で使える変数を定義できる
set_target_properties(X
  PROPERTIES
  VERSION ${PROJECT_VERSION}
  )


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
  ../src/Y/libY.cc)

target_compile_features(Y
  PRIVATE
  cxx_std_11)

target_include_directories(Y
  PRIVATE
  ../include)

target_compile_options(Y
  PUBLIC
  $<$<CONFIG:SanitizeCheck>:-g>
  )

target_link_options(Y
  PUBLIC
  $<$<CONFIG:SanitizeCheck>:-fsanitize=address -fno-omit-frame-pointer>
  )


#
# app
#
project(hello_world
  CXX)

add_executable(app main.cc)

target_include_directories(app
  PRIVATE
  ../include)

target_compile_features(app
  PRIVATE
  cxx_std_11)

target_compile_options(app
  PUBLIC
  $<$<CONFIG:SanitizeCheck>:-g>
  )

target_link_options(app
  PUBLIC
  $<$<CONFIG:SanitizeCheck>:-fsanitize=address -fno-omit-frame-pointer>
  )


target_link_libraries(app X Y)
