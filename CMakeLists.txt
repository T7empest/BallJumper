cmake_minimum_required(VERSION 3.31)
project(BallJumper)

set(CMAKE_CXX_STANDARD 23)

# Define the executable
add_executable(BallJumper
        src/main.cpp
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

# Include header directories
target_include_directories(BallJumper PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/libs
)

# Find raylib (must be installed/found properly for both platforms)
find_package(raylib REQUIRED)

# Link raylib
target_link_libraries(BallJumper PRIVATE raylib)

# Platform-specific linking
if (APPLE)
        message(STATUS "Building on macOS")
        target_link_libraries(BallJumper PRIVATE ${CMAKE_SOURCE_DIR}/libs/libSimple_ECS.dylib)
elseif (WIN32)
        message(STATUS "Building on Windows")
        # Adjust these based on your Windows build of the lib
        target_link_libraries(BallJumper PRIVATE ${CMAKE_SOURCE_DIR}/libs/Simple_ECS.lib)

        # If your lib requires a DLL at runtime, make sure it's available near your .exe
        add_custom_command(TARGET BallJumper POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                ${CMAKE_SOURCE_DIR}/libs/Simple_ECS.dll
                $<TARGET_FILE_DIR:BallJumper>)
endif ()