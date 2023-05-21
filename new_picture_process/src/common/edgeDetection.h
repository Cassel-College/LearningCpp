#pragma once

#include <iostream>
#include "stdlib.h"
#include "stdio.h"
#include <math.h>
#include "threshold.h"
#include "spatialFilter.h"

class edgeDetection {
public:
	int i, j;
	unsigned char * pBmpBuf, *gx, *gy;

	unsigned char * Prewitt(unsigned char * bmp, int width, int height, int linebyte);
	unsigned char * Sobel(unsigned char * bmp, int width, int height, int linebyte);
	void RAdd(unsigned char * in_bmp, int width, int height, int linebyte);
	unsigned char * LOG(unsigned char * bmp, int width, int height, int linebyte);
};