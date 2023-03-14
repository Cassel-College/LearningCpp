#pragma once

#include <iostream>
#include "stdlib.h"
#include "stdio.h"
#include <math.h>

using namespace std;

class threshold {

public:

	int i, j, k;
	int x;

	unsigned char * givenT(int T, unsigned char * bmp, int width, int height, int linebyte);
	int iterationT(unsigned char * bmp, int width, int height, int linebyte);
	int OtsuT(unsigned char * bmp, int width, int height, int linebyte);
	int iterateThreshold(unsigned char * bmp, int width, int height, int linebyte, int T, int flag);

};