cmake_minimum_required(VERSION 3.14)

project(meringue VERSION 0.1 LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(test.helper)
include(with.helper)
include(lto.helper)

option(MERINGUE_CLANG_TIDY "Build with clang-tidy" ON)
option(MERINGUE_TESTS "Build and add tests" ON)
option(MERINGUE_LTO "Build with Link-Time Optimization" OFF)

WithMsg(clang-tidy ${MERINGUE_CLANG_TIDY})
WithMsg(tests ${MERINGUE_TESTS})
WithMsg("link-time optimization" ${MERINGUE_LTO})

if (MERINGUE_CLANG_TIDY)
    include(clang-tidy.helper)
endif()

if (MERINGUE_TESTS)
    include(CTest)
    enable_testing()
endif()

set(MERINGUE_RELEASE_CFLAGS -O3 -ffast-math -fvisibility=hidden)
set_property(GLOBAL PROPERTY G_MERINGUE_RELEASE_CFLAGS ${MERINGUE_RELEASE_CFLAGS})

add_library(meringue_copts_common INTERFACE)
target_compile_options(meringue_copts_common INTERFACE
    -pedantic
    -W
    -Wall
    -Wextra
    -Wcast-align
    -Wcast-qual
    -Wmissing-declarations
    -Wwrite-strings
    -Wundef
    -Wswitch-enum
    -Wshadow
    -Werror
    -Wstrict-aliasing=2
    $<$<CXX_COMPILER_ID:Clang>:-Wshadow-all>
    $<$<CXX_COMPILER_ID:GNU>:
        $<$<STREQUAL:$<CONFIG>,Debug>:
            -ggdb
        >
    >
    $<$<STREQUAL:$<CONFIG>,Release>:${MERINGUE_RELEASE_CFLAGS}>)

add_subdirectory(3rdparty)

add_subdirectory(meringue_common)
add_subdirectory(meringue_client)
add_subdirectory(meringue_daemon)
add_subdirectory(meringue_protocol)
add_subdirectory(meringue_scheduler)
