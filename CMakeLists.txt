
cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 14) # Change standard version if you want

set(PROJECT_NAME "CPPTemplate") # Change to your project name

project(${PROJECT_NAME} VERSION 1.0)

add_library(${PROJECT_NAME} STATIC)

target_include_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/includes
        ${CMAKE_CURRENT_SOURCE_DIR}/sources
)

target_sources(${PROJECT_NAME} PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/sources/bowlingGame.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/sources/helpForTest.cpp"
)

add_executable(${PROJECT_NAME}_executable "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")
target_link_libraries(${PROJECT_NAME}_executable LINK_PUBLIC ${PROJECT_NAME})

enable_testing()
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)