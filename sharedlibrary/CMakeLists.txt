cmake_minimum_required(VERSION 3.16)

# c++11を明示的に有効化する
add_compile_options(-std=c++11)

# c++11で書くとcmakeに教える(↑の別の書き方)
#set (CMAKE_CXX_STANDARD 11)

#add_libraryにSHAREDの指定を省略可
set(BUILD_SHARED_LIBS ON)

set(PROJECT_NAME3 mylib3)
set(MY_LIB_SOURCE1 library1.cpp library1.h)
add_library(${PROJECT_NAME3} SHARED library1.cpp library1.h)

#set(PROJECT_NAME2 mylib2)
#set(MY_LIB_SOURCE2 library2.cpp library2.h)

add_library(mylib1 SHARED library1.cpp library1.h)
add_library(mylib2 SHARED library2.cpp library2.h)

set(PROJECT_NAME1 main)
project(${PROJECT_NAME1})

set(PROJECT_NAME2 main2)
project(${PROJECT_NAME2})

add_executable(${PROJECT_NAME1} main.cpp)
add_executable(${PROJECT_NAME2} main2.cpp)

target_link_libraries(${PROJECT_NAME1} mylib1)
target_link_libraries(${PROJECT_NAME2} mylib1 mylib2)
