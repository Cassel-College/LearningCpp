cmake_minimum_required(VERSION 3.18)
project(PictureProcess)

set(CMAKE_CXX_STANDARD 11)

add_executable(PictureProcess 1/basicOperation.cpp 1/basicOperation.h 1/edgeDetection.cpp histogramEqualize.h histogramEqualize.cpp 1/HoughTransform.cpp 1/outlineExtraction.cpp 1/spatialFilter.cpp splitBmp.cpp 1/threshold.cpp pub.h read_write_bmp.cpp read_write_bmp.h main.cpp)
