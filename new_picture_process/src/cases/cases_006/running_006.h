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
#include "./../../../src/common/splitBmp.h"
#include "./../../../src/common/histogramEqualize.h"
#include "./../../../src/common/spatialFilter.h"
#include "./../../../src/common/basicOperation.h"
#include "./../../../src/common/threshold.h"
#include "./../../../src/common/regionGrowing.h"
#include "./../../../src/common/edgeDetection.h"
#include "./../../../src/common/HoughTransform.h"
#include "./../../../src/common/outlineExtraction.h"
#include "./../../../src/common/read_write_bmp.h"

class Exec006 {

public:

    Exec006();

    ~Exec006();

    Bmp init_colortable(Bmp bmp);

    void regionGrowingWithoutSeed(const char *read_bmp, const char *write_bmp);

    void Add(const char *read_bmp, const char *read_bmp1, const char *read_bmp2, const char *write_bm);

    void regionGrowingWithSeed(const char *read_bmp, const char *write_bmp, POINT seed, int speed);

    void run();

private:

    Bmp in_bmp, out_bmp;
    BmpOperation bmpOperation;
    SplitBmp splitBmp;
    basicOperation basic;
    edgeDetection edge;
    HistogramEqualize histogram;
    HoughTransform hough;
    outlineExtraction outline;
    regionGrowing region;
    spatialFiltering spatial;
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
    const char * read_bmp_6_1       = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/source/test6-1.bmp";
    const char * read_bmp_6_2       = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/source/test6-2.bmp";

    const char * write_bmp_red                  = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target01/imageR.bmp";
    const char * write_bmp_gray                 = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target01/imageGery.bmp";
    const char * write_bmp_green                = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target01/imageG.bmp";
    const char * write_bmp_blue                 = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target01/imageB.bmp";

    const char * write_bmp_gray_red             = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target06/imageGeryRed.bmp";
    const char * write_bmp_gray_blue            = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target06/imageGeryBlue.bmp";
    const char * write_bmp_gray_green           = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target06/imageGeryGreen.bmp";
    const char * write_bmp_alter                = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target06/imageGeryAlter.bmp";
    const char * write_bmp_equalize             = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target06/imageEqualize.bmp";
    const char * write_bmp_histogram            = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target06/imageHistogram.bmp";
    const char * write_bmp_histoEqualize        = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target06/imageHistoEqualize.bmp";
    const char * write_bmp_ab                   = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target06/imageAverageWithBorder.bmp";
    const char * write_bmp_aob                  = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target06/imageAverageWithoutBorder.bmp";
    const char * write_bmp_mb                   = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target06/imageMedianWithBorder.bmp";
    const char * write_bmp_mob                  = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target06/imageMedianWithoutBorder.bmp";
    const char * write_bmp_mirroring1           = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target06/imageMirroring1.bmp";
    const char * write_bmp_mirroring2           = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target06/imageMirroring2.bmp";
    const char * write_bmp_rotate1              = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target06/imageRotate1.bmp";
    const char * write_bmp_rotate2              = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target06/imageRotate2.bmp";
    const char * write_bmp_rotateII             = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target06/imageRotateII.bmp";
    const char * write_bmp_move                 = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target06/imageMove.bmp";
    const char * write_bmp_scale                = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target06/imageScale.bmp";
    const char * write_bmp_givenT               = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target06/imageGivenT.bmp";
    const char * write_bmp_iteration            = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target06/imageIteration.bmp";
    const char * write_bmp_otsu                 = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target06/imageOtsu.bmp";
    const char * write_bmp_histogram_givenT     = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target06/imagehistogram_givenT.bmp";
    const char * write_bmp_histogram_iter       = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target06/imagehistogram_Iteration.bmp";
    const char * write_bmp_histogram_otsu       = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target06/imagehistogram_Otsu.bmp";
    const char * new_write_bmp_histogram_givenT = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target06/new_imagehistogram_givenT.bmp";
    const char * new_write_bmp_histogram_iter   = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target06/new_imagehistogram_Iteration.bmp";
    const char * new_write_bmp_histogram_otsu   = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target06/new_imagehistogram_Otsu.bmp";
    const char * write_bmp_gs1                  = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target06/imageRegionGrowingWS1.bmp";
    const char * write_bmp_gs2                  = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target06/imageRegionGrowingWS2.bmp";
    const char * write_bmp_gs                   = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target06/imageRegionGrowingWS.bmp";
    const char * write_bmp_gws                  = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target06/imageRegionGrowingWOS.bmp";
    const char * write_bmp_prewitt              = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target06/imagePrewitt.bmp";
    const char * write_bmp_sobel                = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target06/imageSobel.bmp";
    const char * write_bmp_LOG                  = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target06/imageLOG.bmp";
    const char * write_bmp_hough                = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target06/imageLineDetection.bmp";
    const char * write_bmp_regionMark           = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target06/imageRegionMark.bmp";
    const char * write_bmp_outline              = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target06/imageOutlineExtraction.bmp";
};
