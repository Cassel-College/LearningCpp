#include "running_002.h"

Exec002::Exec002() {

}

Exec002::~Exec002() {
}

Bmp Exec002::init_colortable(Bmp bmp)
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

//绘制直方图
void Exec002::paintHistogram(const char *read_bmp, const char *write_bmp_histogram)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = histogram.saveHistogram512(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte);
	out_bmp = init_colortable(out_bmp);
	out_bmp.height = 512;
	out_bmp.width = 512;
	bmpOperation.writeBmp(out_bmp, write_bmp_histogram);
	cout << "生成直方图" << write_bmp_histogram << endl;
}

//直方图均衡化
void Exec002::equalize(const char *read_bmp, const char *write_bmp_equalize, const char *write_bmp_histoequalize)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = histogram.equalization(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte);
	out_bmp = init_colortable(out_bmp);
	bmpOperation.writeBmp(out_bmp, write_bmp_equalize);
	cout << "均衡化成功！" << endl;

	in_bmp = bmpOperation.readBmp(write_bmp_equalize);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = histogram.saveHistogram512(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte);
	out_bmp = init_colortable(out_bmp);
	out_bmp.height = 512;
	out_bmp.width = 512;
	bmpOperation.writeBmp(out_bmp, write_bmp_histoequalize);
	cout << "生成均衡化后的直方图" << endl;
}

void Exec002::run() {
    paintHistogram(read_bmp_2, write_bmp_histogram);
	equalize(read_bmp_2, write_bmp_equalize, write_bmp_histoEqualize);
}