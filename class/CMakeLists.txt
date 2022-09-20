cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME1 main)
project(${PROJECT_NAME1})

set(PROJECT_NAME2 main2)
project(${PROJECT_NAME2})

#変数にパスを追加する書き方も可能(ワイルドカード(*)表現も可)
set(MY_SOURCE main2.cpp)
set(MY_SOURCE ${MY_SOURCE} sub.cpp)
set(MY_SOURCE ${MY_SOURCE} sub.h)

add_executable(${PROJECT_NAME1} main.cpp sub.cpp sub.h)
add_executable(${PROJECT_NAME2} ${MY_SOURCE})
