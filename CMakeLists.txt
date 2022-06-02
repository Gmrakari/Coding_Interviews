cmake_minimum_required(VERSION 3.17)
project(Coding_Interviews)

set(CMAKE_CXX_STANDARD 11)

#链接库
#aux_source_directory(leetcode/editor/cn/include LEETCODE)
#add_library(leetcode ${LEETCODE})
#LINK_LIBRARIES(leetcode)


add_executable(Two-Sum "leetcode/editor/cn/Two-Sum.cpp")
add_executable(Longest-Substring-Without-Repeating-Characters leetcode/editor/cn/Longest-Substring-Without-Repeating-Characters.cpp)
add_executable(merge-two-sorted-list leetcode/editor/cn/merge-two-sorted-list.cpp)
add_executable(Reverse-Linked-List "leetcode/editor/cn/Reverse-Linked-List.cpp")
add_executable(Sort-an-Array leetcode/editor/cn/Sort-an-Array.cpp)
add_executable(getKthLastNode leetcode/editor/cn/getKthLastNode.cpp)
add_executable(virtual_polymorphism_output leetcode/editor/cn/altobeam_05_25/virtual_polymorphism_output.cpp)
add_executable(strcpy_and_filterstr leetcode/editor/cn/justcall_05_26/strcpy_and_filterstr.c)
add_executable(fliterStr leetcode/editor/cn/justcall_05_26/fliterStr.cpp leetcode/editor/cn/justcall_05_26/fliterStr.cpp)
add_executable(sizeof_struct_and_strlen_etc leetcode/editor/cn/justcall_05_26/sizeof_struct_and_strlen_etc.
add_executable(sizeof_structA_B leetcode/editor/cn/ouryun_06_01/sizeof_structA_B.c
