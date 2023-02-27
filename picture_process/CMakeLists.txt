cmake_minimum_required(VERSION 3.18)
project(PictureProcess)

set(CMAKE_CXX_STANDARD 11)

add_executable(PictureProcess 1/basicOperation.cpp 1/basicOperation.h 1/edgeDetection.cpp 1/histogramEqualize.cpp 1/HoughTransform.cpp 1/outlineExtraction.cpp 1/read_write_bmp.cpp 1/regionGrowing.cpp 1/spatialFilter.cpp splitBmp.cpp 1/threshold.cpp 1/pub.h main.cpp)
