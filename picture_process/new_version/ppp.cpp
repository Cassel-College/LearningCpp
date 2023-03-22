#pragma once
#include "bitmapQuad.h"
#include <iostream>
#include <fstream>
 
class bitmap {
private:
	FILE* m_rfp;//读入文件指针
	FILE* m_wfp;//写入文件指针
	FILE* m_wfp1;//写入文件指针
	FILE* m_wfp2;//写入文件指针
	BITMAPFILEHEADER* m_pbfHeader;//文件头指针
	BITMAPINFOHEADER* m_pbiHeader;//位图信息头指针
	RGBQUAD* m_prgbQuad;//颜色表指针
	BYTE* m_pImgData;//位图数据指针
	DWORD m_imgSize;//位图数据大小
 
private:
	inline void readFileHeader(BITMAPFILEHEADER* bmFileHeader);//读取文件头数据
	inline void readInfoHeader(BITMAPINFOHEADER* bmInfoHeader);//读取信息头数据
	inline void readRgbQuad(RGBQUAD* rgbQuad, const int& rgbQuadSize);//读取颜色表数据
	inline void readImgData(BYTE* pImgData, const DWORD& imgSize);//读取位图数据
 
private:
	inline void writeFileHeader(BITMAPFILEHEADER* pbfHeader);//读取文件头数据
	inline void writeInfoHeader(BITMAPINFOHEADER* pbiHeader);//读取信息头数据
	inline void writeRgbQuad(RGBQUAD* prgbQuad, const int& rgbQuadSize);//读取颜色表数据
	inline void writeImgData(BYTE* pImgData, const DWORD& imgSize);//读取位图数据
 
private:
	void createGrey_8();//创建8位灰度颜色表
 
public:
	bitmap(const char* readFilePath, const char* writeFilePath);
	bitmap(const char* readFilePath, const char* writeFilePath0, const char* writeFilePath1, const char* writeFilePath2);
	~bitmap();
	void rgb24_to_grey8();//24位图转为8位灰度图
	void grey8_to_antiGrey8();//8位图反色
	void rgb24_to_3grey8();//24位图分离为3个8位灰度图
 
};

#include "bitmap.h"
 
#pragma region bmp文件四部分的读入
/*读取文件头*/
inline
void bitmap::readFileHeader(BITMAPFILEHEADER* bmFileHeader) {
	fread(bmFileHeader, sizeof(BITMAPFILEHEADER), 1, m_rfp);
}
 
/*读取信息头*/
inline
void bitmap::readInfoHeader(BITMAPINFOHEADER* bmInfoHeader) {
	fread(bmInfoHeader, sizeof(BITMAPINFOHEADER), 1, m_rfp);
}
 
/*读取颜色表*/
inline
void bitmap::readRgbQuad(RGBQUAD* rgbQuad, const int& rgbQuadSize) {
	fread(rgbQuad, rgbQuadSize, 1, m_rfp);
}
 
/*读取位图数据*/
inline
void bitmap::readImgData(BYTE* pImgData, const DWORD& imgSize) {
	fread(pImgData, imgSize, 1, m_rfp);
}
#pragma endregion
 
 
#pragma region bmp文件四部分的写入
/*写入文件头*/
inline
void bitmap::writeFileHeader(BITMAPFILEHEADER* bmFileHeader) {
	fwrite(bmFileHeader, sizeof(BITMAPFILEHEADER), 1, m_wfp);
}
 
/*写入信息头*/
inline
void bitmap::writeInfoHeader(BITMAPINFOHEADER* bmInfoHeader) {
	fwrite(bmInfoHeader, sizeof(BITMAPINFOHEADER), 1, m_wfp);
}
 
/*写入颜色表*/
inline
void bitmap::writeRgbQuad(RGBQUAD* rgbQuad, const int& rgbQuadSize) {
	fwrite(rgbQuad, rgbQuadSize, 1, m_wfp);
}
 
/*写入位图数据*/
inline
void bitmap::writeImgData(BYTE* pImgData, const DWORD& imgSize) {
	fwrite(pImgData, imgSize, 1, m_wfp);
}
#pragma endregion
 
 
#pragma region 构造和析构函数
 
bitmap::bitmap(const char* readFilePath, const char* writeFilePath) {
	m_rfp = fopen(readFilePath, "rb");//只读二进制文件
	m_wfp = fopen(writeFilePath, "wb");//只写二进制文件
 
	m_pbfHeader = new BITMAPFILEHEADER;//为文件头分配存储空间
	readFileHeader(m_pbfHeader);//将图片的文件头读入
 
	if (m_pbfHeader->bfType == 0x4d42/*检查是否为bm图片*/) {
		m_pbiHeader = new BITMAPINFOHEADER;//为信息头分配内存空间
		readInfoHeader(m_pbiHeader);//将图片的信息头读入
 
		//24位
		if (m_pbiHeader->biBitCount == 24) {
			m_imgSize = m_pbiHeader->biSizeImage;//获取位图数据大小
			m_pImgData = new BYTE[m_imgSize];//为位图数据分配内存
			readImgData(m_pImgData, m_imgSize);//将图片数据读入
 
			fclose(m_rfp);//结束读入
		}
 
		//8位
		if (m_pbiHeader->biBitCount == 8) {
			m_prgbQuad = new RGBQUAD[256];//位颜色表分配内存空间
			readRgbQuad(m_prgbQuad, sizeof(RGBQUAD) * 256);//读取颜色表
 
			m_imgSize = m_pbiHeader->biSizeImage;//获取位图数据大小
			m_pImgData = new BYTE[m_imgSize];//为位图数据分配内存
			readImgData(m_pImgData, m_imgSize);//将图片数据读入
 
			fclose(m_rfp);//结束读入
		}
 
	}
	
}
 
bitmap::bitmap(const char* readFilePath, const char* writeFilePath0, const char* writeFilePath1, const char* writeFilePath2) {
	m_rfp = fopen(readFilePath, "rb");//只读二进制文件
	m_wfp = fopen(writeFilePath0, "wb");//只写二进制文件
	m_wfp1 = fopen(writeFilePath1, "wb");//只写二进制文件
	m_wfp2 = fopen(writeFilePath2, "wb");//只写二进制文件
 
	m_pbfHeader = new BITMAPFILEHEADER;//为文件头分配存储空间
	readFileHeader(m_pbfHeader);//将图片的文件头读入
 
	if (m_pbfHeader->bfType == 0x4d42/*检查是否为bm图片*/) {
		m_pbiHeader = new BITMAPINFOHEADER;//为信息头分配内存空间
		readInfoHeader(m_pbiHeader);//将图片的信息头读入
 
		//24位
		if (m_pbiHeader->biBitCount == 24) {
			m_imgSize = m_pbiHeader->biSizeImage;//获取位图数据大小
			m_pImgData = new BYTE[m_imgSize];//为位图数据分配内存
			readImgData(m_pImgData, m_imgSize);//将图片数据读入
 
			fclose(m_rfp);//结束读入
		}
	}
}
 
//析构函数
bitmap::~bitmap() {
	fclose(m_wfp);//结束写入
	if(m_pbfHeader != nullptr)
		delete m_pbfHeader;
	if (m_pbiHeader != nullptr)
		delete m_pbiHeader;
	if (m_prgbQuad != nullptr)
		delete m_prgbQuad;
	if (m_pImgData != nullptr)
		delete m_pImgData;
}
#pragma endregion
 
 
#pragma region 创建颜色表
//创建灰度8位颜色表
void bitmap::createGrey_8() {
	BYTE rgb = 0;
	BYTE rgbReserved = 0;
 
	m_prgbQuad = new RGBQUAD[256];//256色颜色分配内存
	for (int i = 0; i < 256; ++i) {
		m_prgbQuad[i].rgbBlue = rgb;
		m_prgbQuad[i].rgbGreen = rgb;
		m_prgbQuad[i].rgbRED = rgb;
		m_prgbQuad[i].rgbReserved = rgbReserved;
		++rgb;
	}
}
#pragma endregion
 
 
#pragma region 处理图片的方法
//将24位转为8位灰图
void bitmap::rgb24_to_grey8() {
	DWORD imgSize = m_pbiHeader->biHeight * (m_pbiHeader->biWidth / 4 + 1) * 4;//新图片的数据大小
	BYTE* imgData = new BYTE[imgSize]{};//为其分配内存
 
	//处理文件头
	m_pbfHeader->bfOffBits = 54 + 1024;//多加了一个颜色表256*4
	m_pbfHeader->bfSize = m_pbfHeader->bfOffBits + imgSize;//得出8位灰度时该分辨率的数据大小
	
	//处理信息头
	m_pbiHeader->biBitCount = 8;//每个像素现在8位
	m_pbiHeader->biSizeImage = imgSize;//更新数据大小
	m_pbiHeader->biClrUsed = 256;//将颜色表索引数改为256
	
	//创建颜色表
	createGrey_8();
	
	//将24位数据转换位8位数据
	int tmp;
	for (unsigned int i = 0; i < m_imgSize; i += 3) {
		tmp = (float)m_pImgData[i] * 0.114f + (float)m_pImgData[i + 1] * 0.587f + (float)m_pImgData[i + 2] * 0.299f;
		imgData[i / 3] = BYTE(tmp);
	}
 
	//写入数据
	writeFileHeader(m_pbfHeader);//写入文件头
	writeInfoHeader(m_pbiHeader);
	writeRgbQuad(m_prgbQuad, 256 * sizeof(RGBQUAD));
	writeImgData(imgData, imgSize);
}
 
//将8位灰度图反色
void bitmap::grey8_to_antiGrey8() {
	//数据区反色
	for (unsigned int i = 0; i < m_imgSize; ++i) {
		m_pImgData[i] = abs(m_pImgData[i] - 255);
	}
 
	//写入
	writeFileHeader(m_pbfHeader);
	writeInfoHeader(m_pbiHeader);
	writeRgbQuad(m_prgbQuad, sizeof(RGBQUAD) * 256);
	writeImgData(m_pImgData, m_imgSize);
}
 
//将24位分离成3个8位图
void bitmap::rgb24_to_3grey8() {
	DWORD imgSize = m_pbiHeader->biHeight * (m_pbiHeader->biWidth / 4 + 1) * 4;//新图片数据大小
	BYTE* imgData0 = new BYTE[imgSize]{};//为其1分配内存
	BYTE* imgData1 = new BYTE[imgSize]{};//为其2分配内存
	BYTE* imgData2 = new BYTE[imgSize]{};//为其3分配内存
 
	#pragma region 生成第一张图片
	//生成第一张图片
		//处理文件头
	m_pbfHeader->bfOffBits = 54 + 1024;//多加了一个颜色表256*4
	m_pbfHeader->bfSize = m_pbfHeader->bfOffBits + imgSize;//得出8位灰度时该分辨率的数据大小
 
		//处理信息头
	m_pbiHeader->biBitCount = 8;//每个像素现在8位
	m_pbiHeader->biSizeImage = imgSize;//更新数据大小
	m_pbiHeader->biClrUsed = 256;//将颜色表索引数改为256
 
		//处理颜色表
	createGrey_8();
 
	//分离数据
	for (unsigned int i = 0; i < m_imgSize; i += 3) {
		imgData0[i / 3] = m_pImgData[i];
	}
 
	//写入数据
	writeFileHeader(m_pbfHeader);//写入文件头
	writeInfoHeader(m_pbiHeader);
	writeRgbQuad(m_prgbQuad, 256 * sizeof(RGBQUAD));
	writeImgData(imgData0, imgSize);
 
	//关闭
	fclose(m_wfp);
	m_wfp = m_wfp1;
	#pragma endregion
 
	#pragma region 生成第二张图片
	//生成第二张图片
		//分离数据
	for (unsigned int i = 0; i < m_imgSize; i += 3) {
		imgData0[i / 3] = m_pImgData[i + 1];
	}
		//写入数据
	writeFileHeader(m_pbfHeader);
	writeInfoHeader(m_pbiHeader);
	writeRgbQuad(m_prgbQuad, 256 * sizeof(RGBQUAD));
	writeImgData(imgData0, imgSize);
 
		//关闭
	fclose(m_wfp);
	m_wfp = m_wfp2;
	#pragma endregion
 
	#pragma region 生成第三张图片
	//生成第三张图片
		//分离数据
	for (unsigned int i = 0; i < m_imgSize; i += 3) {
		imgData0[i / 3] = m_pImgData[i + 2];
	}
	//写入数据
	writeFileHeader(m_pbfHeader);
	writeInfoHeader(m_pbiHeader);
	writeRgbQuad(m_prgbQuad, 256 * sizeof(RGBQUAD));
	writeImgData(imgData0, imgSize);
	#pragma endregion
 
}
#pragma endregion
 