#include "running_005.h"

Exec005::Exec005() {

}

Exec005::~Exec005() {
    
}

Bmp Exec005::init_colortable(Bmp bmp)
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
void Exec005::paintHistogram2(const char *read_bmp, const char *write_bmp_histogram,const int num)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = histogram.saveHistogram512_3(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte, num);
	out_bmp = init_colortable(out_bmp);
	out_bmp.height = 512;
	out_bmp.width = 512;
	bmpOperation.writeBmp(out_bmp, write_bmp_histogram);
	cout << "生成直方图" << write_bmp_histogram << endl;
}

//给定阈值分割
void Exec005::thresholdByGivenT(const char *read_bmp, const char *write_bmp, const char *write_bmp_histogram, int T)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = thres.givenT(T, in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "给定阈值分割 完成" << endl;
	// paintHistogram2(write_bmp, write_bmp_histogram, T);
	// paintHistogram2(read_bmp, write_bmp_histogram, T);
}

//迭代阈值分割
void Exec005::thresholdByIteration(const char *read_bmp, const char *write_bmp, const char *write_bmp_histogram)
{
	int T;
	in_bmp = bmpOperation.readBmp(read_bmp);
	T = thres.iterationT(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte);
	cout << "迭代出的阈值为：" << T << endl;
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp.pBmpBuf = thres.givenT(T, in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "迭代阈值分割 完成" << endl;
	// paintHistogram2(write_bmp, write_bmp_histogram, T);
	paintHistogram2(read_bmp, write_bmp_histogram, T);
}

//Otsu阈值分割
void Exec005::thresholdByOtsu(const char *read_bmp, const char *write_bmp, const char *write_bmp_histogram)
{
	int T;
	in_bmp = bmpOperation.readBmp(read_bmp);
	T = thres.OtsuT(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte);
	cout << "Otsu算法得出的阈值为：" << T << endl;

	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp.pBmpBuf = thres.givenT(T, in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "Otsu阈值分割 完成" << endl;
	// paintHistogram2(write_bmp, write_bmp_histogram, T);
	paintHistogram2(read_bmp, write_bmp_histogram, T);
}

void Exec005::run() {
    thresholdByGivenT(read_bmp_31, write_bmp_givenT, write_bmp_histogram_givenT, 128);
	thresholdByIteration(read_bmp_31, write_bmp_iteration, write_bmp_histogram_iter);
	thresholdByOtsu(read_bmp_31, write_bmp_otsu, write_bmp_histogram_otsu);
}