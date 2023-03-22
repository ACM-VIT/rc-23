cmake_minimum_required(VERSION 3.10)

project(genexec)

if (UNIX)
    message(STATUS ">>> Unix environment detected")
    set(myOSOutput "-linux.lin")
    set(dest "instdir-linux")
    if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
        message(STATUS ">>> Clang compiler detected")
        # Add any Clang-specific settings or flags here
        set(myOSOutput "-macos.mac")
        set(dest "instdir-macos")
        set(CMAKE_CXX_STANDARD 11)
    endif()
elseif (WIN32)
    message(STATUS ">>> Windows environment detected")
    set(CMAKE_CXX_FLAGS "-w")
    set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CXX_STANDARD_LIBRARIES}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")
    set(myOSOutput "-windows")
    set(dest "instdir-windows")
else()
    message(STATUS ">>> Unknown")
    set(myOSOutput "-macos.mac")
    set(dest "instdir-macos")
endif()

file(GLOB SRC_FILES *.cpp)
foreach(srcfile ${SRC_FILES})
    get_filename_component(srcname1 ${srcfile} NAME)
    string(REPLACE ".cpp" ${myOSOutput} srcname ${srcname1})
    add_executable(${srcname} ${srcfile})
    install(TARGETS ${srcname} DESTINATION ${dest})
endforeach(srcfile ${SRC_FILES})



