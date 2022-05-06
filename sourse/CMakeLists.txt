cmake_minimum_required(VERSION 3.8) 

project(APP)			

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)


set(SOURCE_EXE main.cpp)			

include_directories(FPath)		

add_executable(fpath ${SOURCE_EXE})	

add_subdirectory(FPath)				

target_link_libraries(fpath PRIVATE FPath)
