cmake_minimum_required(VERSION 3.6)

project(text_query)

set(CMAKE_CXX_STANDARD 14)


include_directories(include)


set(SOURCE_FILES
		src/Finder.cpp src/Query.cpp src/TextQuery.cpp src/AndQuery.cpp src/NotQuery.cpp src/aa.cpp src/aa.h)

add_executable(text_query ${SOURCE_FILES})
