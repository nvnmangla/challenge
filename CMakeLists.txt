cmake_minimum_required(VERSION 3.4.1)
project (scratch)

# Add project cmake modules to path.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -g")


include(CMakeToolsHelpers OPTIONAL)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(app)
add_subdirectory(test)
add_subdirectory(vendor/googletest/googletest)