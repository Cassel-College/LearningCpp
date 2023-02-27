// #include "splitBmp.h"

// //初始化三个分量的像素点
// rgb SplitBmp::init_rgb(unsigned char * bmp, int height, int width, int linebyte)
// {
// 	rgb total;
// 	unsigned char * image_blue = new unsigned char[height*linebyte * 3]{ 0 };
// 	unsigned char * image_green = new unsigned char[height*linebyte * 3]{ 0 };
// 	unsigned char * image_red = new unsigned char[height*linebyte * 3]{ 0 };
// 	for (i = 0; i < height; i++)
// 	{
// 		for (j = 0; j < width; j++)
// 		{
// 			image_blue[i*linebyte + j * 3 + 0] = bmp[i*linebyte + j * 3 + 0];
// 			image_green[i*linebyte + j * 3 + 1] = bmp[i*linebyte + j * 3 + 1];
// 			image_red[i*linebyte + j * 3 + 2] = bmp[i*linebyte + j * 3 + 2];
// 		}
// 	}
// 	total.blue = image_blue;
// 	total.red = image_red;
// 	total.green = image_green;

// 	return total;
// }

// //初始化灰度图的像素点
// unsigned char * SplitBmp::init_gray(unsigned char * bmp, int height, int width, int linebyte, int lineByte2)
// {
// 	unsigned char * pBmpBuf = new unsigned char[height*linebyte]{ 0 };
// 	for (i = 0; i < height; i++)
// 	{
// 		for (j = 0; j < width; j++)
// 		{
// 			int blue = bmp[i*lineByte2 + j * 3 + 0];
// 			int green = bmp[i*lineByte2 + j * 3 + 1];
// 			int red = bmp[i*lineByte2 + j * 3 + 2];
// 			pBmpBuf[i*linebyte + j] = 0.11*blue + 0.59*green + 0.3*red;
// 		}
// 	}
// 	return pBmpBuf;
// }

// //初始化反色灰度图的像素点
// unsigned char * SplitBmp::init_opposite_gray(unsigned char * bmp, int height, int width, int linebyte)
// {
// 	unsigned char * pBmpBuf = new unsigned char[height*linebyte];
// 	for (i = 0; i < height; i++)
// 	{
// 		for (j = 0; j < width; j++)
// 		{
// 			int gray = bmp[i*linebyte + j];
// 			pBmpBuf[i*linebyte + j] = 255 - gray;
// 		}
// 	}
// 	return pBmpBuf;
// }
