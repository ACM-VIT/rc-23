cmake_minimum_required(VERSION 3.10)

project(genexec)

if (UNIX)
    message(STATUS ">>> Unix environment detected")
    set(myOSOutput "-linux.lin")
elseif (WIN32)
    message(STATUS ">>> Windows environment detected")
    set(CMAKE_CXX_FLAGS "-w")
    set(myOSOutput "-windows.exe")
else()
    message(STATUS ">>> Unknown")
    set(myOSOutput "-macos.mac")
endif()

file(GLOB SRC_FILES *.cpp)
foreach(srcfile ${SRC_FILES})
    get_filename_component(srcname1 ${srcfile} NAME)
    string(REPLACE ".cpp" ${myOSOutput} srcname ${srcname1})
    add_executable(${srcname} ${srcfile})
    install(TARGETS ${srcname} DESTINATION instdir)
endforeach(srcfile ${SRC_FILES})



