#pragma once

#include <iostream>
#include "stdlib.h"
#include "stdio.h"
#include <math.h>
#define pi 3.14159265358979323846

using namespace std;

class HoughTransform {
public:
	int i, j, num;
	int bt;
	unsigned char * lineDetection(unsigned char * bmp, int width, int height, int linebyte, int number);
};