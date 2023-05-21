#include "edgeDetection.h"

unsigned char * edgeDetection::Prewitt(unsigned char * bmp, int width, int height, int linebyte)
{
	threshold th;
	int T;
	pBmpBuf = new unsigned char[height*linebyte]{ 0 };
	gx = new unsigned char[height*linebyte]{ 0 };
	gy = new unsigned char[height*linebyte]{ 0 };
	for ( i = 1; i < width; i++)
	{
		for ( j = 1; j < height; j++)
		{
			gx[j*linebyte + i] = abs(bmp[(j + 1)*linebyte + i - 1] + bmp[(j + 1)*linebyte + i] + bmp[(j + 1)*linebyte + i + 1] - bmp[(j - 1)*linebyte + i - 1] - bmp[(j - 1)*linebyte + i] - bmp[(j - 1)*linebyte + i + 1]);
			gy[j*linebyte + i] = abs(bmp[(j - 1)*linebyte + i + 1] + bmp[j*linebyte + i + 1] + bmp[(j + 1)*linebyte + i + 1] - bmp[(j - 1)*linebyte + i - 1] - bmp[j*linebyte + i - 1] - bmp[(j + 1)*linebyte + i - 1]);

		}
	}
	for (i = 0; i < width; i++)
	{
		for (j = 0; j < height; j++)
		{
			pBmpBuf[j*linebyte + i] = 0.5*(gx[j*linebyte + i] + gy[j*linebyte + i]);
		}
	}
	T = th.OtsuT(pBmpBuf, width, height, linebyte);
	pBmpBuf = th.givenT(T, pBmpBuf, width, height, linebyte);
	RAdd(pBmpBuf, width, height, linebyte);
	return pBmpBuf;
}

unsigned char * edgeDetection::Sobel(unsigned char * bmp, int width, int height, int linebyte)
{
	threshold th;
	int T;
	pBmpBuf = new unsigned char[height*linebyte]{ 0 };
	gx = new unsigned char[height*linebyte]{ 0 };
	gy = new unsigned char[height*linebyte]{ 0 };
	for (i = 1; i < width; i++)
	{
		for (j = 1; j < height; j++)
		{
			gx[j*linebyte + i] = abs(bmp[(j + 1)*linebyte + i - 1] + 2*bmp[(j + 1)*linebyte + i] + bmp[(j + 1)*linebyte + i + 1] - bmp[(j - 1)*linebyte + i - 1] - 2*bmp[(j - 1)*linebyte + i] - bmp[(j - 1)*linebyte + i + 1]);
			gy[j*linebyte + i] = abs(bmp[(j - 1)*linebyte + i + 1] + 2*bmp[j*linebyte + i + 1] + bmp[(j + 1)*linebyte + i + 1] - bmp[(j - 1)*linebyte + i - 1] - 2*bmp[j*linebyte + i - 1] - bmp[(j + 1)*linebyte + i - 1]);

		}
	}
	for (i = 0; i < width; i++)
	{
		for (j = 0; j < height; j++)
		{
			pBmpBuf[j*linebyte + i] = 0.5*(gx[j*linebyte + i] + gy[j*linebyte + i]);
		}
	}
	T = th.OtsuT(pBmpBuf, width, height, linebyte);
	pBmpBuf = th.givenT(T, pBmpBuf, width, height, linebyte);
	RAdd(pBmpBuf, width, height, linebyte);
	return pBmpBuf;
}

unsigned char * edgeDetection::LOG(unsigned char * bmp, int width, int height, int linebyte)
{
	spatialFiltering sf;
	threshold th;
	int T;
	pBmpBuf = new unsigned char[height*linebyte]{ 0 };
	pBmpBuf = sf.average_with_border(pBmpBuf, width, height, linebyte);
	for (i = 1; i < width; i++)
	{
		for (j = 1; j < height; j++)
		{
			pBmpBuf[j*linebyte + i] = abs(bmp[(j - 1)*linebyte + i] + bmp[(j + 1)*linebyte + i] + bmp[j*linebyte + i + 1] + bmp[j*linebyte + i - 1] - 4*bmp[j*linebyte + i]);

		}
	}
	T = th.OtsuT(pBmpBuf, width, height, linebyte);
	pBmpBuf = th.givenT(T, pBmpBuf, width, height, linebyte);
	RAdd(pBmpBuf, width, height, linebyte);
	return pBmpBuf;
}


void edgeDetection::RAdd(unsigned char * in_bmp, int width, int height, int linebyte)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (in_bmp[i * linebyte + j] == 255) {
				in_bmp[i * linebyte + j] = 0;
				continue;
			}
			if (in_bmp[i * linebyte + j] == 0) {
				in_bmp[i * linebyte + j] = 255;
				continue;
			}
			
		}
	}
}