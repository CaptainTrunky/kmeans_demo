cmake_minimum_required (VERSION 3.10)

project (kmeans)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

set ( CMAKE_CXX_FLAGS "-std=c++1z -Werror -Wall -Wextra -Wpedantic -Wcast-align \
    -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wenum-compare -Wfloat-equal \
    -Wnon-virtual-dtor -Wold-style-cast -Woverloaded-virtual -Wredundant-decls \
    -Wsign-conversion -Wsign-promo -Wno-unused-function"
)

find_package(Boost)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
else()
  message("failed to find Boost")
  message("conider specifying BOOST_ROOT variable")
endif()

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

add_subdirectory(tests)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

add_library(kmeans STATIC src/geometry.cpp src/kmeans.cpp)