find_program(
  CLANG_TIDY_EXE
  NAMES "clang-tidy"
  DOC "Path to clang-tidy executable"
  )

if(NOT CLANG_TIDY_EXE)
  message(FATAL_ERROR "clang-tidy not found.")
endif()

function(clang_tidy_check TARGET)
    # Include header files from the same directory
    get_filename_component(SOURCE_DIR_NAME "${CMAKE_CURRENT_SOURCE_DIR}" NAME)
    set(DO_CLANG_TIDY "${CLANG_TIDY_EXE}" "-p=${CMAKE_CURRENT_BUILD_DIR}/" "--header-filter=${SOURCE_DIR_NAME}/.*")

    set_target_properties(${TARGET} PROPERTIES C_CLANG_TIDY "${DO_CLANG_TIDY}")
    set_target_properties(${TARGET} PROPERTIES CXX_CLANG_TIDY "${DO_CLANG_TIDY}")
endfunction()

function(configure_clang_tidy TARGET)
    if (MERINGUE_CLANG_TIDY)
        clang_tidy_check(${TARGET})
    endif()
endfunction()
