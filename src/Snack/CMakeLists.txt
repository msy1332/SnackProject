#指定工程名
project(Snack)

add_library(${PROJECT_NAME}
    SHARED
    Snack.cpp
)

#链接easyx库
target_link_libraries(${PROJECT_NAME}
    PUBLIC
    easyx
)