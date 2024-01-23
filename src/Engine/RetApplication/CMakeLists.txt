cmake_minimum_required(VERSION 3.13)

project(RetApplication)

file(GLOB Sources ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)


add_library(RetApplication SHARED
	${Sources}
) 

target_sources(RetApplication PRIVATE ${Sources})
target_include_directories(RetApplication PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")