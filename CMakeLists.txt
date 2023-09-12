cmake_minimum_required(VERSION 3.14)

project(ArduinoLibrarySkeleton LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ask for all warnings and strict compliance with the standard
set(CMAKE_CXX_FLAGS "-Wall -Werror -pedantic")

add_library(ArduinoLibrarySkeleton STATIC
  src/arduinolibraryskeleton.h
  src/arduinolibraryskeleton.cpp
)

target_compile_definitions(ArduinoLibrarySkeleton PRIVATE ARDUINOLIBRARYSKELETON_LIBRARY)
target_include_directories(ArduinoLibrarySkeleton PUBLIC src)

# target_link_libraries(ArduinoLibrarySkeleton PUBLIC <TBD>)  # use this if the library depends from other libraries
