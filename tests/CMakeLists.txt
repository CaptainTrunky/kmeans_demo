cmake_minimum_required (VERSION 3.10)

project (tests)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

find_package(Boost 1.63 COMPONENTS unit_test_framework REQUIRED)

if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
else()
  message("failed to find Boost")
  message("conider specifying BOOST_ROOT variable")
endif()

set ( CMAKE_CXX_FLAGS "-std=c++1z -Werror -Wall -Wextra -Wpedantic -Wcast-align \
    -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wenum-compare -Wfloat-equal \
    -Wnon-virtual-dtor -Wold-style-cast -Woverloaded-virtual -Wredundant-decls \
    -Wsign-conversion -Wsign-promo -Wno-unused-function"
)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include" "${CMAKE_CURRENT_SOURCE_DIR}/../include")

link_directories("${CMAKE_CURRENT_SOURCE_DIR}/../lib")

add_executable(tests main.cpp)

target_link_libraries(tests kmeans)

if(Boost_FOUND)
  target_link_libraries(tests ${Boost_LIBRARIES})
endif()
