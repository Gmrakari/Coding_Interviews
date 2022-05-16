cmake_minimum_required(VERSION 3.17)
project(Coding_Interviews)

set(CMAKE_CXX_STANDARD 11)

#链接库
#aux_source_directory(leetcode/editor/cn/include LEETCODE)
#add_library(leetcode ${LEETCODE})
#LINK_LIBRARIES(leetcode)


add_executable(Two-Sum "leetcode/editor/cn/Two-Sum.cpp")
add_executable(Longest-Substring-Without-Repeating-Characters leetcode/editor/cn/Longest-Substring-Without-Repeating-Characters.cpp)