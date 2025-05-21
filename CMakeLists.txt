cmake_minimum_required(VERSION 3.0)
project(engine)

# get all sources inside src folder
file(GLOB SOURCES "src/*")

add_library(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)