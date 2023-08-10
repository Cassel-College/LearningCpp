#include "regionGrowing.h"

unsigned char * regionGrowing::growwWithSeed(POINT ptGrowing, unsigned char * bmp, int width, int height, int linebyte, int speed)
{
	unsigned char * pBmpBuf = new unsigned char[height*linebyte]{ 0 };
	int* tab = new int[height*linebyte]{ 0 };
	pt.push_back(ptGrowing);
	while (!pt.empty())
	{
		POINT currPt = pt.back();
		pt.pop_back();
		origin.x = currPt.x;
		origin.y = currPt.y;
		for ( i = 0; i < 8; i++)
		{
			ptGrowing.x = currPt.x + dir[i][0];
			ptGrowing.y = currPt.y + dir[i][1];
			if (ptGrowing.x < 0 || ptGrowing.y<0 || ptGrowing.x > width - 1 || ptGrowing.y>height - 1)
				continue;
			if (tab[ptGrowing.y * linebyte + ptGrowing.x] == 0)
			{
				
				if (bmp[ptGrowing.y * linebyte + ptGrowing.x] - bmp[origin.y * linebyte + origin.x] <= speed && bmp[ptGrowing.y * linebyte + ptGrowing.x] - bmp[origin.y * linebyte + origin.x] >= -speed)
				{
					pt.push_back(ptGrowing);
					tab[ptGrowing.y * linebyte + ptGrowing.x] = 1;
					pBmpBuf[ptGrowing.y * linebyte + ptGrowing.x] = 255;
				}
			}
		}
	}
	return pBmpBuf;
}




unsigned char * regionGrowing::growWithoutSeed(unsigned char * bmp, int width, int height, int linebyte)
{
	unsigned char * pBmpBuf = new unsigned char[height*linebyte]{ 0 };
	std::stack<SplitStruct> nMyStack;
	SplitStruct splitStruct, splitStructTemp;
	splitStruct.x = 0;
	splitStruct.y = 0;
	splitStruct.w = linebyte;
	splitStruct.h = height;
	nMyStack.push(splitStruct);
	int nValueS[2][2];// 用于存储块图像的平均灰度值
	int nAV;
	int nWidthTemp[3], nHeightTemp[3], nTemp;
	int nWidth, nHeigh;
	int n, m;
	double dOver;
	while (!nMyStack.empty())
	{
		splitStruct = nMyStack.top();
		nMyStack.pop();
		n = (splitStruct.y * linebyte + splitStruct.x);// 该块图像的左上角 是左上角！！！ 坐标原点在左上角！！！
		nWidthTemp[0] = 0;
		nWidthTemp[2] = (splitStruct.w + 1) / 2;
		nWidthTemp[1] = splitStruct.w - nWidthTemp[2];
		nHeightTemp[0] = 0;
		nHeightTemp[2] = (splitStruct.h + 1) / 2;
		nHeightTemp[1] = splitStruct.h - nHeightTemp[2];
		// 计算每一块图像的属性值
		int nValue;
		int nValueTemp;
		nAV = 0;
		for (i = 1; i < 3; ++i) {
			for (j = 1; j < 3; ++j) {
				nValue = 0;
				m = (n + linebyte * nHeightTemp[i - 1] + nWidthTemp[j - 1]);
				for (nHeigh = 0; nHeigh < nHeightTemp[i]; ++nHeigh) {
					for (nWidth = 0; nWidth < nWidthTemp[j]; ++nWidth) {
						if (k < linebyte * height) {
							k = (m + linebyte * nHeigh + nWidth);
							nValueTemp = (int)bmp[k];
							nValue += nValueTemp; // 灰度值之和
						}
					}
				}
				if (nHeightTemp[i] * nWidthTemp[j] == 0){
					continue;
				}
				if (nHeightTemp[i] * nWidthTemp[j] == 1){
					k = m;
					if (k < linebyte * height - 1) {
						if (bmp[k] < 128) {
							pBmpBuf[k] = 0;
							pBmpBuf[k + 1] = 0;
						} else {
							pBmpBuf[k] = 255;
							pBmpBuf[k + 1] = 255;
						}
					}
					continue;
				}
				nValueS[i - 1][j - 1] = nValue / (nHeightTemp[i] * nWidthTemp[j]);
				if (nValueS[i - 1][j - 1] < 200) {
					splitStructTemp.w = nWidthTemp[j];
					splitStructTemp.h = nHeightTemp[i];
					splitStructTemp.x = splitStruct.x + nWidthTemp[j - 1];
					splitStructTemp.y = splitStruct.y + nHeightTemp[i - 1];
					nMyStack.push(splitStructTemp);
				} else {
					for (nHeigh = 0; nHeigh < nHeightTemp[i]; ++nHeigh) {
						for (nWidth = 0; nWidth < nWidthTemp[j]; ++nWidth) {
							k = (m + linebyte * nHeigh + nWidth);
							if (k < linebyte * height - 1) {
								pBmpBuf[k] = 255;
								pBmpBuf[k + 1] = 255;
							}
						}
					}
				}
			}
		}
	}
	return pBmpBuf;
}


