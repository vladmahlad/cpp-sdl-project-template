cmake_minimum_required(VERSION 3.28)
project("sample_sdl_project")

add_subdirectory("submodules/SDL" EXCLUDE_FROM_ALL)
add_subdirectory("src")