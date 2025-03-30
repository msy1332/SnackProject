#指定工程名
project(SnackMain)

#添加子目录
add_subdirectory(PutImage)
add_subdirectory(Snake)
add_subdirectory(Food)
add_subdirectory(Game)

#添加可执行文件
add_executable(${PROJECT_NAME} SnackMain.cpp)

#显示控制台终端
set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE ON)

#包含贪吃蛇的主页面目录下的头文件
target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${PutImage_Dir}
    ${Snake_Dir}
    ${Food_Dir}
    ${Game_Dir}
)

#链接贪吃蛇的主页面生成的动态库
target_link_libraries(${PROJECT_NAME}
    PUBLIC
    PutImage
    Snake
    Food
    easyx
    Game
    Winmm
)