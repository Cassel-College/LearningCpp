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
    //  基于边界跟踪提取轮廓，内部使用栈。
    // extractOutline(read_bmp_9_1, write_bmp_outline1);
    // // 基于边界点的定义提取轮廓
    // regionMark(read_bmp_9_2, write_bmp_regionMark1);

    //  基于边界跟踪提取轮廓，内部使用栈。
    extractOutline(read_bmp_8_1, write_bmp_outline1);
    extractOutline(read_bmp_8_2, write_bmp_outline2);
    // 基于边界点的定义提取轮廓
    regionMark(read_bmp_8_1, write_bmp_regionMark1);
    regionMark(read_bmp_8_2, write_bmp_regionMark2);
}