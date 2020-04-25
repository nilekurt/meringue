include (FetchContent)

FetchContent_Declare(
    asio
    GIT_REPOSITORY https://github.com/chriskohlhoff/asio.git
    GIT_TAG        master
)
FetchContent_GetProperties(asio)
if (NOT asio_POPULATED)
    FetchContent_Populate(asio)

    add_library(asio INTERFACE)
    target_include_directories(asio SYSTEM
        INTERFACE $<BUILD_INTERFACE:${asio_SOURCE_DIR}/asio/include>)
    target_compile_definitions(asio
        INTERFACE ASIO_STANDALONE ASIO_NO_DEPRECATED)
endif()

FetchContent_Declare(
    gsl
    GIT_REPOSITORY https://github.com/microsoft/GSL.git
    GIT_TAG        master
)
FetchContent_GetProperties(gsl)
if (NOT gsl_POPULATED)
    FetchContent_Populate(gsl)

    add_library(gsl INTERFACE)
    target_include_directories(gsl SYSTEM
        INTERFACE $<BUILD_INTERFACE:${gsl_SOURCE_DIR}/include>)
    target_compile_definitions(gsl
        INTERFACE GSL_NO_DEPRECATED)
endif()

FetchContent_Declare(
    argsparser
    GIT_REPOSITORY https://github.com/igormironchik/args-parser.git
    GIT_TAG        5.0.1.5
)
FetchContent_GetProperties(argsparser)
if (NOT argsparser_POPULATED)
    FetchContent_Populate(argsparser)

    add_library(argsparser INTERFACE)
    target_include_directories(argsparser SYSTEM
        INTERFACE $<BUILD_INTERFACE:${argsparser_SOURCE_DIR}>)
endif()