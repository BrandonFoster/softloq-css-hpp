cmake_minimum_required(VERSION 3.10...3.29)
project(softloq-css-project VERSION 1.0.0 LANGUAGES CXX)
option(BUILD_SHARED_LIBS "Generate Shared Library" OFF)
option(SOFTLOQ_CSS_BUILD_TESTING "Generate Unit-Testing" OFF)
option(SOFTLOQ_CSS_MONOLITHIC_BUILD "Builds everything in one Shared/Static Library" OFF)

# Build settings
set(CMAKE_CXX_EXTENSIONS OFF)
if(NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 23)
endif()
if(NOT CMAKE_CXX_STANDARD_REQUIRED)
    set(CMAKE_CXX_STANDARD_REQUIRED)
endif()
if(NOT CMAKE_RUNTIME_OUTPUT_DIRECTORY)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
endif()

# Catch2
include(CTest)
if(NOT TARGET Catch2)
    add_subdirectory(Catch2)
endif()

# Default values
set(MONOLITHIC_CXX_FILES "")
set(MONOLITHIC_PUBLIC_INCLUDES "")
set(MONOLITHIC_PRIVATE_INCLUDES "")
set(LIBRARY_TYPE STATIC)
set(PUBLIC_DEFINITIONS "")
set(PRIVATE_DEFINITIONS "")
set(LINK_LIBRARIES "")
set(DEPENDENCIES "")

# Library settings
if(BUILD_SHARED_LIBS)
    set(LIBRARY_TYPE SHARED)
    set(PUBLIC_DEFINITIONS SOFTLOQ_CSS_USE_API)
    set(PRIVATE_DEFINITIONS SOFTLOQ_CSS_BUILD_API)
endif()

if(SOFTLOQ_CSS_MONOLITHIC_BUILD)
    # Builds everything in one shared/static library
    file(GLOB_RECURSE MONOLITHIC_CXX_FILES softloq-unicode-hpp/src/**.cpp)
    set(MONOLITHIC_PUBLIC_INCLUDES softloq-unicode-hpp/include)
    if(BUILD_SHARED_LIBS)
        set(PUBLIC_DEFINITIONS SOFTLOQ_UNICODE_USE_API)
        set(PRIVATE_DEFINITIONS SOFTLOQ_UNICODE_BUILD_API)
    endif()
else()
    # Build dependencies as separate shared/static libraries
    if(NOT TARGET softloq::unicode)
        add_subdirectory(softloq-unicode-hpp)
    endif()
    set(DEPENDENCIES softloq::unicode)
    set(LINK_LIBRARIES softloq::unicode)
endif()

# Library build
file(GLOB_RECURSE CXX_FILES src/**.cpp)
add_library(softloq-css ${LIBRARY_TYPE} ${CXX_FILES} ${MONOLITHIC_CXX_FILES})
add_library(softloq::css ALIAS softloq-css)
target_include_directories(softloq-css PUBLIC include ${MONOLITHIC_PUBLIC_INCLUDES})
target_include_directories(softloq-css PRIVATE ${MONOLITHIC_PRIVATE_INCLUDES})
target_compile_definitions(softloq-css PUBLIC ${PUBLIC_DEFINITIONS})
target_compile_definitions(softloq-css PRIVATE ${PRIVATE_DEFINITIONS})
target_link_libraries(softloq-css ${LINK_LIBRARIES})

# Unit testing
if(BUILD_TESTING AND SOFTLOQ_CSS_BUILD_TESTING)
    add_executable(softloq-css-macros-test tests/css_macros_test.cpp)
    add_dependencies(softloq-css-macros-test softloq::css Catch2::Catch2WithMain)
    target_link_libraries(softloq-css-macros-test softloq::css Catch2::Catch2WithMain)

    add_executable(softloq-css-parser-test tests/css_parser_test.cpp)
    add_dependencies(softloq-css-parser-test softloq::css Catch2::Catch2WithMain)
    target_link_libraries(softloq-css-parser-test softloq::css Catch2::Catch2WithMain)

    add_executable(softloq-css-token-test tests/css_token_test.cpp)
    add_dependencies(softloq-css-token-test softloq::css Catch2::Catch2WithMain)
    target_link_libraries(softloq-css-token-test softloq::css Catch2::Catch2WithMain)

    add_executable(softloq-css-tokenizer-test tests/css_tokenizer_test.cpp)
    add_dependencies(softloq-css-tokenizer-test softloq::css Catch2::Catch2WithMain)
    target_link_libraries(softloq-css-tokenizer-test softloq::css Catch2::Catch2WithMain)
    include(Catch)
    catch_discover_tests(softloq-css-macros-test softloq-css-parser-test softloq-css-token-test softloq-css-tokenizer-test)
endif()