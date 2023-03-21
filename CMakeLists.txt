cmake_minimum_required(VERSION 3.16)

project(genexec)

add_executable(./*.cpp)

install(TARGETS ./*.cpp DESTINATION instdir)
