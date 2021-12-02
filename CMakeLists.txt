cmake_minimum_required(VERSION 3.14)
project(game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(SOURCE_FILES main.cpp)

add_definitions(-DSFML_STATIC)
add_executable(game main.cpp inc/src/classes.cpp inc/src/classes.hpp)
include_directories(inc/src)
include_directories(inc/img)
include_directories(/usr/local/include)


include_directories(${SFML_INCLUDE_DIRS})
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
target_link_libraries(game sfml-system sfml-window sfml-graphics sfml-audio sfml-network)