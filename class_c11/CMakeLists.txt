cmake_minimum_required(VERSION 3.16)
project(main)

# c++11を明示的に有効化する
add_compile_options(-std=c++11)

set(MY_SOURCE main.cpp)

add_executable(${PROJECT_NAME} ${MY_SOURCE})
