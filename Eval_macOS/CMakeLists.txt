cmake_minimum_required(VERSION 3.10)

#
# libX (Shared Library)
#
project(libX
  VERSION 1.0.0
  DESCRIPTION "libX first version"
  LANGUAGES CXX
)

add_library(libX
  SHARED
  ../src/X/libX.cc)

# ライブラリのビルドをC++11規格で実行するように指定
target_compile_features(libX
  PRIVATE
  cxx_std_11)

target_include_directories(libX
  PRIVATE
  ../include)

set_target_properties(libX
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

target_link_libraries(app libX)
