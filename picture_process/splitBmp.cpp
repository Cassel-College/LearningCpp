#include "splitBmp.h"

//初始化三个分量的像素点
rgb SplitBmp::init_rgb(unsigned char * bmp, int height, int width, int linebyte)
{
	rgb total;
	unsigned char * image_blue = new unsigned char[height*linebyte * 3]{ 0 };
	unsigned char * image_green = new unsigned char[height*linebyte * 3]{ 0 };
	unsigned char * image_red = new unsigned char[height*linebyte * 3]{ 0 };
	// for (int i=0;i<height*linebyte * 3; i++) {
	// 	image_blue[i] = 255;
	// 	image_green[i] = 255;
	// 	image_red[i] = 255;
	// }
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{	
			// 0 0 0 是黑色
			int v = 0;

			// b
			if ((bmp[i*linebyte + j * 3 + 0] >= 235) && (bmp[i*linebyte + j * 3 + 1] >= 235) && (bmp[i*linebyte + j * 3 + 2] >= 235)){
				image_blue[i*linebyte + j * 3 + 0] = 255;
				image_blue[i*linebyte + j * 3 + 1] = 255;
				image_blue[i*linebyte + j * 3 + 2] = 255;
			}
			if (bmp[i*linebyte + j * 3 + 0] >= 235) {
				image_blue[i*linebyte + j * 3 + 0] = 255;
				image_blue[i*linebyte + j * 3 + 1] = 255;
				image_blue[i*linebyte + j * 3 + 2] = 255;
			}

			// g
			if ((bmp[i*linebyte + j * 3 + 0] >= 235) && (bmp[i*linebyte + j * 3 + 1] >= 235) && (bmp[i*linebyte + j * 3 + 2] >= 235)){
				image_green[i*linebyte + j * 3 + 0] = 255;
				image_green[i*linebyte + j * 3 + 1] = 255;
				image_green[i*linebyte + j * 3 + 2] = 255;
			}
			if (bmp[i*linebyte + j * 3 + 1] >= 235) {
				image_green[i*linebyte + j * 3 + 0] = 255;
				image_green[i*linebyte + j * 3 + 1] = 255;
				image_green[i*linebyte + j * 3 + 2] = 255; 
			}
			
			// r
			if ((bmp[i*linebyte + j * 3 + 0] >= 235) && (bmp[i*linebyte + j * 3 + 1] >= 235) && (bmp[i*linebyte + j * 3 + 2] >= 235)){
				image_red[i*linebyte + j * 3 + 0] = 255;
				image_red[i*linebyte + j * 3 + 1] = 255;
				image_red[i*linebyte + j * 3 + 2] = 255;
			}
			if (bmp[i*linebyte + j * 3 + 2] >= 230) {
				image_red[i*linebyte + j * 3 + 0] = 255;
				image_red[i*linebyte + j * 3 + 1] = 255;
				image_red[i*linebyte + j * 3 + 2] = 255;
			}

			// // image_green[i*linebyte + j * 3 + 0] = 255;
			// image_green[i*linebyte + j * 3 + 1] = bmp[i*linebyte + j * 3 + 1] - v;
			// // image_green[i*linebyte + j * 3 + 2] = 255;

			// image_red[i*linebyte + j * 3 + 0] = 255;
			// image_red[i*linebyte + j * 3 + 1] = 255;
			// image_red[i*linebyte + j * 3 + 2] = bmp[i*linebyte + j * 3 + 2] - v;
		}
	}
	total.blue = image_blue;
	total.red = image_red;
	total.green = image_green;

	return total;
}

//初始化灰度图的像素点
unsigned char * SplitBmp::init_gray(unsigned char * bmp, int height, int width, int linebyte, int lineByte2)
{
	// 灰度图只有亮度信息，无颜色信息，可用Y表示
	// lineByte2： 原图像宽度
	// 初始化输出的灰度图
	unsigned char * pBmpBuf = new unsigned char[height*linebyte]{ 0 };
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{	
			//取原来图像的像素X3, [BGR,BGR,BGR]
			int blue = bmp[i*lineByte2 + j * 3 + 0];
			int green = bmp[i*lineByte2 + j * 3 + 1];
			int red = bmp[i*lineByte2 + j * 3 + 2];
			// RGB彩色图像变换为灰度图理论中的参数
			pBmpBuf[i*linebyte + j] = 0.11*blue + 0.59*green + 0.3*red;
			pBmpBuf[i*linebyte + j] = 0.11*blue + 0.59*green + 0.3*red;
			pBmpBuf[i*linebyte + j] = 0.11*blue + 0.59*green + 0.3*red;
		}
	}
	return pBmpBuf;
}

//初始化灰度图的像素点
unsigned char * SplitBmp::init_gray_24_to_24(unsigned char * bmp, int height, int width, int linebyte, int lineByte2)
{
	// 灰度图只有亮度信息，无颜色信息，可用Y表示
	// lineByte2： 原图像宽度
	// 初始化输出的灰度图
	unsigned char * pBmpBuf = new unsigned char[height*linebyte * 3]{ 0 };
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{	
			//取原来图像的像素X3, [BGR,BGR,BGR]
			int blue = bmp[i*lineByte2 + j * 3 + 0];
			int green = bmp[i*lineByte2 + j * 3 + 1];
			int red = bmp[i*lineByte2 + j * 3 + 2];
			// RGB彩色图像变换为灰度图理论中的参数
			pBmpBuf[i*linebyte + j * 3 + 0] = 0.11*blue + 0.59*green + 0.3*red;
			pBmpBuf[i*linebyte + j * 3 + 1] = 0.11*blue + 0.59*green + 0.3*red;
			pBmpBuf[i*linebyte + j * 3 + 2] = 0.11*blue + 0.59*green + 0.3*red;
		}
	}
	return pBmpBuf;
}

//初始化反色灰度图的像素点
unsigned char * SplitBmp::init_opposite_gray(unsigned char * bmp, int height, int width, int linebyte)
{
	unsigned char * pBmpBuf = new unsigned char[height*linebyte];
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			int gray = bmp[i*linebyte + j];
			// 反色核心： 用 255 - 原值
			pBmpBuf[i*linebyte + j] = 255 - gray;
		}
	}
	return pBmpBuf;
}
