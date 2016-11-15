project(SorterWithStrategy)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++14")

cmake_minimum_required(VERSION 2.8)

set (SRC_LIST
    src/sorter.cpp
    src/sortstrategy.cpp
    src/mergesort.cpp
    src/selectionsort.cpp
    src/quicksort.cpp
    src/sortstrategyfactoryimpl.cpp
    src/comparestrategyfactory.cpp
    src/stdsort.cpp
    )

include_directories(
${CMAKE_SOURCE_DIR}/src/include
${CMAKE_SOURCE_DIR}/limo
)

add_library(sort ${SRC_LIST})

add_executable(${PROJECT_NAME} main.cpp)
add_executable(unit_tests unit_tests.cpp)

target_link_libraries(${PROJECT_NAME} sort)
target_link_libraries(unit_tests sort)

