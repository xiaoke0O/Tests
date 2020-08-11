cmake_minimum_required(VERSION 3.10.0)
project(TestQtShow VERSION 0.1.0)
find_package(Qt5Widgets)
add_executable(TestQtShow main.cpp)

target_link_libraries(TestQtShow PRIVATE Qt5::Widgets)