cmake_minimum_required(VERSION 3.15)
project(GDAL)

set(CMAKE_CXX_STANDARD 14)

find_package(GDAL REQUIRED)
add_executable(GDAL ReadHDF.cpp)

target_include_directories(GDAL PRIVATE ${GDAL_INCLUDE_DIRS})
target_link_libraries(GDAL PRIVATE ${GDAL_LIBRARIES})
