
include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(candidate_solution main.cpp network.cpp station.cpp)

target_link_libraries(candidate_solution ${PYTHON_LIBRARIES})





# include("${scratch_CMAKE_DIR}/matplotlib_cppTargets.cmake")

# get_target_property(scratch_INCLUDE_DIRS matplotlib_cpp::matplotlib_cpp INTERFACE_INCLUDE_DIRECTORIES)