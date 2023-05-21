#include "running_010.h"


Exec010::Exec010() {}


Exec010::~Exec010() {}


Bmp Exec010::init_colortable(Bmp bmp)
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


//Hough变换 需事先知道直线数量
void Exec010::Hough(const char *read_bmp, const char *write_bmp, int number)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = hough.lineDetectionII(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte, number);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "Hough变换 完成" << endl;
}

//区域标记与轮廓提取
void Exec010::regionMark(const char *read_bmp, const char *write_bmp)
{
	int label;
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = outline.regionMark(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "区域标记 完成" << endl;
}

//轮廓提取
void Exec010::extractOutline(const char *read_bmp, const char *write_bmp)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = outline.extractOutline(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "轮廓提取 完成" << endl;
}

void Exec010::change24to8(const char *read_bmp, const char *write_bmp)
{
    cout << "开始读取24位图 ...:" << read_bmp << endl;
    // 读取图片
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.biBitCount = 8;
	out_bmp.lineByte = (out_bmp.width * 8 / 8 + 3) / 4 * 4;
	out_bmp = init_colortable(out_bmp);
	out_bmp.pBmpBuf = splitBmp.init_gray(in_bmp.pBmpBuf, in_bmp.height, in_bmp.width, out_bmp.lineByte, in_bmp.lineByte);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "成功转为8位灰度图" << endl;
}

void Exec010::split(const char *read_bmp, const char *write_bmp, int index)
{
    cout << "开始读取" << index << "位车牌号码 ...:" << read_bmp << endl;
    // 读取图片
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.biBitCount = 8;
	// out_bmp.lineByte = (out_bmp.width * 8 / 8 + 3) / 4 * 4;
	// out_bmp.lineByte = in_bmp.width;
	out_bmp = init_colortable(out_bmp);
	out_bmp.pBmpBuf = splitBmp.split_car_number(in_bmp.pBmpBuf, in_bmp.height, in_bmp.width, in_bmp.lineByte, index);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "成功读取" << index << "位车牌号码" << endl;
}

void Exec010::run() {
    std::cout << "No func" << std::endl;
    
	


	
	std::shared_ptr<Exec001> execution_001 = std::make_shared<Exec001>();
	std::shared_ptr<Exec003> execution_003 = std::make_shared<Exec003>();
	std::shared_ptr<Exec004> execution_004 = std::make_shared<Exec004>();
	std::shared_ptr<Exec005> execution_005 = std::make_shared<Exec005>();
	std::shared_ptr<Exec007> execution_007 = std::make_shared<Exec007>();
	std::shared_ptr<Exec008> execution_008 = std::make_shared<Exec008>();

	execution_001->change24to8(read_bmp_10, write_car_11);
	// execution_001->change24to8_to_b(read_bmp_10, write_car_101);
	execution_004->rotate(write_car_11, write_car_21, -15);
	execution_004->perspective_transform_for10(write_car_21, write_image_card);
	execution_005->thresholdByGivenT(write_image_card, write_car_33, write_car_43, 128);
	execution_004->move(write_car_33, write_car_43, 329, 0);
	execution_004->move(write_car_43, write_car_42, -355, 0);
	execution_004->move(write_car_42, write_car_41, 0, 30);
	execution_004->move(write_car_41, write_car_52, 0, -55);
	split(write_car_52, car_number_00, 0);
	split(write_car_52, car_number_01, 1);
	split(write_car_52, car_number_02, 2);
	split(write_car_52, car_number_03, 3);
	split(write_car_52, car_number_04, 4);
	split(write_car_52, car_number_05, 5);
	split(write_car_52, car_number_06, 6);
	split(write_car_52, car_number_07, 7);



	// split(write_car_52, write_car_53, 0);
	// split(write_car_52, write_car_53, 0);
	// split(write_car_52, write_car_53, 0);

    // execution_001->change24to8_to_g(read_bmp_10, write_car_102);
    // execution_001->change24to8_to_r(read_bmp_10, write_car_103);

	// std::shared_ptr<Exec009> execution_009 = std::make_shared<Exec009>();
	// execution_009->prewitt(	write_car_102, write_car_51);
    // execution_009->Sobel(	write_car_102, write_car_52);
    // execution_009->LOG(		write_car_102, write_car_53);

	// execution_004->rotate(write_car_51, write_car_21, -15);      
	// execution_004->rotate(write_car_52, write_car_22, -15);      
	// execution_004->rotate(write_car_53, write_car_23, -15);    

	
	// execution_005->thresholdByGivenT(write_car_11, write_car_31, write_car_41, 210);
	// execution_005->thresholdByGivenT(write_car_11, write_car_32, write_car_42, 220);
	// execution_005->thresholdByGivenT(write_car_11, write_car_33, write_car_43, 250);

	// execution_005->thresholdByGivenT(write_car_101, write_car_31, write_car_41, 128);
	// execution_003->medianWithBorder(write_car_31, write_car_41);
	// execution_003->medianWithoutBorder(write_car_31, write_car_42);

	// execution_007->HoughI(write_car_42, write_car_12, 5);
	// execution_007->HoughII(write_car_42, write_car_52, 5);
	// // execution_005->thresholdByGivenT(write_car_102, write_car_32, write_car_42, 128);
	// // execution_005->thresholdByGivenT(write_car_103, write_car_33, write_car_43, 128);

	
	// execution_004->rotate(write_car_11, write_car_21, -15);
	// // // execution_004->rotate(write_car_32, write_car_22, -15);
	// // execution_004->rotate(write_car_33, write_car_23, -15);

	// execution_004->perspective_transform_for10(write_car_11, write_image_card);
	// // execution_004->scale(write_car_101, write_car_51, 4.0f, 4.0f);
	// // execution_004->scale(write_car_102, write_car_52, 4.0f, 4.0f);
	// // execution_004->scale(write_car_103, write_car_53, 4.0f, 4.0f);


	
	// execution_008->extractOutline(write_car_31, write_car_41);
	// execution_008->extractOutline(write_car_31, write_car_42);
	// execution_008->extractOutline(write_car_31, write_car_43);
	// // execution_008->regionMark(write_car_101, write_car_51);
	// execution_008->regionMark(write_car_31, write_car_52);
	// execution_008->regionMark(write_car_32, write_car_52);
	// execution_008->regionMark(write_car_33, write_car_53);

}