cmake_minimum_required(VERSION 2.8)
project(EMC_group_4)

add_executable(example src/example.cpp)
target_link_libraries(example emc-framework)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
