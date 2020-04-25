file(GLOB_RECURSE INC "include/*.hh")
file(GLOB_RECURSE SRC "src/*.cc")

add_executable(meringue_client ${INC} ${SRC})
target_link_libraries(meringue_client PRIVATE meringue_copts_common meringue_protocol)

configure_lto(meringue_client)
configure_clang_tidy(meringue_client)
