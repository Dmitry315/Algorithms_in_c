cmake_minimum_required(VERSION 3.17)
project(algnstructs C)

set(CMAKE_C_STANDARD 11)

add_library(algnstructs library.c library.h avl.c avl.h list.c list.h stack.c stack.h queue.c queue.h)