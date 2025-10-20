cmake_minimum_required(VERSION 4.0)

project(cpp_demos 
    VERSION 1.0.0
    DESCRIPTION "C++ Demos"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR}/build)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB_RECURSE TST_FILES ${PROJECT_SOURCE_DIR}/tests/*.cc)

add_executable(src_binary ${SRC_FILES})
target_compile_options(src_binary PRIVATE 
  -Wall      # Basic warnings
  -Wextra    # Extra warnings
  -Werror
  -Wpedantic # Strict ISO C++
  -O0
  -g
)


# gtest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(test_binary ${TST_FILES} ${SRC_FILES})
target_link_libraries(test_binary PRIVATE 
  GTest::gtest_main
  GTest::gtest 
  GTest::gmock 
)