cmake_minimum_required(VERSION 3.10)
project(VM)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wc++17-extensions")

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-4.0)
pkg_check_modules(GLIBMM REQUIRED glibmm-2.4)

include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})
link_libraries(${GTKMM_LIBRARIES})

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(VM ${SOURCES})

# Create the target directory
set(TARGET_DIR "${CMAKE_CURRENT_SOURCE_DIR}/target")
file(MAKE_DIRECTORY ${TARGET_DIR})

# Set the output directory for the executable
set_target_properties(VM PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${TARGET_DIR})
