file(GLOB_RECURSE INC "include/*.hh")
file(GLOB_RECURSE SRC "src/*.cc")

add_library(meringue_protocol)
target_sources(meringue_protocol PRIVATE ${INC} ${SRC})
target_include_directories(meringue_protocol
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
target_link_libraries(meringue_protocol
    PUBLIC gsl meringue_common
    PRIVATE meringue_copts_common)

configure_lto(meringue_protocol)
configure_clang_tidy(meringue_protocol)
