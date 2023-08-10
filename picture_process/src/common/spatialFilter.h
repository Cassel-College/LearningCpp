#pragma once

#include <iostream>
#include "stdlib.h"
#include "stdio.h"

class spatialFiltering
{
public:
	//存储返回的像素点
	unsigned char *pBmpBuf;
	//存储3*3的像素点的值
	int filter[9];
	//计数
	int count = 0;
	//计算出像素点的值
	int result;

	int i, j;

	unsigned char * average_with_border(unsigned char * bmp, int width, int height, int lineByte);
	unsigned char * average_without_border(unsigned char * bmp, int width, int height, int lineByte);
	unsigned char * median_with_border(unsigned char * bmp, int width, int height, int lineByte);
	unsigned char * median_without_border(unsigned char * bmp, int width, int height, int lineByte);
	int bubbleSort(int* m);
};