cmake_minimum_required(VERSION 3.15)
#工程名字 和使用语言
project(mc)
#设置 debug程序或lib文件的后缀
set(CMAKE_DEBUG_POSTFIX "_d")
#设置 release程序或lib文件的后缀
set(CMAKE_RELEASE_POSTFIX "_r")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/build/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/build/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/build/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/build/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/build/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE  ${PROJECT_SOURCE_DIR}/build/bin)
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
#当前操作系统信息
MESSAGE(STATUS "operation system is ${CMAKE_SYSTEM}")
# 添加下级目录，生成.a文件
add_subdirectory("./googletest")
add_subdirectory("./src/file-operations")
add_subdirectory("./src/index-operations")
add_subdirectory("./src/util")

#收集源代码目录
aux_source_directory(./src SRC_LIST)
set(SOURCE_FILES src/main.cpp)


#add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${SRC_LIST})
add_executable(${PROJECT_NAME} src/main.cpp)

add_executable(file-operations_test
        ./test/main.cpp
        ./src/file-operations/repofile-list_test.cxx
        )
add_executable(index_operations_test
        ./test/main.cpp
        ./src/mc.c
        ./src/index-operations/repoindex-ops_test.cxx
        )
add_executable(util_test
        ./test/main.cpp
        ./src/util/dict.c
        ./src/util/mt19937-64.c
        ./src/util/siphash.c
        ./src/util/dict_test.cxx
        )
#为主程序添加连接库
target_link_libraries(${PROJECT_NAME} gtest repofileops collection)
#为测试程序添加连接库
target_link_libraries(util_test gtest collection )

target_link_libraries(file-operations_test gtest repofileops)

target_link_libraries(index_operations_test gtest repoindex sqlite3)


