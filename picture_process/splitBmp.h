#pragma once

#include <iostream>
#include "stdlib.h"
#include "stdio.h"

using namespace std;

typedef struct rgb {
	unsigned char * red;
	unsigned char * green;
	unsigned char * blue;
};

class SplitBmp {
public:
	int i, j;

	rgb init_rgb_old(unsigned char * bmp, int height, int width, int linebyte);
	
	rgb init_rgb(unsigned char * bmp, int height, int width, int linebyte);

	unsigned char * get_bgr_of_b(unsigned char * bmp, int height, int width, int linebyte, int lineByte2);
	unsigned char * get_bgr_of_g(unsigned char * bmp, int height, int width, int linebyte, int lineByte2);
	unsigned char * get_bgr_of_r(unsigned char * bmp, int height, int width, int linebyte, int lineByte2);

	unsigned char * init_gray(unsigned char * bmp, int height, int width, int linebyte, int lineByte2);

	unsigned char * init_gray_24_to_24(unsigned char * bmp, int height, int width, int linebyte, int lineByte2);

	unsigned char * init_opposite_gray(unsigned char * bmp, int height, int width, int linebyte);
};

