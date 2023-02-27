#include "HoughTransform.h"

#include <cstring>

unsigned char * HoughTransform::lineDetection(unsigned char * bmp, int width, int height, int linebyte, int number)
{
	unsigned char * pBmpBuf = new unsigned char[height*linebyte]{ 0 };
	for ( i = 0; i < height*linebyte; i++)
	{
		pBmpBuf[i] = 255;
	}

	const int MinTheta = 0;
	const int MaxTheta = 180;

	int w, h, x, y;
	int cosV, sinV;
	int **count, nmax;
	int *max;
	int theta, thro;
	//POINT start, end;

	double k, b;

	nmax = sqrt(width*width + height * height);
	count = new int *[MaxTheta];
	for ( i = 0; i < MaxTheta; i++)
	{
		count[i] = new int[nmax];
		memset(count[i], 0, sizeof(int) * nmax);
	}

	for ( theta = MinTheta; theta < MaxTheta; theta++)
	{
		cosV = (int)(cos(pi * theta / 180) * 2048);
		sinV = (int)(sin(pi * theta / 180) * 2048);
		for ( h = 0; h < height; h++)
		{
			for ( w = 0; w < width; w++)
			{
				if (bmp[h*linebyte + w] == 255)
				{
					thro = (w * cosV + h * sinV) >> 11;
					if (thro < nmax && thro > 0)
					{
						count[theta][thro]++;
					}
				}
			}
		}
	}
	max = new int[number];
	for ( i = 0; i < number; i++)
	{
		max[i] = count[0][0];
	}
	for ( num = 0; num < number; num++)
	{
		theta = 0;
		thro = 0;
		for (i = MinTheta; i < MaxTheta; i++)
		{
			for (j = 0; j < nmax; j++)
			{
				if (count[i][j] > max[num])
				{
					max[num] = count[i][j];
					theta = i;
					thro = j;
				}
			}
		}

		if (theta == 0)
		{
			k = 0;
			b = thro;
			for (i = 0; i < height; i++)
			{
				pBmpBuf[i*linebyte + thro] = 0;
			}
		}
		else
		{
			k = -1.0 / tan(pi * theta / 180);
			b = thro / sin(pi * theta / 180);
			for (i = 0; i < width; i++)
			{
				x = i;
				y = k * x + b;
				if (y > 0 && y < height)
				{
					pBmpBuf[y * linebyte + x] = 0;
				}
			}
		}
		count[theta][thro] = 0;
	}

	//cout << "k:" << k << ", b:" << b << endl;

	return pBmpBuf;
}
