#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

typedef unsigned int DWORD;  // 4bytes
typedef unsigned short WORD;  // 2bytes
typedef signed long LONG;  // 4bytes
typedef unsigned char BYTE;  // 1bytes

#pragma pack(push)
#pragma pack(1)// 修改默认对齐值
/*位图文件文件头结构体*/
typedef struct tagBITMAPFILEHEADER {
	WORD bFileType;    //bmp图固定为0x4d42
	DWORD bFileSize;  //整个bmp文件大小，包括两个头、一个颜色表和颜色数据的总大小
	WORD bReserved1;  //保留字，不考虑，设为0即可
	WORD bReserved2;  //保留字，同上
	DWORD bPixelDataOffset;  //实际位图数据的偏移字节数，即前三个部分长度之和
}BITMAPFILEHEADER; //14bytes
#pragma pack(pop)

/*位图文件信息头结构体*/
typedef struct tagBITMAPINFOHEADER {
	DWORD bHeaderSize;  // 图像信息头总大小（40bytes）
	LONG bImageWidth;  // 图像宽度（像素）
	LONG bImageHeight;  // 图像高度
	WORD bPlanes;  // 应该是0
	WORD bBitsPerPixel;   //采用颜色位数，可以是1，2，4，8，16，24，32，这里是8
	DWORD bCompression;  // 图像压缩方法
	DWORD bImageSize;  // 图像大小（字节）
	LONG bXpixelsPerMeter;  // 横向每米像素数  X方向分辨率  1 in = 0.0254 m
	LONG bYpixelsPerMeter;  // 纵向每米像素数
	DWORD bTotalColors;  // 使用的颜色总数，如果像素位数大于8，则该字段没有意义
	DWORD bImportantColors;  // 重要颜色数，
}BITMAPINFOHEADER; //40bytes

/*位图文件调色板结构体*/
typedef struct tagRGBQUAD {
	BYTE	rgbBlue;
	BYTE	rgbGreen;
	BYTE	rgbRed;
	BYTE	rgbReserved;
}RGBQUAD;

/*像素点RGB结构体*/
typedef struct tagRGB {
	BYTE blue;
	BYTE green;
	BYTE red;
}RGBDATA;

int main() {
	//打开bmp文件，追加读
	FILE* fp = fopen("/home/Code/github/LearningCpp/picture_process/new_version/1280_1024.bmp", "rb");
	
	//读取头结构14字节
	BITMAPFILEHEADER* fileHead = (BITMAPFILEHEADER*)malloc(sizeof(BITMAPFILEHEADER));
	fread(fileHead, sizeof(BITMAPFILEHEADER), 1, fp);
	//读取头信息40字节
	BITMAPINFOHEADER* infoHead = (BITMAPINFOHEADER*)malloc(sizeof(BITMAPINFOHEADER));
	fread(infoHead, sizeof(BITMAPINFOHEADER), 1, fp);

	//打印头信息
	printf("信息头大小：%d字节\n", infoHead->bHeaderSize);
	printf("图片宽度：%d像素\n", infoHead->bImageWidth);
	printf("图片高度：%d像素\n", infoHead->bImageHeight);
	printf("颜色位数：%d位\n", infoHead->bBitsPerPixel);

	//开辟空间读取调色板1024字节
	RGBQUAD* rgbQuad = (RGBQUAD*)malloc(sizeof(RGBQUAD) * 256);
	fread(rgbQuad, 1024, 1, fp);
	
	//获取图像宽和高
	int width = infoHead->bImageWidth;
	int height = infoHead->bImageHeight;
	//堆上开辟二维数组空间
	BYTE** data = (BYTE**)malloc(sizeof(BYTE*) * height);
	for (int i = 0; i < height; i++)
	{
		data[i] = (BYTE*)malloc(sizeof(BYTE) * width);
	}
	//读取像素信息存入二维数组
	for (int i = height - 1; i >= 0; i--)
	{
		for (int j = 0; j < width; j++)
		{
			fread(&data[i][j], sizeof(BYTE), 1, fp);
		}
	}
	//选取几个点测试一下是否正确,注意x和y的先后顺序
	printf("%d\n", data[10][5]);

	//释放资源
	free(rgbQuad);
	rgbQuad = NULL;
	for (int i = 0; i < height; i++)
	{
		free(data[i]);
	}
	free(data);
	data = NULL;

	fclose(fp);
	free(fp);
	free(fileHead);
	free(infoHead);
	fileHead = NULL;
	infoHead = NULL;

	system("/home/Code/github/LearningCpp/picture_process/new_version/1280_1024.bmp");
	getchar();
	return 0;
}
