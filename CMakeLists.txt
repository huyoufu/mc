cmake_minimum_required(VERSION 3.17)
#工程名字 和使用语言
project(mc C)

set(CMAKE_C_STANDARD 99)

include_directories("./include")

add_subdirectory("./gtests")
#添加可执行文件
add_executable(mc src/main.c  src/xml/sxml.c   )
