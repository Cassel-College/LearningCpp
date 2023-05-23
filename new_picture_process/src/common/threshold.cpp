#include "threshold.h"

unsigned char * threshold::givenT(int T, unsigned char * bmp, int width, int height, int linebyte)
{
	std::cout << "height:" << height << "; " << "width:" << width << std::endl;
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			int x = bmp[i*linebyte + j];
			if (x > T) {
				bmp[i*linebyte + j] = 255;
			} else {
				bmp[i*linebyte + j] = 0;
			}
		}
	}
	return bmp;
}

int threshold::iterationT(unsigned char * bmp, int width, int height, int linebyte)
{
	int T0;
	int	T1, T2, T = 128;
	do {
		T0 = T;
		T1 = iterateThreshold(bmp, width, height, linebyte, T, 1);
		T2 = iterateThreshold(bmp, width, height, linebyte, T, 0);
		T = (T1 + T2) / 2;
	} while (fabs(T0 - T) > 1);
	return T0;
}

int threshold::OtsuT(unsigned char * bmp, int width, int height, int linebyte)
{
	int T; 
	int c1, c2;
	float w, w0, a1, a2, u1, u2;
	w0 = 0;
	for ( k = 0; k < 256; k++) {
		c1 = 0, c2 = 0, a1 = 0, a2 = 0, u1 = 0, u2 = 0;
		for (i = 0; i < height; i++) {
			for (j = 0; j < width; j++) {
				int x = bmp[i*linebyte + j];
				if (x > k) {
					c1++;
					u1 += (int)x;
				} else {
					c2++;
					u2 += x;
				}
			}
		}
		a1 = (float)c1 / (c1 + c2);
		a2 = (float)c2 / (c1 + c2);
		u1 = u1 / a1;
		u2 = u2 / a2;
		w = a1 * a2*(u1 - u2)*(u1 - u2);
		if (w > w0) {
			T = k;
			w0 = w;
		}
	}
	return T;
}

int threshold::iterateThreshold(unsigned char * bmp, int width, int height, int linebyte, int T, int flag)
{
	int Tx = 0, Ty = 0, y1 = 0, y2 = 0;
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			int x = bmp[i*linebyte + j];
			if (x > T)
			{
				Tx += x;
				y1++;
			}
			else
			{
				Ty += x;
				y2++;
			}
		}
	}
	Tx = Tx / y1;
	Ty = Ty / y2;
	if (flag == 1)
	{
		return Tx;
	}
	else
	{
		return Ty;
	}

}
