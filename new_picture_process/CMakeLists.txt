cmake_minimum_required(VERSION 3.18)
project(PictureProcess)

set(CMAKE_CXX_STANDARD 11)

add_executable(PictureProcess src/common/HoughTransform.cpp src/common/HoughTransform.h src/common/basicOperation.cpp src/common/basicOperation.h src/common/edgeDetection.cpp src/common/edgeDetection.h src/common/histogramEqualize.cpp src/common/histogramEqualize.h src/common/outlineExtraction.cpp src/common/outlineExtraction.h src/common/perspective_transform.cpp src/common/perspective_transform.h src/common/pub.h src/common/read_write_bmp.cpp src/common/read_write_bmp.h src/common/regionGrowing.cpp src/common/regionGrowing.h src/common/spatialFilter.cpp src/common/spatialFilter.h src/common/splitBmp.cpp src/common/splitBmp.h src/common/threshold.cpp src/common/threshold.h src/cases/cases_001/running_001.h src/cases/cases_001/running_001.cpp src/cases/cases_002/running_002.h src/cases/cases_002/running_002.cpp src/cases/cases_003/running_003.h src/cases/cases_003/running_003.cpp src/cases/cases_004/running_004.h src/cases/cases_004/running_004.cpp src/cases/cases_005/running_005.h src/cases/cases_005/running_005.cpp main.cpp)
