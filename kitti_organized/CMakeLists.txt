cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

project(kitti_organized)

include_directories( include )
aux_source_directory( src DIR_SRCS)
set(TEST_MATH ${DIR_SRCS})


find_package(PCL 1.7 REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

list(REMOVE_ITEM PCL_LIBRARIES "vtkproj4")

add_executable(plane_extract ${TEST_MATH})
target_link_libraries(plane_extract ${PCL_LIBRARIES})
