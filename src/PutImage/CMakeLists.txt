#指定工程名
project(PutImage)

add_library(${PROJECT_NAME}
    SHARED
    PutImage.cpp
)

#链接easyx库
target_link_libraries(${PROJECT_NAME}
    PUBLIC
    easyx
)