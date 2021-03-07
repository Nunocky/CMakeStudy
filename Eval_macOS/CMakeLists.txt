cmake_minimum_required(VERSION 3.10)


# clang: error: unsupported option '-fsanitize=memory' for target 'x86_64-apple-darwin20.3.0'
# clang: error: unsupported option '-fsanitize=leak' for target 'x86_64-apple-darwin20.3.0'

#
# app
#
project(hello_world
  CXX)

add_executable(app main.cc)
add_subdirectory(libX)
add_subdirectory(libY)

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
