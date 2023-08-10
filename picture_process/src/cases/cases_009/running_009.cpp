#include "running_009.h"

Exec009::Exec009() {}

Exec009::~Exec009() {}

Bmp Exec009::init_colortable(Bmp bmp)
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

//边缘检测Prewitt
void Exec009::prewitt(const char *read_bmp, const char *write_bmp)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = edge.Prewitt(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "边缘检测Prewitt 完成" << endl;
}

//边缘检测Sobel
void Exec009::Sobel(const char *read_bmp, const char *write_bmp)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = edge.Sobel(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "边缘检测Sobel 完成" << endl;
}

//LOG
void Exec009::LOG(const char *read_bmp, const char *write_bmp)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = edge.LOG(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte);
	bmpOperation.writeBmp(out_bmp, write_bmp); 
	cout << "边缘检测LOG 完成" << endl;
}

void Exec009::run() {
    prewitt(read_bmp_9_2, write_bmp_prewitt);
    Sobel(read_bmp_9_2, write_bmp_sobel);
    LOG(read_bmp_9_2, write_bmp_LOG);

    prewitt(read_bmp_9_1, write_bmp_prewitt_cp);
    Sobel(read_bmp_9_1, write_bmp_sobel_cp);
    LOG(read_bmp_9_1, write_bmp_LOG_cp);
}


