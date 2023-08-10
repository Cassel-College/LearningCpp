#pragma once

#include <iostream>
#include "stdlib.h"
#include "stdio.h"
#include "pub.h"

using namespace std;
// 定义了几个全局变量，用来储存安放读入图象的位图数值、宽、高、颜色表及每像素位数等信息
typedef struct Bmp {
	int width; // 图象的宽
	int height; // 图象的高
	int lineByte;
	int biBitCount; // 图象类型，每像素位数
	RGBQUAD *pColorTable; // 颜色表指针
	unsigned char *pBmpBuf; // 读入图象数值的指针
};

class BmpOperation {
public:
	Bmp readBmp(const char *bmpName);

	void writeBmp(Bmp bmp, const char *bmpName);
};