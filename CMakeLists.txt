cmake_minimum_required(VERSION 3.14)

project(TinyDisplay LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ask for all warnings and strict compliance with the standard
set(CMAKE_CXX_FLAGS "-Wall -Werror -pedantic")

add_library(TinyDisplay STATIC
  src/TinyDisplay.h
  src/TinyDisplay.cpp
  src/configTinyDisplay.h
)

target_compile_definitions(TinyDisplay PRIVATE TINYDISPLAY_LIBRARY)
target_include_directories(TinyDisplay PUBLIC src)

# target_link_libraries(TinyDisplay PUBLIC <TBD>)  # use this if the library depends from other libraries
