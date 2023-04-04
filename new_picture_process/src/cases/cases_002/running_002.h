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


class Exec002 {

public:

    Exec002();

    ~Exec002();

    Bmp init_colortable(Bmp bmp);

    void paintHistogram(const char *read_bmp, const char *write_bmp_histogram);

    void equalize(const char *read_bmp, const char *write_bmp_equalize, const char *write_bmp_histoequalize);

    void run();

private:

    Bmp in_bmp, out_bmp;
    BmpOperation bmpOperation;
    SplitBmp splitBmp;
    HistogramEqualize histogram;
    spatialFiltering spatial;
    basicOperation basic;
    threshold thres;

    // const char * read_bmp_1 = "./../images/source/image1.bmp";
    // const char * write_bmp_red = "./../images/target01/imageR.bmp";
    // const char * write_bmp_gray = "./..images/target01/imageGery.bmp";
    // const char * write_bmp_gray_red = "./../images/target01/imageGeryRed.bmp";
    // const char * write_bmp_gray_blue = "./../images/target01/imageGeryBlue.bmp";
    // const char * write_bmp_gray_green = "./../images/target01/imageGeryGreen.bmp";
    // const char * write_bmp_green = "./../images/target01/imageG.bmp";
    // const char * write_bmp_blue = "./../images/target01/imageB.bmp";
    // const char * write_bmp_alter = "./../images/target01/imageGeryAlter.bmp";

    const char * read_bmp_1 = "/home/Code/github/LearningCpp/picture_process/bitmaps/image1.bmp";
    const char * read_bmp_2 = "/home/Code/github/LearningCpp/picture_process/bitmaps/image2.bmp";
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
};
