#pragma once

#include <iostream>
#include "stdlib.h"
#include "stdio.h"
#include "pub.h"

using namespace std;

typedef struct Bmp {
	int width;
	int height;
	int lineByte;
	int biBitCount;
	RGBQUAD *pColorTable;
	unsigned char *pBmpBuf;
};

class BmpOperation {
public:
	Bmp readBmp(const char *bmpName);

	//writeBmp������bmp��linebyte��Ϊδ��ֵ
	void writeBmp(Bmp bmp, const char *bmpName);
};