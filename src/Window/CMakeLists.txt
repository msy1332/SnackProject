#指定工程名
project(Window)

#添加动态库
add_library(${PROJECT_NAME}
    SHARED
    Window.cpp
)

#链接easyx库
target_link_libraries(${PROJECT_NAME}
    PUBLIC
    easyx
)