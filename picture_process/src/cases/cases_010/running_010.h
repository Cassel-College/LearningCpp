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

#include "./../../../src/cases/cases_001/running_001.h"
#include "./../../../src/cases/cases_002/running_002.h"
#include "./../../../src/cases/cases_003/running_003.h"
#include "./../../../src/cases/cases_004/running_004.h"
#include "./../../../src/cases/cases_005/running_005.h"
#include "./../../../src/cases/cases_006/running_006.h"
#include "./../../../src/cases/cases_007/running_007.h"
#include "./../../../src/cases/cases_008/running_008.h"
#include "./../../../src/cases/cases_009/running_009.h"



class Exec010 {

public:

    Exec010();

    ~Exec010();

    Bmp init_colortable(Bmp bmp);

    //Hough变换 需事先知道直线数量
    void Hough(const char *read_bmp, const char *write_bmp, int number);

    //区域标记与轮廓提取
    void regionMark(const char *read_bmp, const char *write_bmp);

    //轮廓提取
    void extractOutline(const char *read_bmp, const char *write_bmp);

    void change24to8(const char *read_bmp, const char *write_bmp);

    void split(const char *read_bmp, const char *write_bmp, int index);

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
    const char * write_bmp_gray     = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target01/imageGery.bmp";
    const char * read_bmp_6_1       = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/source/test6-1.bmp";
    const char * read_bmp_6_2       = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/source/test6-2.bmp";
    const char * read_bmp_7_1       = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/source/test7-1.bmp";
    const char * read_bmp_7_2       = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/source/test7-2.bmp";
    const char * read_bmp_8_1       = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/source/test8-1.bmp";
    const char * read_bmp_8_2       = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/source/test8-2.bmp";
    const char * read_bmp_9_1       = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/source/test9-1.bmp";
    const char * read_bmp_9_2       = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/source/test9-2.bmp";
    const char * read_bmp_10        = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/source/input1.bmp";

    const char * write_bmp_red                  = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target09/imageR.bmp";
    const char * write_bmp_gray_red             = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target09/imageGeryRed.bmp";
    const char * write_bmp_gray_blue            = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target09/imageGeryBlue.bmp";
    const char * write_bmp_gray_green           = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target09/imageGeryGreen.bmp";
    const char * write_bmp_green                = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target09/imageG.bmp";
    const char * write_bmp_blue                 = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target09/imageB.bmp";
    const char * write_bmp_alter                = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target09/imageGeryAlter.bmp";
    const char * write_bmp_equalize             = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target09/imageEqualize.bmp";
    const char * write_bmp_histogram            = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target09/imageHistogram.bmp";
    const char * write_bmp_histoEqualize        = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target09/imageHistoEqualize.bmp";
    const char * write_bmp_ab                   = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target09/imageAverageWithBorder.bmp";
    const char * write_bmp_aob                  = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target09/imageAverageWithoutBorder.bmp";
    const char * write_bmp_mb                   = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target09/imageMedianWithBorder.bmp";
    const char * write_bmp_mob                  = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target09/imageMedianWithoutBorder.bmp";
    const char * write_bmp_mirroring1           = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target09/imageMirroring1.bmp";
    const char * write_bmp_mirroring2           = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target09/imageMirroring2.bmp";
    const char * write_bmp_rotate1              = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target09/imageRotate1.bmp";
    const char * write_bmp_rotate2              = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target09/imageRotate2.bmp";
    const char * write_bmp_rotateII             = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target09/imageRotateII.bmp";
    const char * write_bmp_move                 = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target09/imageMove.bmp";
    const char * write_bmp_scale                = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target09/imageScale.bmp";
    const char * write_bmp_givenT               = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target09/imageGivenT.bmp";
    const char * write_bmp_iteration            = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target09/imageIteration.bmp";
    const char * write_bmp_otsu                 = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target09/imageOtsu.bmp";
    const char * write_bmp_histogram_givenT     = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target09/imagehistogram_givenT.bmp";
    const char * write_bmp_histogram_iter       = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target09/imagehistogram_Iteration.bmp";
    const char * write_bmp_histogram_otsu       = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target09/imagehistogram_Otsu.bmp";
    const char * new_write_bmp_histogram_givenT = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target09/new_imagehistogram_givenT.bmp";
    const char * new_write_bmp_histogram_iter   = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target09/new_imagehistogram_Iteration.bmp";
    const char * new_write_bmp_histogram_otsu   = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target09/new_imagehistogram_Otsu.bmp";
    const char * write_bmp_gs                   = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target09/imageRegionGrowingWS.bmp";
    const char * write_bmp_gws                  = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target09/imageRegionGrowingWOS.bmp";
    const char * write_bmp_prewitt              = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target09/imagePrewitt.bmp";
    const char * write_bmp_sobel                = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target09/imageSobel.bmp";
    const char * write_bmp_LOG                  = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target09/imageLOG.bmp";

    const char * write_bmp_prewitt_cp           = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target09/imagePrewitt_cp.bmp";
    const char * write_bmp_sobel_cp             = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target09/imageSobel_cp.bmp";
    const char * write_bmp_LOG_cp               = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target09/imageLOG_cp.bmp";

    const char * write_bmp_hough                = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target09/imageLineDetection.bmp";
    const char * write_bmp_regionMark           = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target09/imageRegionMark.bmp";
    const char * write_bmp_outline              = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target09/imageOutlineExtraction.bmp";

    const char * write_image_card                = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target10/image_card.bmp";

    const char * write_car_11                    = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target10/image11.bmp";
    const char * write_car_21                    = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target10/image21.bmp";
    const char * write_car_31                    = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target10/image31.bmp";
    const char * write_car_41                    = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target10/image41.bmp";
    const char * write_car_51                    = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target10/image51.bmp";
    const char * write_car_61                    = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target10/image61.bmp";

    const char * write_car_12                    = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target10/image12.bmp";
    const char * write_car_22                    = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target10/image22.bmp";
    const char * write_car_32                    = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target10/image32.bmp";
    const char * write_car_42                    = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target10/image42.bmp";
    const char * write_car_52                    = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target10/image52.bmp";
    const char * write_car_62                    = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target10/image62.bmp";
    
    const char * write_car_13                    = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target10/image13.bmp";
    const char * write_car_23                    = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target10/image23.bmp";
    const char * write_car_33                    = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target10/image33.bmp";
    const char * write_car_43                    = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target10/image43.bmp";
    const char * write_car_53                    = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target10/image53.bmp";
    const char * write_car_63                    = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target10/image63.bmp";
    const char * write_car_101                  = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target10/image101.bmp";
    const char * write_car_102                  = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target10/image102.bmp";
    const char * write_car_103                  = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target10/image103.bmp";

    const char * car_number_00                  = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target10/car_number/car_number_00.bmp";
    const char * car_number_01                  = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target10/car_number/car_number_01.bmp";
    const char * car_number_02                  = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target10/car_number/car_number_02.bmp";
    const char * car_number_03                  = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target10/car_number/car_number_03.bmp";
    const char * car_number_04                  = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target10/car_number/car_number_04.bmp";
    const char * car_number_05                  = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target10/car_number/car_number_05.bmp";
    const char * car_number_06                  = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target10/car_number/car_number_06.bmp";
    const char * car_number_07                  = "/Users/pengliu/Code/LearningCpp/new_picture_process/images/target10/car_number/car_number_07.bmp";
};
