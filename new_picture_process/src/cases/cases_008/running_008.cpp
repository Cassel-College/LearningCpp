#include "running_008.h"

Exec008::Exec008() {}

Exec008::~Exec008() {}

Bmp Exec008::init_colortable(Bmp bmp)
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

//区域标记与轮廓提取
void Exec008::regionMark(const char *read_bmp, const char *write_bmp)
{
	int label;
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = outline.regionMark(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "区域标记 完成" << endl;
}

//轮廓提取
void Exec008::extractOutline(const char *read_bmp, const char *write_bmp)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = outline.extractOutline(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "轮廓提取 完成" << endl;
}

void Exec008::run() {
    regionMark(read_bmp_4, write_bmp_regionMark);
    extractOutline(read_bmp_4, write_bmp_outline);
}