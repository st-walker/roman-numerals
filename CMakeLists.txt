cmake_minimum_required (VERSION 2.8)

project (roman_numerals-kata)

set(CMAKE_CXX_STANDARD          20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

# We have gtest/gmock as a Git submodule, add subdirectory to pick
# this up we we can use it as a dependency
add_subdirectory(lib/gtest)

# For the sake of form, and to give an idea of the sort of setup you'd
# find in a "real world" project, we're keeping the sources separate,
# and creating a separate archive
file (GLOB productionSources src/*.cpp)
add_library (roman_numerals STATIC ${productionSources})
target_include_directories (roman_numerals PRIVATE ${PROJECT_SOURCE_DIR}/include)

file (GLOB testSources test/*.cpp)
add_executable (roman_numeralstest ${testSources})
target_link_libraries (roman_numeralstest roman_numerals gmock gmock_main gtest pthread)
target_include_directories (roman_numeralstest PRIVATE ${gtest_SOURCE_DIR}/include)
target_include_directories (roman_numeralstest PRIVATE ${gmock_SOURCE_DIR}/include)
target_include_directories (roman_numeralstest PRIVATE ${PROJECT_SOURCE_DIR}/include)

# This enables the "make test" target, although for TDD it's likely
# you'll want to use the "make unit" target.
enable_testing ()

# Add the unit tests executable 
add_test (Unit roman_numeralstest)



# And a custom target as a convenience for running "make unit" as a
# specific target to support the TDD cycle
add_custom_target(unit
  COMMAND ${CMAKE_BINARY_DIR}/roman_numeralstest --gtest_color=true
  )
