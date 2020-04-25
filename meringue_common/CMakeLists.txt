file(GLOB_RECURSE INC "include/*.hh")
file(GLOB_RECURSE SRC "src/*.cc")

add_library(meringue_common)
target_sources(meringue_common PRIVATE ${INC} ${SRC})
target_include_directories(meringue_common
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
target_link_libraries(meringue_common
    PUBLIC gsl
    PRIVATE meringue_copts_common)

configure_lto(meringue_common)
configure_clang_tidy(meringue_common)
