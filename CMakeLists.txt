cmake_minimum_required(VERSION 3.31)
project(BallJumper)

set(CMAKE_CXX_STANDARD 23)

add_executable(BallJumper src/main.cpp
        src/Game.cpp
        include/Game.h
        src/Player.cpp
        include/Player.h
        src/Ball.cpp
        include/Ball.h
        include/Utils.h
        include/Input.h
        src/Resources.cpp
        include/Resources.h
)

# Find raylib package
find_package(raylib REQUIRED)

# Include header directories
target_include_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/libs
)

# Link raylib and any dependencies (raylib links glfw, opengl, etc automatically)
target_link_libraries(${PROJECT_NAME} PRIVATE
        raylib
        ${CMAKE_SOURCE_DIR}/libs/libSimple_ECS.dylib
        )


