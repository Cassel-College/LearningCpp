#pragma once

#include <iostream>
#include "stdlib.h"
#include "stdio.h"
#include <math.h>
#include "threshold.h"
// #include "spatialFilter.h"

class HistogramEqualize {
public:
	int grayPoint[256];
	float grayChance[256] = { 0 };

	void histogram(unsigned char * bmp, int width, int height, int linebyte);

	void chance_gery(unsigned char * bmp, int width, int height, int linebyte);

	unsigned char * saveHistogram(unsigned char * bmp, int width, int height, int linebyte);

	unsigned char * equalization(unsigned char * bmp, int width, int height, int linebyte);
};

