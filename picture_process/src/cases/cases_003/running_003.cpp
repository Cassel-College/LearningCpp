#include "running_003.h"

Exec003::Exec003() {

}

Exec003::~Exec003() {
    
}

Bmp Exec003::init_colortable(Bmp bmp)
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


//均值滤波_无边界
void Exec003::averageWithoutBorder(const char *read_bmp, const char *write_bmp)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = spatial.average_without_border(in_bmp.pBmpBuf,
													 in_bmp.width,
													 in_bmp.height,
													 in_bmp.lineByte);
	out_bmp = init_colortable(out_bmp);//可能不需要再次初始化调色板
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "均值滤波_无边界 完成" << endl;
}

//均值滤波_有边界
void Exec003::averageWithBorder(const char *read_bmp, const char *write_bmp)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = spatial.average_with_border(in_bmp.pBmpBuf,
												  in_bmp.width,
												  in_bmp.height,
												  in_bmp.lineByte);
	out_bmp = init_colortable(out_bmp);//可能不需要再次初始化调色板
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "均值滤波_有边界 完成" << endl;
}

//中值滤波_无边界
void Exec003::medianWithoutBorder(const char *read_bmp, const char *write_bmp)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = spatial.median_without_border(in_bmp.pBmpBuf,
													in_bmp.width,
													in_bmp.height,
													in_bmp.lineByte);
	out_bmp = init_colortable(out_bmp);//可能不需要再次初始化调色板
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "中值滤波_无边界 完成" << endl;
}

//中值滤波_有边界
void Exec003::medianWithBorder(const char *read_bmp, const char *write_bmp)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = spatial.median_with_border(in_bmp.pBmpBuf,
												 in_bmp.width,
												 in_bmp.height,
												 in_bmp.lineByte);
	out_bmp = init_colortable(out_bmp);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "中值滤波_有边界 完成" << endl;
}

void Exec003::run() {
    averageWithBorder(read_bmp_31, write_bmp_ab);
	averageWithoutBorder(read_bmp_31, write_bmp_aob);
	medianWithBorder(read_bmp_32, write_bmp_mb);
	medianWithoutBorder(read_bmp_32, write_bmp_mob);
}