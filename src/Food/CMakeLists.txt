#指定工程名
project(Food)

add_library(${PROJECT_NAME}
    SHARED
    Food.cpp
)

#链接easyx库
target_link_libraries(${PROJECT_NAME}
    PUBLIC
    easyx
)