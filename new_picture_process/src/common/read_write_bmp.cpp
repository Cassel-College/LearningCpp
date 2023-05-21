#include "read_write_bmp.h"
// readBmp()函数实现了BMP文件的读取操作
Bmp BmpOperation::readBmp(const char * bmpName) //文件名及路径
{
	FILE *fp = fopen(bmpName, "rb"); //二进制读方式打开指定的图象文件
	//if (fp == 0) return ;
	Bmp bmp;
	BITMAPFILEHEADER bitmapfileheader; //读取位图文件头结构BITMBPFILEHEBDER
	fread(&bitmapfileheader, sizeof(BITMAPFILEHEADER), 1, fp); 
	BITMAPINFOHEADER head; //定义位图信息头结构变量
	fread(&head, sizeof(BITMAPINFOHEADER), 1, fp); //读取位图信息头进内存，储存安放在变量head中
	//获取图象宽、高、每像素所占位数等信息
	bmp.biBitCount = head.biBitCount;
	bmp.width = head.biWidth;
	bmp.height = head.biHeight;
    bmp.lineByte = (bmp.width * bmp.biBitCount / 8 + 3) / 4 * 4; //定义变量，计算图象每行像素所占的字节数（必须是4的倍数）
	//灰度图象有颜色表，且颜色表表项为256
	if (bmp.biBitCount == 8)
	{
		//申请颜色表所需要的空间，读颜色表进内存
		bmp.pColorTable = new RGBQUAD[256]; 
		fread(bmp.pColorTable, sizeof(RGBQUAD), 256, fp);
	}
	//申请位图数值所需要的空间，读位图数值进内存
	bmp.pBmpBuf = new unsigned char[bmp.lineByte*bmp.height];
	fread(bmp.pBmpBuf, 1, bmp.lineByte*bmp.height, fp);
	//封闭文件
	fclose(fp);
    cout << "读取图像:" << bmpName << "成功！" << endl;
	return bmp;
}

void BmpOperation::writeBmp(Bmp bmp, const char * bmpName)
{
	if (!bmp.pBmpBuf)
		return;
	int colorTablesize = 0; //调色板大小，以字节为单位，灰度图象调色板为1024字节，彩色图象调色板大小为0
	if (bmp.biBitCount == 8)
		colorTablesize = 1024;
	bmp.lineByte = (bmp.width * bmp.biBitCount / 8 + 3) / 4 * 4; //待存储图象数值每行字节数为4的倍数
	FILE *fp = fopen(bmpName, "wb"); //以二进制写的方式打开文件
	if (fp == 0) return;
	BITMAPFILEHEADER fileHead; //申请位图文件头结构变量，填写文件头信息
	fileHead.bfType = 0x4D42; //bmp类型
	fileHead.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) //bfSize是图象文件4个构成部分之和
		+ colorTablesize + bmp.lineByte * bmp.height;
	fileHead.bfReserved1 = 0;
	fileHead.bfReserved2 = 0;
	fileHead.bfOffBits = 54 + colorTablesize; //bfOffBits是图象文件前3个部分所需空间之和
	fwrite(&fileHead, sizeof(BITMAPFILEHEADER), 1, fp); //写文件头进文件
	BITMAPINFOHEADER head; //申请位图信息头结构变量，填写信息头信息
	head.biBitCount = bmp.biBitCount;
	head.biClrImportant = 0;
	head.biClrUsed = 0;
	head.biCompression = 0;
	head.biHeight = bmp.height;
	head.biPlanes = 1;
	head.biSize = 40;
	head.biSizeImage = bmp.lineByte * bmp.height;
	head.biWidth = bmp.width;
	head.biXPelsPerMeter = 0;
	head.biYPelsPerMeter = 0;
	fwrite(&head, sizeof(BITMAPINFOHEADER), 1, fp); //写位图信息头进内存
	if (bmp.biBitCount == 8) //如果灰度图象，有调色板，写入文件
		fwrite(bmp.pColorTable, sizeof(RGBQUAD), 256, fp);  //写位图数值进文件
	fwrite(bmp.pBmpBuf, bmp.height*bmp.lineByte, 1, fp);
	fclose(fp); //封闭文件
	cout << "---- 保存图像:" << bmpName << ".成功！" << endl;
}
