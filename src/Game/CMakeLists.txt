#指定工程名
project(Game)

add_library(${PROJECT_NAME}
    SHARED
    Game.cpp
)

#链接easyx库
target_link_libraries(${PROJECT_NAME}
    PUBLIC
    easyx
    Snake
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${Snake_Dir}
)