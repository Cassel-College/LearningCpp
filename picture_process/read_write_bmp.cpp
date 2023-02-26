#include "read_write_bmp.h"

Bmp BmpOperation::readBmp(const char * bmpName)
{
	FILE *fp = fopen(bmpName, "rb");
	//if (fp == 0) return ;
	Bmp bmp;
	BITMAPFILEHEADER bitmapfileheader;
	fread(&bitmapfileheader, sizeof(BITMAPFILEHEADER), 1, fp);
	BITMAPINFOHEADER head;
	fread(&head, sizeof(BITMAPINFOHEADER), 1, fp);
	bmp.biBitCount = head.biBitCount;
	bmp.width = head.biWidth;
	bmp.height = head.biHeight;
    // bmp.height = head.biSizeImage / head.biWidth / head.biBitCount;
    bmp.lineByte = (bmp.width * bmp.biBitCount / 8 + 3) / 4 * 4;

    // std::cout << "head.biSizeImage: " << head.biSizeImage << std::endl;
    // std::cout << "bmp.biBitCount: " << bmp.biBitCount << std::endl;
    // std::cout << "bmp.width: " << bmp.width << std::endl;
    // std::cout << "bmp.height: " << bmp.height << std::endl;
    // std::cout << "bmp.lineByte:" << bmp.lineByte << std::endl;
	if (bmp.biBitCount == 8)
	{
		bmp.pColorTable = new RGBQUAD[256];
		fread(bmp.pColorTable, sizeof(RGBQUAD), 256, fp);
	}
	bmp.pBmpBuf = new unsigned char[bmp.lineByte*bmp.height];
	fread(bmp.pBmpBuf, 1, bmp.lineByte*bmp.height, fp);
	fclose(fp);
    cout << "读取图像:" << bmpName << "成功！" << endl;
	return bmp;
}

void BmpOperation::writeBmp(Bmp bmp, const char * bmpName)
{
	if (!bmp.pBmpBuf)
		return;
	int colorTablesize = 0;
	if (bmp.biBitCount == 8)
		colorTablesize = 1024;
	bmp.lineByte = (bmp.width * bmp.biBitCount / 8 + 3) / 4 * 4;
	FILE *fp = fopen(bmpName, "wb");
	if (fp == 0) return;
	BITMAPFILEHEADER fileHead;
	fileHead.bfType = 0x4D42;//bmp����
	fileHead.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)
		+ colorTablesize + bmp.lineByte * bmp.height;
	fileHead.bfReserved1 = 0;
	fileHead.bfReserved2 = 0;
	fileHead.bfOffBits = 54 + colorTablesize;
	fwrite(&fileHead, sizeof(BITMAPFILEHEADER), 1, fp);
	BITMAPINFOHEADER head;
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
	fwrite(&head, sizeof(BITMAPINFOHEADER), 1, fp);
	if (bmp.biBitCount == 8)
		fwrite(bmp.pColorTable, sizeof(RGBQUAD), 256, fp);
	fwrite(bmp.pBmpBuf, bmp.height*bmp.lineByte, 1, fp);
	fclose(fp);
	cout << "---- 保存图像:" << bmpName << ".成功！" << endl;
}
