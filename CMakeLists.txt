cmake_minimum_required(VERSION 3.10)

project(genexec)

if (UNIX)
    message(STATUS ">>> Unix environment detected")
    set(myOSOutput "unix")
elseif (WIN32)
    message(STATUS ">>> Windows environment detected")
    set(CMAKE_CXX_FLAGS "-w")
    set(myOSOutput "windows")
else()
    message(STATUS ">>> Unknown")
    set(myOSOutput "macos")
endif()

file(GLOB SRC_FILES *.cpp)
foreach(srcfile ${SRC_FILES})
    get_filename_component(srcname1 ${srcfile} NAME)
    string(REPLACE ".cpp" ${myOSOutput} srcname ${srcname1})
    add_executable(${srcname} ${srcfile})
    install(TARGETS ${srcname} DESTINATION instdir-${myOSOutput})
endforeach(srcfile ${SRC_FILES})



