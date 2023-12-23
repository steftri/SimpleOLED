cmake_minimum_required(VERSION 3.14)

project(SimpleOLED LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ask for all warnings and strict compliance with the standard
set(CMAKE_CXX_FLAGS "-Wall -Werror -pedantic")

add_library(SimpleOLED STATIC
  src/simpleoled.h
  src/simpleoled.cpp
  src/configSimpleOLED.h
  display_font_default.h
  display_font_C64.h
  display_font_topaz.h
)

target_compile_definitions(SimpleOLED PRIVATE SIMPLEOLED_LIBRARY)
target_include_directories(SimpleOLED PUBLIC src)

# target_link_libraries(SimpleOLED PUBLIC <TBD>)  # use this if the library depends from other libraries
