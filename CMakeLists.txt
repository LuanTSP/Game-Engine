cmake_minimum_required(VERSION 3.0)
project(engine)

add_library(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/engine.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/utils.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)