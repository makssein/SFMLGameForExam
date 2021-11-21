cmake_minimum_required(VERSION 3.14)
project(sfml_sample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(SOURCE_FILES main.cpp)

add_definitions(-DSFML_STATIC)
add_executable(sfml_sample ${SOURCE_FILES})
include_directories(/usr/local/include)


include_directories(${SFML_INCLUDE_DIRS})
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
target_link_libraries(sfml_sample sfml-system sfml-window sfml-graphics sfml-audio sfml-network)