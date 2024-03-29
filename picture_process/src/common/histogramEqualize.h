#pragma once

#include <iostream>
#include "stdlib.h"
#include "stdio.h"
#include <math.h>

class HistogramEqualize {
public:
	int grayPoint[256];
	
	float grayChance[256] = { 0 };

	void histogram(unsigned char * bmp, int width, int height, int linebyte);

	void chance_gery(unsigned char * bmp, int width, int height, int linebyte);

	unsigned char * saveHistogram512(unsigned char * bmp, int width, int height, int linebyte);
	
	unsigned char * saveHistogram(unsigned char * bmp, int width, int height, int linebyte);

	unsigned char * equalization(unsigned char * bmp, int width, int height, int linebyte);

	unsigned char * saveHistogram512_2(unsigned char * bmp, int width, int height, int linebyte, int num);
	unsigned char * saveHistogram512_3(unsigned char * bmp, int width, int height, int linebyte, int num);

};

