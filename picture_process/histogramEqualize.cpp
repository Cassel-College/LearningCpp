#include "histogramEqualize.h"

//对灰度图像素点计数
void HistogramEqualize::histogram(unsigned char * bmp, int width, int height, int linebyte)
{
	int i, j;
	//数组初始化
	for (i = 0; i < 256; i++)
	{
		grayPoint[i] = 0;
	}
	//计数
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			int gray = bmp[i*linebyte + j];
			grayPoint[gray]++;
		}
	}

}

//计算每个灰度的概率与对应的累计概率
void HistogramEqualize::chance_gery(unsigned char * bmp, int width, int height, int linebyte)
{
	int flag = 0;
	unsigned char * pBmpBuf;
	histogram(bmp, width, height, linebyte);
	for (int i = 0; i < 256; i++)
	{
		grayChance[i] = 1.0f * grayPoint[i] / (height*width);
	}
	//累计概率
	for (int i = 1; i < 256; i++)
	{
		grayChance[i] = grayChance[i] + grayChance[i - 1];
	}

}

//存入直方图像素点
unsigned char * HistogramEqualize::saveHistogram(unsigned char * bmp, int width, int height, int linebyte)
{
	int i, j;
	unsigned char * pBmpBuf = new unsigned char[512 * 1000];
	int lineByte = (512 * 8 / 8 + 3) / 4 * 4;
	histogram(bmp, width, height, linebyte);
	//初始化
	for (i = 0; i < 512; i++)
	{
		for (j = 0; j < 1000; j++)
		{
			pBmpBuf[j*lineByte + i] = 0;

		}
	}

	for (i = 0; i < 512; i = i + 2)
	{
		for (j = 0; j < 1000; j++)
		{
			if (!grayPoint[i / 2]--)
			{
				break;
			}
			pBmpBuf[j*lineByte + i] = 255;
			pBmpBuf[j*lineByte + i + 1] = 255;

		}
	}

	return pBmpBuf;
}

//均衡化
unsigned char * HistogramEqualize::equalization(unsigned char * bmp, int width, int height, int linebyte)
{
	int i, j, k;
	chance_gery(bmp, width, height, linebyte);
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			int x = bmp[i*linebyte + j];
			for (k = 0; k < 256; k++)
			{
				if (x == k)
				{
					bmp[i*linebyte + j] = 255 * grayChance[k];
				}
			}
		}
	}
	return bmp;
}

