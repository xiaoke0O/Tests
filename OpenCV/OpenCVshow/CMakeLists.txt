cmake_minimum_required (VERSION 3.10)

project ("OpenCVshow")
find_package(OpenCV)
add_executable (OpenCVshow "main.cpp" )

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
