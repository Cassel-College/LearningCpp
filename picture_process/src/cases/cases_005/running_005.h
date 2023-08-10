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

class Exec005 {

public:

    Exec005();

    ~Exec005();

    Bmp init_colortable(Bmp bmp);

    void thresholdByGivenT(const char *read_bmp, const char *write_bmp, const char *write_bmp_histogram, int T);

    void thresholdByIteration(const char *read_bmp, const char *write_bmp, const char *write_bmp_histogram);

    void thresholdByOtsu(const char *read_bmp, const char *write_bmp, const char *write_bmp_histogram);
    
    void paintHistogram2(const char *read_bmp, const char *write_bmp_histogram,const int num);

    void run();

private:

    Bmp in_bmp, out_bmp;
    BmpOperation bmpOperation;
    SplitBmp splitBmp;
    HistogramEqualize histogram;
    spatialFiltering spatial;
    basicOperation basic;
    threshold thres;

    const char * read_bmp_1         = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/source/image1.bmp";
    const char * read_bmp_2         = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/source/image2.bmp";
    const char * read_bmp_3         = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/source/image3_average.bmp";
    const char * read_bmp_4         = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/source/image4.bmp";
    const char * read_bmp_5         = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/source/image5.bmp";
    const char * read_bmp_31        = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/source/image3_average.bmp";
    const char * read_bmp_31_per    = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/source/image3_perspective_transform.bmp";
    const char * read_bmp_32        = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/source/image3_median.bmp";
    const char * read_bmp_test4     = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/source/test4.bmp";
    const char * read_bmp_test4_p   = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/source/test4_perspective_transform.bmp";

    const char * write_bmp_red                  = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target05/imageR.bmp";
    const char * write_bmp_gray                 = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target05/imageGery.bmp";
    const char * write_bmp_gray_red             = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target05/imageGeryRed.bmp";
    const char * write_bmp_gray_blue            = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target05/imageGeryBlue.bmp";
    const char * write_bmp_gray_green           = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target05/imageGeryGreen.bmp";
    const char * write_bmp_green                = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target05/imageG.bmp";
    const char * write_bmp_blue                 = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target05/imageB.bmp";
    const char * write_bmp_alter                = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target05/imageGeryAlter.bmp";
    const char * write_bmp_equalize             = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target05/imageEqualize.bmp";
    const char * write_bmp_histogram            = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target05/imageHistogram.bmp";
    const char * write_bmp_histoEqualize        = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target05/imageHistoEqualize.bmp";
    const char * write_bmp_ab                   = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target05/imageAverageWithBorder.bmp";
    const char * write_bmp_aob                  = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target05/imageAverageWithoutBorder.bmp";
    const char * write_bmp_mb                   = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target05/imageMedianWithBorder.bmp";
    const char * write_bmp_mob                  = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target05/imageMedianWithoutBorder.bmp";
    const char * write_bmp_mirroring1           = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target05/imageMirroring1.bmp";
    const char * write_bmp_mirroring2           = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target05/imageMirroring2.bmp";
    const char * write_bmp_rotate1              = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target05/imageRotate1.bmp";
    const char * write_bmp_rotate2              = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target05/imageRotate2.bmp";
    const char * write_bmp_rotateII             = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target05/imageRotateII.bmp";
    const char * write_bmp_move                 = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target05/imageMove.bmp";
    const char * write_bmp_scale                = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target05/imageScale.bmp";
    const char * write_bmp_givenT               = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target05/imageGivenT.bmp";
    const char * write_bmp_iteration            = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target05/imageIteration.bmp";
    const char * write_bmp_otsu                 = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target05/imageOtsu.bmp";
    const char * write_bmp_histogram_givenT     = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target05/imagehistogram_givenT.bmp";
    const char * write_bmp_histogram_iter       = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target05/imagehistogram_Iteration.bmp";
    const char * write_bmp_histogram_otsu       = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target05/imagehistogram_Otsu.bmp";
    const char * new_write_bmp_histogram_givenT = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target05/new_imagehistogram_givenT.bmp";
    const char * new_write_bmp_histogram_iter   = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target05/new_imagehistogram_Iteration.bmp";
    const char * new_write_bmp_histogram_otsu   = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target05/new_imagehistogram_Otsu.bmp";
    const char * write_bmp_gs                   = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target05/imageRegionGrowingWS.bmp";
    const char * write_bmp_gws                  = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target05/imageRegionGrowingWOS.bmp";
    const char * write_bmp_prewitt              = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target05/imagePrewitt.bmp";
    const char * write_bmp_sobel                = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target05/imageSobel.bmp";
    const char * write_bmp_LOG                  = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target05/imageLOG.bmp";
    const char * write_bmp_hough                = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target05/imageLineDetection.bmp";
    const char * write_bmp_regionMark           = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target05/imageRegionMark.bmp";
    const char * write_bmp_outline              = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target05/imageOutlineExtraction.bmp";
    
};
