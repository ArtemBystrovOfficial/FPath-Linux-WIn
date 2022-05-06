cmake_minimum_required(VERSION 3.8) 
								
project(FPath)				

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

set(SOURCE_LIB FPath.cpp)		

add_library(FPath STATIC ${SOURCE_LIB})
