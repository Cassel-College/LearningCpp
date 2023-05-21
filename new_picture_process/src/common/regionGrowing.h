#pragma once

#include <iostream>
#include "stdlib.h"
#include "stdio.h"
#include <math.h>
#include <vector>
#include <stack>
#include "pub.h"

using namespace std;

class regionGrowing
{
public:
	typedef struct SplitStruct {
		unsigned int w;
		unsigned int h;
		unsigned int x;
		unsigned int y;
	};//??????? ???????
	int i, j, k;
	int dir[8][2] = { {-1,-1},
                      {-1,0},
                      {-1,1},
                      {0,-1},
                      {0,1},
                      {1,-1},
                      {1,0},
                      {1,1} };
	int x;
	POINT origin;
	std::vector<POINT> pt;

	unsigned char * growwWithSeed(POINT ptGrowing, unsigned char * bmp, int width, int height, int linebyte, int speed);
	unsigned char * growWithoutSeed(unsigned char * bmp, int width, int height, int linebyte);
};