cmake_minimum_required(VERSION 3.0)
project(demo)

add_executable(${PROJECT_NAME} main.cpp src/scenes/scene1.cpp src/scenes/scene2.cpp)
target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../build)
target_link_libraries(${PROJECT_NAME} engine sfml-graphics sfml-window sfml-system)