cmake_minimum_required(VERSION 3.31)
project(PG_Drzewo_Trie C)

set(CMAKE_C_STANDARD 11)

add_executable(PG_Drzewo_Trie main.c structs.h trie.c trie.h)
