project(SorterWithStrategy)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

cmake_minimum_required(VERSION 2.8)

set (SRC_LIST
    main.cpp
    src/sorting.cpp
    src/sorterstrategy.cpp
    src/mergesort.cpp
    src/selectionsort.cpp
    src/quicksort.cpp
    )


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/include)

add_executable(${PROJECT_NAME} ${SRC_LIST})

target_link_libraries(${PROJECT_NAME} ${LIBRARIES})

