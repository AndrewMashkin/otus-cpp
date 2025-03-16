cmake_minimum_required(VERSION 3.0)

project(ip_loader)

set(CMAKE_CXX_STANDARD_REQUIRED 17)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
	${CMAKE_CURRENT_SOURCE_DIR}/lib/*.cpp
	)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_library(${PROJECT_NAME} SHARED ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME})

if(UNITTEST)
	include(unittest.cmake)
endif()

