file(GLOB_RECURSE INC "include/*.hh")
file(GLOB_RECURSE SRC "src/*.cc")

add_executable(meringue_scheduler ${INC} ${SRC})
target_link_libraries(meringue_scheduler PRIVATE
    meringue_copts_common
    argsparser gsl)

configure_lto(meringue_scheduler)
configure_clang_tidy(meringue_scheduler)
