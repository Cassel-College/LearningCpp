#pragma once

#include <iostream>
#include "stdlib.h"
#include "stdio.h"
#include <math.h>
#include <set>
#include <vector>
#include "../pub.h"

using namespace std;

class outlineExtraction {
public:
	POINT origin;
	int i, j;
	int dir[8][2] = { {-1,-1},
                      {-1,0},
                      {-1,1},
                      {0,-1},
                      {0,1},
                      {1,-1},
                      {1,0},
                      {1,1} };

	unsigned char * regionMark(unsigned char * bmp, int width, int height, int linebyte);
	unsigned char * extractOutline(unsigned char * bmp, int width, int height, int linebyte);
};