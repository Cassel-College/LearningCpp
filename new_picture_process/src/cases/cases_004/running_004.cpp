#include "running_004.h"

Exec004::Exec004() {

}

Exec004::~Exec004() {

}

Bmp Exec004::init_colortable(Bmp bmp)
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

//镜像
void Exec004::mirroing(const char *read_bmp, const char *write_bmp, int flag)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = basic.bmpMirroring(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte, flag);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "图像镜像 完成" << endl;
}

//旋转
void Exec004::rotate(const char *read_bmp, const char *write_bmp, int angle)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = basic.bmpRotate(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte, angle);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "图像旋转 完成" << endl;
}

void Exec004::rotateII(const char *read_bmp, const char *write_bmp, const char *writeII_bmp, int angle)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	std::vector<int> infos;
	out_bmp.pBmpBuf = basic.bmpRotateII(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte, angle, infos);
	out_bmp.width = out_bmp.width * 2;
	out_bmp.height = out_bmp.height * 2;
	out_bmp.lineByte = (out_bmp.width * 8 / 8 + 3) / 4 * 4;
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "图像旋转I 完成" << endl;

	in_bmp = bmpOperation.readBmp(read_bmp);
	Bmp outr_bmp = in_bmp;
	outr_bmp.width = infos[0];
	outr_bmp.height = infos[1];
	outr_bmp.lineByte = (outr_bmp.width * 8 / 8 + 3) / 4 * 4;
	outr_bmp.pBmpBuf = basic.bmpCreate(out_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte, infos);
	bmpOperation.writeBmp(outr_bmp, writeII_bmp);
	cout << "图像旋转II 完成" << endl;
}

//平移
void Exec004::move(const char *read_bmp, const char *write_bmp, int x, int y)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = basic.bmpMove(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte, x, y);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "图像平移 完成" << endl;
}

//放缩
void Exec004::scale(const char *read_bmp, const char *write_bmp, float times1, float times2)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = basic.bmpScale(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte, times1, times2);
	out_bmp.width = out_bmp.width * times1;
	out_bmp.height = out_bmp.height * times2;
	out_bmp.lineByte = (out_bmp.width * 8 / 8 + 3) / 4 * 4;
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "图像放缩 完成" << endl;
}

//透视
void Exec004::perspective_transform(const char *read_bmp, const char *write_bmp)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = basic.bmpPerspect(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "图像透视 完成" << endl;
}

void Exec004::perspective_transform_for10(const char *read_bmp, const char *write_bmp)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = basic.bmpPerspect_10(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "图像透视 完成" << endl;
}

void Exec004::run() {
    scale(read_bmp_31, write_bmp_scale, 0.3f, 0.3f);
    
	move(read_bmp_31, write_bmp_move, 100, 100);
    
    mirroing(read_bmp_31, write_bmp_mirroring1, 1);
    
	mirroing(read_bmp_31, write_bmp_mirroring2, 0);
    
	rotate(read_bmp_31, write_bmp_rotate1, -60);

	rotateII(read_bmp_31, write_bmp_rotate2, write_bmp_rotateII, -60);

	perspective_transform(read_bmp_test4, read_bmp_test4_p);
}