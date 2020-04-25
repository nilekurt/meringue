file(GLOB_RECURSE INC "include/*.hh")
file(GLOB_RECURSE SRC "src/*.cc")

add_executable(meringue_daemon ${INC} ${SRC})
target_link_libraries(meringue_daemon PRIVATE meringue_copts_common)

configure_lto(meringue_daemon)
configure_clang_tidy(meringue_daemon)
