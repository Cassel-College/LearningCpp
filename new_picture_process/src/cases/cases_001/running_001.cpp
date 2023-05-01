#include "running_001.h"

Exec001::Exec001() {
	std::cout << "开始读取图片 ..." << read_bmp_1 << std::endl;
}

Exec001::~Exec001() {
    
}

Bmp Exec001::init_colortable(Bmp bmp)
{
	int i;
    // 创建调色板
	bmp.pColorTable = (RGBQUAD*)malloc(256 * sizeof(RGBQUAD));
    // 置于0
	memset(bmp.pColorTable, 0, 256 * sizeof(RGBQUAD));
    // 填充调色板
	for (i = 0; i < 256; i++)
	{
		bmp.pColorTable[i].rgbBlue = i;
		bmp.pColorTable[i].rgbGreen = i;
		bmp.pColorTable[i].rgbRed = i;
		bmp.pColorTable[i].rgbReserved = 0;
	}
	return bmp;
}

//将24位图变成灰度图
void Exec001::change24to8(const char *read_bmp, const char *write_bmp)
{
    cout << "开始读取24位图 ..." << read_bmp << endl;
	
    // 读取图片
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;

	out_bmp.biBitCount = 8;

    // bmpWidth是位图的宽度，也就是每行有多少个像素块
    // 8：8位图像
    // 8：位数÷8即为每个像元占用字节数，bmpwidth*位数/8为有效字节数，在此基础上填充0
    // 3: 补齐 存储图像数据每行字节数为4的倍数，所以+3是怕出现不满足4的倍数这种情况
    // 4: BMP图片扫描引擎的最小单位是4字节，遵循4的整倍数
    // 目的： 用来计算8位图每行占多少个字节
	out_bmp.lineByte = (out_bmp.width * 8 / 8 + 3) / 4 * 4;

	out_bmp = init_colortable(out_bmp);

	out_bmp.pBmpBuf = splitBmp.init_gray(in_bmp.pBmpBuf, in_bmp.height, in_bmp.width, out_bmp.lineByte, in_bmp.lineByte);

	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "成功转为8位灰度图" << endl;
}


//将24位图变成灰度图
void Exec001::change24to8_to_b(const char *read_bmp, const char *write_bmp)
{
    cout << "开始读取24位图 ..." << endl;
    // 读取图片
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.biBitCount = 8;
	out_bmp.lineByte = (out_bmp.width * 8 / 8 + 3) / 4 * 4;
	out_bmp = init_colortable(out_bmp);
	out_bmp.pBmpBuf = splitBmp.get_bgr_of_b(in_bmp.pBmpBuf, in_bmp.height, in_bmp.width, out_bmp.lineByte, in_bmp.lineByte);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "成功转为8位灰度图-B" << endl;
}

void Exec001::change24to8_to_g(const char *read_bmp, const char *write_bmp)
{
    cout << "开始读取24位图 ..." << endl;
    // 读取图片
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.biBitCount = 8;
	out_bmp.lineByte = (out_bmp.width * 8 / 8 + 3) / 4 * 4;
	out_bmp = init_colortable(out_bmp);
	out_bmp.pBmpBuf = splitBmp.get_bgr_of_g(in_bmp.pBmpBuf, in_bmp.height, in_bmp.width, out_bmp.lineByte, in_bmp.lineByte);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "成功转为8位灰度图-G" << endl;
}

void Exec001::change24to8_to_r(const char *read_bmp, const char *write_bmp)
{
    cout << "开始读取24位图 ..." << endl;
    // 读取图片
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.biBitCount = 8;
	out_bmp.lineByte = (out_bmp.width * 8 / 8 + 3) / 4 * 4;
	out_bmp = init_colortable(out_bmp);
	out_bmp.pBmpBuf = splitBmp.get_bgr_of_r(in_bmp.pBmpBuf, in_bmp.height, in_bmp.width, out_bmp.lineByte, in_bmp.lineByte);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "成功转为8位灰度图-R" << endl;
}


void Exec001::change24to24_gray(const char *read_bmp, const char *write_bmp)
{
    cout << "开始读取24位图 ..." << endl;
    // 读取图片
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;

	out_bmp.biBitCount = 24;

    // // bmpWidth是位图的宽度，也就是每行有多少个像素块
    // // 8：8位图像
    // // 8：位数÷8即为每个像元占用字节数，bmpwidth*位数/8为有效字节数，在此基础上填充0
    // // 3: 补齐 存储图像数据每行字节数为4的倍数，所以+3是怕出现不满足4的倍数这种情况
    // // 4: BMP图片扫描引擎的最小单位是4字节，遵循4的整倍数
    // // 目的： 用来计算8位图每行占多少个字节
	// out_bmp.lineByte = (out_bmp.width * 8 / 8 + 3) / 4 * 4;

	out_bmp = init_colortable(out_bmp);

	out_bmp.pBmpBuf = splitBmp.init_gray_24_to_24(in_bmp.pBmpBuf, in_bmp.height, in_bmp.width, out_bmp.lineByte, in_bmp.lineByte);
    // 
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "成功转为24位灰度图" << endl;
}

//8位图反色
void Exec001::reverse8(const char *read_bmp, const char *write_bmp)
{
    cout << "开始读取8位图 ..." << endl;
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = splitBmp.init_opposite_gray(in_bmp.pBmpBuf, in_bmp.height, in_bmp.width, in_bmp.lineByte);
	out_bmp = init_colortable(out_bmp);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "成功反色8位灰度图" << endl;
}


void Exec001::run() {
    std::cout << "开始读取图片 ..." << read_bmp_1 << std::endl;
    change24to8(read_bmp_1, write_bmp_gray);
    reverse8(write_bmp_gray, write_bmp_alter);
    change24to8_to_b(read_bmp_1, write_bmp_gray_blue);
    change24to8_to_g(read_bmp_1, write_bmp_gray_green);
    change24to8_to_r(read_bmp_1, write_bmp_gray_red);

	change24to8_to_b(read_bmp_1, write_bmp_blue);
    change24to8_to_g(read_bmp_1, write_bmp_green);
    change24to8_to_r(read_bmp_1, write_bmp_red);
}