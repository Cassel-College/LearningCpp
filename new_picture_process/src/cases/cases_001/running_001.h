#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib> 
#include <map>
#include <cstring>
#include <algorithm>

#include "stdlib.h"
#include "stdio.h"

#include "./../../../src/common/pub.h"
#include "./../../../src/common/read_write_bmp.h"
#include "./../../../src/common/splitBmp.h"
#include "./../../../src/common/histogramEqualize.h"
#include "./../../../src/common/spatialFilter.h"
#include "./../../../src/common/basicOperation.h"
#include "./../../../src/common/threshold.h"
#include "./../../../src/tools/get_root_path.h"

class Exec001 {

public:

    Exec001();

    ~Exec001();

    Bmp init_colortable(Bmp bmp);

    void change24to8_to_b(const char *read_bmp, const char *write_bmp);

    void change24to8_to_g(const char *read_bmp, const char *write_bmp);

    void change24to8_to_r(const char *read_bmp, const char *write_bmp);

    void change24to24_gray(const char *read_bmp, const char *write_bmp);

    void change24to8(const char *read_bmp, const char *write_bmp);

    void reverse8(const char *read_bmp, const char *write_bmp);

    void run();

private:

    Bmp in_bmp, out_bmp;
    BmpOperation bmpOperation;
    SplitBmp splitBmp;
    HistogramEqualize histogram;
    spatialFiltering spatial;
    basicOperation basic;
    threshold thres;

    const char * read_bmp_1           = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/source/image1.bmp";
    const char * write_bmp_red        = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target01/imageR.bmp";
    const char * write_bmp_gray       = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target01/imageGery.bmp";
    const char * write_bmp_gray_red   = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target01/imageGeryRed.bmp";
    const char * write_bmp_gray_blue  = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target01/imageGeryBlue.bmp";
    const char * write_bmp_gray_green = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target01/imageGeryGreen.bmp";
    const char * write_bmp_green      = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target01/imageG.bmp";
    const char * write_bmp_blue       = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target01/imageB.bmp";
    const char * write_bmp_alter      = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target01/imageGeryAlter.bmp";

    // const char * read_bmp_1           = std::string(RootPath::getRootPath() + std::string("images/source/image1.bmp")).c_str();
    // const char * write_bmp_red        = std::string(RootPath::getRootPath() + std::string("images/target01/imageR.bmp")).c_str();
    // const char * write_bmp_gray       = std::string(RootPath::getRootPath() + std::string("images/target01/imageGery.bmp")).c_str();
    // const char * write_bmp_gray_red   = std::string(RootPath::getRootPath() + std::string("images/target01/imageGeryRed.bmp")).c_str();
    // const char * write_bmp_gray_blue  = std::string(RootPath::getRootPath() + std::string("images/target01/imageGeryBlue.bmp")).c_str();
    // const char * write_bmp_gray_green = std::string(RootPath::getRootPath() + std::string("images/target01/imageGeryGreen.bmp")).c_str();
    // const char * write_bmp_green      = std::string(RootPath::getRootPath() + std::string("images/target01/imageG.bmp")).c_str();
    // const char * write_bmp_blue       = std::string(RootPath::getRootPath() + std::string("images/target01/imageB.bmp")).c_str();
    // const char * write_bmp_alter      = std::string(RootPath::getRootPath() + std::string("images/target01/imageGeryAlter.bmp")).c_str();
};
