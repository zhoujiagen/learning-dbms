cmake_minimum_required (VERSION 3.16)
project (file-structure)

# C99, C++11
set (CMAKE_C_STANDARD 99)
set (CMAKE_CXX_STANDARD 11)

# 库
include_directories("${PROJECT_SOURCE_DIR}/lib")
add_subdirectory (lib)
set (EXTRA_LIBS ${EXTRA_LIBS} libfs)

# 各子目录
add_subdirectory(ch01)
add_subdirectory(ch02)
add_subdirectory(ch04)
add_subdirectory(ch07)
