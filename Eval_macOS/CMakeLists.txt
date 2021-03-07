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
  ../src/X/libX.cc)

# ライブラリのビルドをC++11規格で実行するように指定
target_compile_features(X
  PRIVATE
  cxx_std_11)

target_include_directories(X
  PRIVATE
  ../include)

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

set_target_properties(Y
  PROPERTIES
  VERSION ${PROJECT_VERSION}
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

target_link_libraries(app X Y)
