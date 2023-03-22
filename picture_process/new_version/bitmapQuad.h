#pragma once
 
using BYTE = unsigned char;//1
using WORD  = unsigned short;//2
using DWORD = unsigned int;//4
using LONG  = unsigned long;//4
 
#pragma pack(push)
#pragma pack(2) //每次读取两个字节，以确保为结构体创建的内存刚刚好是我们想要的
struct BITMAPFILEHEADER {//定义bitmap文件头结构
	WORD  bfType;//记录文件标识符，BM
	DWORD bfSize;//记录文件的大小:文件头，信息头，颜色表，颜色数据
	WORD  bfReserved1;//保留字 0
	WORD  bfReserved2;//保留字 0
	DWORD bfOffBits;//颜色数据距文件头的偏移量
};
 
//定义位图信息头结构
struct BITMAPINFOHEADER {
	DWORD biSize;//本结构体的大小
	LONG  biWidth;//位图的宽：像素
	LONG  biHeight;//位图的高：像素
	WORD  biPlanes;//为平面数（一般为1）
	WORD  biBitCount;//每个像素所需的位数：1，4，8，16，24，32
	DWORD biCompression;//位图压缩类型（一般不压缩，取0）
	DWORD biSizeImage;//位图的大小
	LONG  biXPelsPerMeter;//水平分辨率 0代表取标准值
	LONG  biYPelsPerMeter;//垂直分辨率 0代表取标准值
	DWORD biClrUsed;//颜色数 标准取0 计算方法为2的biBitCount次方
	DWORD biClrImportant;//重要颜色数 标准取0
};
 
//颜色表
struct RGBQUAD {
	BYTE rgbBlue;//蓝
	BYTE rgbGreen;//绿
	BYTE rgbRED;//红
	BYTE rgbReserved;//保留字 0
};
#pragma pack(pop)