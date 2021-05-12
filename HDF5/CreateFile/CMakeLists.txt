# The HDF5 1.12.x product requires a minimum CMake version of 3.12.
cmake_minimum_required(VERSION 3.12)
project(TestHDF5Write)
find_package(HDF5 COMPONENTS CXX)
add_executable(TestHDF5Write main.cpp)
target_include_directories(TestHDF5Write PRIVATE ${HDF5_CXX_INCLUDE_DIRS} )
target_link_libraries(TestHDF5Write ${HDF5_CXX_LIBRARIES})