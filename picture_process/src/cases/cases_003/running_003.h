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


class Exec003 {

public:

    Exec003();

    ~Exec003();

    Bmp init_colortable(Bmp bmp);

    void averageWithoutBorder(const char *read_bmp, const char *write_bmp);

    void averageWithBorder(const char *read_bmp, const char *write_bmp);

    void medianWithoutBorder(const char *read_bmp, const char *write_bmp);

    void medianWithBorder(const char *read_bmp, const char *write_bmp);

    void run();

private:

    Bmp in_bmp, out_bmp;
    BmpOperation bmpOperation;
    SplitBmp splitBmp;
    HistogramEqualize histogram;
    spatialFiltering spatial;
    basicOperation basic;
    threshold thres;

    const char * read_bmp_1                     = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/source/image1.bmp";
    const char * read_bmp_2                     = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/source/image2.bmp";
    const char * read_bmp_31                    = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/source/image3_average.bmp";
    const char * read_bmp_31_per                = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/source/image3_perspective_transform.bmp";
    const char * read_bmp_32                    = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/source/image3_median.bmp";
    const char * read_bmp_test4                 = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/source/test4.bmp";
    const char * read_bmp_test4_p               = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/source/test4_perspective_transform.bmp";

    const char * write_bmp_red                  = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target03/imageR.bmp";
    const char * write_bmp_gray                 = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target03/imageGery.bmp";
    const char * write_bmp_gray_red             = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target03/imageGeryRed.bmp";
    const char * write_bmp_gray_blue            = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target03/imageGeryBlue.bmp";
    const char * write_bmp_gray_green           = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target03/imageGeryGreen.bmp";
    const char * write_bmp_green                = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target03/imageG.bmp";
    const char * write_bmp_blue                 = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target03/imageB.bmp";
    const char * write_bmp_alter                = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target03/imageGeryAlter.bmp";
    const char * write_bmp_equalize             = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target03/imageEqualize.bmp";
    const char * write_bmp_histogram            = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target03/imageHistogram.bmp";
    const char * write_bmp_histoEqualize        = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target03/imageHistoEqualize.bmp";
    const char * write_bmp_ab                   = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target03/imageAverageWithBorder.bmp";
    const char * write_bmp_aob                  = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target03/imageAverageWithoutBorder.bmp";
    const char * write_bmp_mb                   = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target03/imageMedianWithBorder.bmp";
    const char * write_bmp_mob                  = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target03/imageMedianWithoutBorder.bmp";
    const char * write_bmp_mirroring1           = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target03/imageMirroring1.bmp";
    const char * write_bmp_mirroring2           = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target03/imageMirroring2.bmp";
    const char * write_bmp_rotate1              = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target03/imageRotate1.bmp";
    const char * write_bmp_rotate2              = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target03/imageRotate2.bmp";
    const char * write_bmp_rotateII             = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target03/imageRotateII.bmp";
    const char * write_bmp_move                 = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target03/imageMove.bmp";
    const char * write_bmp_scale                = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target03/imageScale.bmp";
    const char * write_bmp_givenT               = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target03/imageGivenT.bmp";
    const char * write_bmp_iteration            = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target03/imageIteration.bmp";
    const char * write_bmp_otsu                 = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target03/imageOtsu.bmp";
    const char * write_bmp_histogram_givenT     = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target03/imagehistogram_givenT.bmp";
    const char * write_bmp_histogram_iter       = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target03/imagehistogram_Iteration.bmp";
    const char * write_bmp_histogram_otsu       = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target03/imagehistogram_Otsu.bmp";
};
