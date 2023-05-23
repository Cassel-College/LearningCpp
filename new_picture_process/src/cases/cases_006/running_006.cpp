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
	std::cout << "height:" << in_bmp.height << "; " << "width:" << in_bmp.width << std::endl;
	out_bmp.pBmpBuf = region.growwWithSeed(seed, in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte, speed);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "区域生长 完成" << endl;
}

//区域分裂
void Exec006::regionGrowingWithoutSeed(const char *read_bmp, const char *write_bmp)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	std::cout << "height:" << in_bmp.height << "; " << "width:" << in_bmp.width << std::endl;
	out_bmp.pBmpBuf = region.growWithoutSeed(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "区域分裂 完成" << endl;
}

void Exec006::Add(const char *read_bmp, const char *read_bmp1, const char *read_bmp2, const char *write_bmp)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	std::cout << "height:" << in_bmp.height << "; " << "width:" << in_bmp.width << std::endl;

	Bmp in_bmp1 = bmpOperation.readBmp(read_bmp1);
	Bmp in_bmp2 = bmpOperation.readBmp(read_bmp2);

	for (int i = 0; i < in_bmp.height; i++)
	{
		for (int j = 0; j < in_bmp.width; j++)
		{
			if (in_bmp2.pBmpBuf[i * in_bmp.lineByte + j] == 255) {
				out_bmp.pBmpBuf[i * in_bmp.lineByte + j] = 255;
			}
			if (in_bmp1.pBmpBuf[i * in_bmp.lineByte + j] == 255) {
				out_bmp.pBmpBuf[i * in_bmp.lineByte + j] = 0;
			}
		}
	}
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "合并操作完成" << endl;
}

void Exec006::run() {
    POINT seed;
	seed.x = 120;
    seed.y = 120;
	regionGrowingWithSeed(read_bmp_6_1, write_bmp_gs2, seed, 1);
	seed.x = 10;
    seed.y = 10;
	regionGrowingWithSeed(read_bmp_6_1, write_bmp_gs2, seed, 1);
	Add(read_bmp_6_1, write_bmp_gs1, write_bmp_gs2, write_bmp_gs);


    regionGrowingWithoutSeed(read_bmp_6_2, write_bmp_gws);
}



