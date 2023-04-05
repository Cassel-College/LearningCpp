#include "running_010.h"


Exec010::Exec010() {}


Exec010::~Exec010() {}


//Hough变换 需事先知道直线数量
void Exec010::Hough(const char *read_bmp, const char *write_bmp, int number)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = hough.lineDetection(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte, number);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "Hough变换 完成" << endl;
}

//区域标记与轮廓提取
void Exec010::regionMark(const char *read_bmp, const char *write_bmp)
{
	int label;
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = outline.regionMark(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "区域标记 完成" << endl;
}

//轮廓提取
void Exec010::extractOutline(const char *read_bmp, const char *write_bmp)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = outline.extractOutline(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "轮廓提取 完成" << endl;
}

void Exec010::run() {
    std::cout << "No func" << std::endl;
}