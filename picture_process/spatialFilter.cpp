#include "spatialFilter.h"

unsigned char * spatialFiltering::average_without_border(unsigned char * bmp, int width, int height, int lineByte)
{
	pBmpBuf = new unsigned char[lineByte*height];
	for ( i = 0; i < height; i++)
	{
		for ( j = 0; j < width; j++)
		{
			if (i == 0 || j == 0 || i == height - 1 || j == width - 1)
			{
				pBmpBuf[i * lineByte + j] = bmp[i * lineByte + j];
			}
			else
			{
				int x = bmp[(i - 1) * lineByte + j - 1];
				filter[0] = x;
				x = bmp[(i - 1) * lineByte + j];
				filter[1] = x;
				x = bmp[(i - 1) * lineByte + j + 1];
				filter[2] = x;
				x = bmp[i * lineByte + j - 1];
				filter[3] = x;
				x = bmp[i * lineByte + j];
				filter[4] = x;
				x = bmp[i * lineByte + j + 1];
				filter[5] = x;
				x = bmp[(i + 1) * lineByte + j - 1];
				filter[6] = x;
				x = bmp[(i + 1) * lineByte + j];
				filter[7] = x;
				x = bmp[(i + 1) * lineByte + j + 1];
				filter[8] = x;

				result = (filter[0] + filter[1] + filter[2] + filter[3] + filter[4] + filter[5] + filter[6] + filter[7] + filter[8]) / 9;

				pBmpBuf[i * lineByte + j] = result;
			}
		}
	}
	return pBmpBuf;
}

unsigned char * spatialFiltering::median_without_border(unsigned char * bmp, int width, int height, int lineByte)
{
	pBmpBuf = new unsigned char[lineByte*height];
	for (i = 1; i < height - 1; i++)
	{
		for (j = 1; j < width - 1; j++)
		{
			int x = bmp[(i - 1) * lineByte + j - 1];
			filter[0] = x;
			x = bmp[(i - 1) * lineByte + j];
			filter[1] = x;
			x = bmp[(i - 1) * lineByte + j + 1];
			filter[2] = x;
			x = bmp[i * lineByte + j - 1];
			filter[3] = x;
			x = bmp[i * lineByte + j];
			filter[4] = x;
			x = bmp[i * lineByte + j + 1];
			filter[5] = x;
			x = bmp[(i + 1) * lineByte + j - 1];
			filter[6] = x;
			x = bmp[(i + 1) * lineByte + j];
			filter[7] = x;
			x = bmp[(i + 1) * lineByte + j + 1];
			filter[8] = x;

			result = bubbleSort(filter);

			pBmpBuf[i * lineByte + j] = result;
		}
	}
	return pBmpBuf;
}

int spatialFiltering::bubbleSort(int* m)
{
	int i, j, temp;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9 - i; j++)
		{
			if (m[j] > m[j + 1])
			{
				temp = m[j];
				m[j] = m[j + 1];
				m[j + 1] = temp;
			}
		}
	}
	return m[4];
}

{
	int lineByteT = ((width + 2) * 8 / 8 + 3) / 4 * 4;
	pBmpBuf = new unsigned char[lineByteT*(height + 2)];
	for (i = 0; i < height + 2; i++)
	{
		for (j = 0; j < width + 2; j++)
		{
			if (i != 0 && j != 0 && i != height + 1 && j != width + 1)
			{
				pBmpBuf[i*lineByteT + j] = bmp[(i - 1)*lineByte + j - 1];
			}
			else
			{
				pBmpBuf[i*lineByteT + j] = 128;
			}
		}
	}
	for (i = 0; i < height + 2; i++)
	{
		for (j = 0; j < width + 2; j++)
		{
			if (i == 0 || j == 0 || i == height + 1 || j == width + 1)
			{
				pBmpBuf[i * lineByteT + j] = 128;
			}
			else
			{
				int x = pBmpBuf[(i - 1) * lineByteT + j - 1];
				filter[0] = x;
				x = pBmpBuf[(i - 1) * lineByteT + j];
				filter[1] = x;
				x = pBmpBuf[(i - 1) * lineByteT + j + 1];
				filter[2] = x;
				x = pBmpBuf[i * lineByteT + j - 1];
				filter[3] = x;
				x = pBmpBuf[i * lineByteT + j];
				filter[4] = x;
				x = pBmpBuf[i * lineByteT + j + 1];
				filter[5] = x;
				x = pBmpBuf[(i + 1) * lineByteT + j - 1];
				filter[6] = x;
				x = pBmpBuf[(i + 1) * lineByteT + j];
				filter[7] = x;
				x = pBmpBuf[(i + 1) * lineByteT + j + 1];
				filter[8] = x;

				result = bubbleSort(filter);

				pBmpBuf[i * lineByteT + j] = result;
			}
		}
	}
	for (i = 1; i < height + 1; i++)
	{
		for (j = 1; j < width + 1; j++)
		{
			bmp[(i - 1)*lineByte + j - 1] = pBmpBuf[i*lineByteT + j];
		}
	}
	return bmp;
}