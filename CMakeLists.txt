cmake_minimum_required(VERSION 3.15)
#工程名字 和使用语言
project(mc )

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=UTF-8")
#头文件所在目录
include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/googletest/include
)
#连接目录
link_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/googletest
)

# 添加下级目录，生成.a文件
add_subdirectory("./googletest")
add_subdirectory("./src/file-operations")


message("main.cpp~~~~~~~~~~~~~")



#收集源代码目录
aux_source_directory(./src SRC_LIST)
set(SOURCE_FILES src/main.cpp)

#add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${SRC_LIST})
add_executable(${PROJECT_NAME} src/main.cpp)



add_executable(mytest
        ./test/main.cpp
        ./src/file-operations/repofile-list_test.cxx
        )


#设置cmake 输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
#为主程序添加连接库
target_link_libraries(${PROJECT_NAME} gtest repofileops)
#为测试程序添加连接库
target_link_libraries(mytest gtest repofileops)

