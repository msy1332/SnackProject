#指定工程名
project(Snake)

add_library(${PROJECT_NAME}
    SHARED
    Snake.cpp
)

#链接easyx库
target_link_libraries(${PROJECT_NAME}
    PUBLIC
    easyx
)