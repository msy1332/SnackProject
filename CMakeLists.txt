cmake_minimum_required(VERSION 4.0.0)#要求cmake最低版本
project(SnackProject
    VERSION 0.0.1#项目的版本
    DESCRIPTION "SnackProject"#项目的描述
    HOMEPAGE_URL "https://github.com/msy1332/SnackProject"#项目的地址
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)#指定C++版本

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)#设置可执行文件的输出目录

add_subdirectory(src)#添加子目录

#设置变量
set(PutImage_Dir ${CMAKE_SOURCE_DIR}/src/PutImage)
set(Snake_Dir ${CMAKE_SOURCE_DIR}/src/Snake)
set(Food_Dir ${CMAKE_SOURCE_DIR}/src/Food)