#include "running_006.h"

Exec006::Exec006() {}

Exec006::~Exec006() {}

Bmp Exec006::init_colortable(Bmp bmp)
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

//区域生长
void Exec006::regionGrowingWithSeed(const char *read_bmp, const char *write_bmp, POINT seed, int speed)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = region.growwWithSeed(seed, in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte, speed);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "区域生长 完成" << endl;
}

//区域分裂
void Exec006::regionGrowingWithoutSeed(const char *read_bmp, const char *write_bmp)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = region.growWithoutSeed(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "区域分裂 完成" << endl;
}

void Exec006::run() {
    POINT seed;
    seed.x = 91;
    seed.y = 45;
    regionGrowingWithSeed(write_bmp_gray, write_bmp_gs, seed, 5);
    regionGrowingWithoutSeed(write_bmp_gray, write_bmp_gws);
}



