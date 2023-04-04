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

class Exec008 {

public:

    Exec008();

    ~Exec008();

    Bmp init_colortable(Bmp bmp);

    void extractOutline(const char *read_bmp, const char *write_bmp);

    void regionMark(const char *read_bmp, const char *write_bmp);

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

    const char * read_bmp_1 = "/home/Code/github/LearningCpp/picture_process/bitmaps/image1.bmp";
    const char * read_bmp_2 = "/home/Code/github/LearningCpp/picture_process/bitmaps/image2.bmp";
    const char * read_bmp_3 = "/home/Code/github/LearningCpp/picture_process/bitmaps/image3_average.bmp";
    const char * read_bmp_4 = "/home/Code/github/LearningCpp/picture_process/bitmaps/image4.bmp";
    const char * read_bmp_5 = "/home/Code/github/LearningCpp/picture_process/bitmaps/image5.bmp";
    const char * read_bmp_31 = "/home/Code/github/LearningCpp/picture_process/bitmaps/image3_average.bmp";
    const char * read_bmp_31_per = "/home/Code/github/LearningCpp/picture_process/bitmaps/image3_perspective_transform.bmp";
    const char * read_bmp_32 = "/home/Code/github/LearningCpp/picture_process/bitmaps/image3_median.bmp";
    const char * write_bmp_red = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageR.bmp";
    const char * write_bmp_gray = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageGery.bmp";
    const char * write_bmp_gray_red = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageGeryRed.bmp";
    const char * write_bmp_gray_blue = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageGeryBlue.bmp";
    const char * write_bmp_gray_green = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageGeryGreen.bmp";
    const char * write_bmp_green = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageG.bmp";
    const char * write_bmp_blue = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageB.bmp";
    const char * write_bmp_alter = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageGeryAlter.bmp";
    const char * write_bmp_equalize = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageEqualize.bmp";
    const char * write_bmp_histogram= "/home/Code/github/LearningCpp/picture_process/bitmaps/imageHistogram.bmp";
    const char * write_bmp_histoEqualize = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageHistoEqualize.bmp";
    const char * write_bmp_ab = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageAverageWithBorder.bmp";
    const char * write_bmp_aob = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageAverageWithoutBorder.bmp";
    const char * write_bmp_mb = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageMedianWithBorder.bmp";
    const char * write_bmp_mob = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageMedianWithoutBorder.bmp";
    const char * write_bmp_mirroring1 = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageMirroring1.bmp";
    const char * write_bmp_mirroring2 = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageMirroring2.bmp";
    const char * write_bmp_rotate1 = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageRotate1.bmp";
    const char * write_bmp_rotate2 = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageRotate2.bmp";
    const char * write_bmp_rotateII = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageRotateII.bmp";
    const char * write_bmp_move = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageMove.bmp";
    const char * write_bmp_scale = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageScale.bmp";
    const char * write_bmp_givenT = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageGivenT.bmp";
    const char * write_bmp_iteration = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageIteration.bmp";
    const char * write_bmp_otsu = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageOtsu.bmp";
    const char * read_bmp_test4 = "/home/Code/github/LearningCpp/picture_process/bitmaps/test4.bmp";
    const char * read_bmp_test4_p = "/home/Code/github/LearningCpp/picture_process/bitmaps/test4_perspective_transform.bmp";
    const char * write_bmp_histogram_givenT = "/home/Code/github/LearningCpp/picture_process/bitmaps/imagehistogram_givenT.bmp";
    const char * write_bmp_histogram_iter = "/home/Code/github/LearningCpp/picture_process/bitmaps/imagehistogram_Iteration.bmp";
    const char * write_bmp_histogram_otsu = "/home/Code/github/LearningCpp/picture_process/bitmaps/imagehistogram_Otsu.bmp";
    const char * new_write_bmp_histogram_givenT = "/home/Code/github/LearningCpp/picture_process/bitmaps/new_imagehistogram_givenT.bmp";
    const char * new_write_bmp_histogram_iter   = "/home/Code/github/LearningCpp/picture_process/bitmaps/new_imagehistogram_Iteration.bmp";
    const char * new_write_bmp_histogram_otsu   = "/home/Code/github/LearningCpp/picture_process/bitmaps/new_imagehistogram_Otsu.bmp";

    const char * write_bmp_gs = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageRegionGrowingWS.bmp";
    const char * write_bmp_gws = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageRegionGrowingWOS.bmp";
    const char * write_bmp_prewitt = "/home/Code/github/LearningCpp/picture_process/bitmaps/imagePrewitt.bmp";
    const char * write_bmp_sobel = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageSobel.bmp";
    const char * write_bmp_LOG = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageLOG.bmp";
    const char * write_bmp_hough = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageLineDetection.bmp";
    const char * write_bmp_regionMark = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageRegionMark.bmp";
    const char * write_bmp_outline = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageOutlineExtraction.bmp";
};
