#include "running_007.h"

Exec007::Exec007() {}

Exec007::~Exec007() {}

Bmp Exec007::init_colortable(Bmp bmp)
{
	int i;
    // 创建调色板
	bmp.pColorTable = (RGBQUAD*)malloc(256 * sizeof(RGBQUAD));
    // 置于0
	memset(bmp.pColorTable, 0, 256 * sizeof(RGBQUAD));
    // 填充调色板
	for (i = 0; i < 256; i++)
	{
		bmp.pColorTable[i].rgbBlue = i;
		bmp.pColorTable[i].rgbGreen = i;
		bmp.pColorTable[i].rgbRed = i;
		bmp.pColorTable[i].rgbReserved = 0;
	}
	return bmp;
}

//Hough变换 需事先知道直线数量
void Exec007::Hough(const char *read_bmp, const char *write_bmp, int number)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = hough.lineDetection(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte, number);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "Hough变换 完成" << endl;
}

void Exec007::run() {
    Hough(read_bmp_3, write_bmp_hough, 5);
}