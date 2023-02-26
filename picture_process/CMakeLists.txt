cmake_minimum_required(VERSION 3.18)
project(PictureProcess)

set(CMAKE_CXX_STANDARD 11)

add_executable(PictureProcess basicOperation.cpp basicOperation.h edgeDetection.cpp histogramEqualize.cpp HoughTransform.cpp outlineExtraction.cpp read_write_bmp.cpp regionGrowing.cpp spatialFilter.cpp splitBmp.cpp threshold.cpp pub.h main.cpp)
