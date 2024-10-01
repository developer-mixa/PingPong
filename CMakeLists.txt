cmake_minimum_required(VERSION 3.5.0)

set(PROJECT_NAME PingPong)
project(${PROJECT_NAME} VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)


add_executable(
    ${PROJECT_NAME}
    src/main.cpp
    src/core/Engine.cpp
    src/main/start_screen/StartScreen.cpp
)

add_custom_target(copy_assets
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/assets ${CMAKE_CURRENT_BINARY_DIR}/assets
)
add_dependencies(${PROJECT_NAME} copy_assets)


target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/include)
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio)