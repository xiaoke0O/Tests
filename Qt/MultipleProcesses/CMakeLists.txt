# cmake最小支持版本
cmake_minimum_required(VERSION 3.10)

# 设置项目名，并制定指定语言为C++
project(MultipleProcesses LANGUAGES CXX)

# 自动增加当前源目录和编译目录到Include Path
# 如果源代码中包含编译目录的内容，开启这个选项相当有用
# 如include "ui_mainwindow.h"，这个可以在编译阶段自动在编译目录生成。
# 开启该选项，在源代码中只需要简单地写include "ui_mainwindow.h"。
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# 自动运行uic，生成ui_*.h
set(CMAKE_AUTOUIC ON)

# 自动生成元对象文件
# TODO：写一篇MOC的介绍文章
set(CMAKE_AUTOMOC ON)

# 自动运行rcc,将qrc文件 生成c文件参与编译为可执行文件
set(CMAKE_AUTORCC ON)

# 设置C++标准为C++ 11
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 要用到的包
find_package(Qt5 COMPONENTS Widgets LinguistTools REQUIRED)

# 设置TS文件路径
set(TS_FILES i18n/MultipleProcesses_zh_CN.ts)
# 那些文件参与编译成最终的可执行文件
add_executable(MultipleProcesses WIN32
    main.cpp
    multipleping.cpp
    multipleping.h
    multipleping.ui
    translation.qrc
    ${TS_FILES}
    )
# 链接动态链接库
target_link_libraries(MultipleProcesses PRIVATE Qt5::Widgets)
# 创建翻译文件
qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
