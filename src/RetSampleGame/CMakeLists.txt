cmake_minimum_required(VERSION 3.13)

project(RetSampleGame)

file(GLOB Sources ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB Headers ${CMAKE_CURRENT_SOURCE_DIR}/*.(h|hpp))

add_executable(RetSampleGame SampleGame.cpp)
target_link_libraries(RetSampleGame RetApplication)