cmake_minimum_required(VERSION 3.9)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

project(parser CXX)

add_executable(parser 
    src/main.cpp
    src/parse.cpp
    src/print.cpp
    src/parse_input.cpp
)
    
target_include_directories(parser
    PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    target_compile_options(parser
        PUBLIC
            -Wall 
            -Wextra 
            -Werror=return-type
            -Werror=switch
        
            -Werror
            -Wshadow
    )
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    target_compile_options(parser
        PUBLIC
            -Wall 
            -Wextra 
            -Werror=return-type
            -Werror=switch
            -Wfatal-errors
            -g
            -ggdb
        
            -Werror
            -Wshadow
            -Wnon-virtual-dtor
            -Wold-style-cast
            -Wcast-align
            -Wunused
            -Woverloaded-virtual
            -Wpedantic
            -Wconversion
            -Wsign-conversion
            -Wmisleading-indentation
            -Wduplicated-cond
            -Wlogical-op
            -Wnull-dereference
            -Wdouble-promotion
            -Wformat=2
    )
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    target_compile_options(parser
        PUBLIC     
            /permissive
            /W4
            /w14640
            /w14242
            /w14254
            /w14263
            /w14265
            /w14287
            /we4289
            /w14296
            /w14311
            /w14545
            /w14546
            /w14547
            /w14549
            /w14555
            /w14640
            /w14826
            /w14905
            /w14906
            /w14928
    )
    source_group("src" REGULAR_EXPRESSION "src/.*")
endif()
