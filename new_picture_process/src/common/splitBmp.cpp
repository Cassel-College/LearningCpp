#include "splitBmp.h"

// //初始化三个分量的像素点
// rgb SplitBmp::init_rgb(unsigned char * bmp, int height, int width, int linebyte)
// {
	
// 	rgb total;
// 	unsigned char * image_blue = new unsigned char[height*linebyte * 3]{ 0 };
// 	unsigned char * image_green = new unsigned char[height*linebyte * 3]{ 0 };
// 	unsigned char * image_red = new unsigned char[height*linebyte * 3]{ 0 };
// 	// for (int i=0;i<height*linebyte * 3; i++) {
// 	// 	image_blue[i] = 255;
// 	// 	image_green[i] = 255;
// 	// 	image_red[i] = 255;
// 	// }
// 	for (i = 0; i < (height * 24 / 8 + 3) / 4 * 4; i++)
// 	{
// 		for (j = 0; j < (width * 24 / 8 + 3) / 4 * 4; j++)
// 		{	
// 			// 0 0 0 是黑色
// 			int v = 0;

// 			// b
// 			// if ((bmp[i*linebyte + j * 3 + 0] >= 235) && (bmp[i*linebyte + j * 3 + 1] >= 235) && (bmp[i*linebyte + j * 3 + 2] >= 235)){
// 			// 	image_blue[i*linebyte + j * 3 + 0] = 255;
// 			// 	image_blue[i*linebyte + j * 3 + 1] = 255;
// 			// 	image_blue[i*linebyte + j * 3 + 2] = 255;
// 			// }
// 			// if (bmp[i*linebyte + j * 3 + 0] >= 235) {
// 			// 	image_blue[i*linebyte + j * 3 + 0] = 255;
// 			// 	image_blue[i*linebyte + j * 3 + 1] = 255;
// 			// 	image_blue[i*linebyte + j * 3 + 2] = 255;
// 			// }

// 			// // g
// 			// if ((bmp[i*linebyte + j * 3 + 0] >= 235) && (bmp[i*linebyte + j * 3 + 1] >= 235) && (bmp[i*linebyte + j * 3 + 2] >= 235)){
// 			// 	image_green[i*linebyte + j * 3 + 0] = 255;
// 			// 	image_green[i*linebyte + j * 3 + 1] = 255;
// 			// 	image_green[i*linebyte + j * 3 + 2] = 255;
// 			// }
// 			// if (bmp[i*linebyte + j * 3 + 1] >= 235) {
// 			// 	image_green[i*linebyte + j * 3 + 0] = 255;
// 			// 	image_green[i*linebyte + j * 3 + 1] = 255;
// 			// 	image_green[i*linebyte + j * 3 + 2] = 255; 
// 			// }
			
// 			// // r
// 			// if ((bmp[i*linebyte + j * 3 + 0] >= 235) && (bmp[i*linebyte + j * 3 + 1] >= 235) && (bmp[i*linebyte + j * 3 + 2] >= 235)){
// 			// 	image_red[i*linebyte + j * 3 + 0] = 255;
// 			// 	image_red[i*linebyte + j * 3 + 1] = 255;
// 			// 	image_red[i*linebyte + j * 3 + 2] = 255;
// 			// }
// 			// if (bmp[i*linebyte + j * 3 + 2] >= 230) {
// 			// 	image_red[i*linebyte + j * 3 + 0] = 255;
// 			// 	image_red[i*linebyte + j * 3 + 1] = 255;
// 			// 	image_red[i*linebyte + j * 3 + 2] = 255;
// 			// }

// 			// // image_green[i*linebyte + j * 3 + 0] = 255;
// 			// image_green[i*linebyte + j * 3 + 1] = bmp[i*linebyte + j * 3 + 1] - v;
// 			// // image_green[i*linebyte + j * 3 + 2] = 255;

// 			// image_red[i*linebyte + j * 3 + 0] = 255;
// 			// image_red[i*linebyte + j * 3 + 1] = 255;
// 			// image_red[i*linebyte + j * 3 + 2] = bmp[i*linebyte + j * 3 + 2] - v;
// 		}
// 	}
// 	total.blue = image_blue;
// 	total.red = image_red;
// 	total.green = image_green;

// 	return total;
// }

rgb SplitBmp::init_rgb(unsigned char * bmp, int height, int width, int linebyte)
{
	rgb total;
	unsigned char * image_blue = new unsigned char[height*linebyte * 3]{ 0 };
	unsigned char * image_green = new unsigned char[height*linebyte * 3]{ 0 };
	unsigned char * image_red = new unsigned char[height*linebyte * 3]{ 0 };

	for (i = 0; i < (height * 24 / 8 + 3) / 4 * 4; i++)
	{
		for (j = 0; j < (width * 24 / 8 + 3) / 4 * 4; j++)
		{
			image_blue[i*linebyte + j * 3 + 0] = bmp[i*linebyte + j * 3 + 0];
			image_green[i*linebyte + j * 3 + 1] = bmp[i*linebyte + j * 3 + 1];
			image_red[i*linebyte + j * 3 + 2] = bmp[i*linebyte + j * 3 + 2];
		}
	}
	total.blue = image_blue;
	total.red = image_red;
	total.green = image_green;

	return total;
}


void SplitBmp::rgb24_to_grey8(char* image_path, unsigned char * rawImageData) {
	std::cout << "111" << std::endl;
    FILE* fp = fopen(image_path, "rb");
    BMFH rawFileHeader;
    fread(&rawFileHeader, sizeof(BMFH), 1, fp);
    BMIH rawInfoHeader;
    fread(&rawInfoHeader, sizeof(BMIH), 1, fp);
	std::cout << "111" << std::endl;
    unsigned int bitSize = rawFileHeader.bfSize - rawFileHeader.bfOffBits;
    // BYTE* rawImageData = (BYTE*)malloc(bitSize);
    // fread(rawImageData, bitSize, 1, fp);
    // fclose(fp);
	std::cout << "111" << std::endl;
    struct tagBITMAPFILEHEADER newBmpFileHeader = rawFileHeader;
    struct tagBITMAPINFOHEADER newBmpInfoHeader = rawInfoHeader;
    unsigned int lineBytes_24 =  ((rawInfoHeader.biWidth*3 + 3) / 4) * 4;
    unsigned int lineBytes_8 =  ((rawInfoHeader.biWidth + 3) / 4) * 4;
    unsigned int count24 = lineBytes_24-rawInfoHeader.biWidth*3;
	std::cout << "111" << std::endl;
    newBmpInfoHeader.biSizeImage = lineBytes_8 * rawInfoHeader.biHeight;
    newBmpInfoHeader.biClrUsed = 256;
    newBmpFileHeader.bfOffBits = 54 + newBmpInfoHeader.biClrUsed * sizeof(RGBQUAD);
    newBmpFileHeader.bfSize = newBmpInfoHeader.biSizeImage + newBmpFileHeader.bfOffBits;
    newBmpInfoHeader.biBitCount = 8;
	std::cout << "111" << std::endl;
    // -------------------------------------------------------------------------
    RGBQUAD rgbquad[256];
    for(int i=0;i<256;i++) {
        rgbquad[i].rgbBlue     = i;
        rgbquad[i].rgbGreen    = i;
        rgbquad[i].rgbRed      = i;
        rgbquad[i].rgbReserved = 0;
    }

    // -------------------------------------------------------------------------
    // FILE* fp_grey = fopen("./test1-8-grey.bmp", "wb");
    // fwrite(&newBmpFileHeader, 14, 1, fp_grey);
    // fwrite(&newBmpInfoHeader, 40, 1, fp_grey);
    // fwrite(rgbquad, 256 * sizeof(RGBQUAD), 1, fp_grey);

    // FILE* fp_inverted = fopen("./test1-8-inverted.bmp", "wb");
    // fwrite(&newBmpFileHeader, 14, 1, fp_inverted);
    // fwrite(&newBmpInfoHeader, 40, 1, fp_inverted);
    // fwrite(rgbquad, 256 * sizeof(RGBQUAD), 1, fp_inverted);

    FILE* fp_B = fopen("/home/Code/github/LearningCpp/picture_process/bitmaps/test1-8-B.bmp", "wb");
    fwrite(&newBmpFileHeader, 14, 1, fp_B);
    fwrite(&newBmpInfoHeader, 40, 1, fp_B);
    fwrite(rgbquad, 256 * sizeof(RGBQUAD), 1, fp_B);

    // FILE* fp_G = fopen("./test1-8-G.bmp", "wb");
    // fwrite(&newBmpFileHeader, 14, 1, fp_G);
    // fwrite(&newBmpInfoHeader, 40, 1, fp_G);
    // fwrite(rgbquad, 256 * sizeof(RGBQUAD), 1, fp_G);

    // FILE* fp_R = fopen("./test1-8-R.bmp", "wb");
    // fwrite(&newBmpFileHeader, 14, 1, fp_R);
    // fwrite(&newBmpInfoHeader, 40, 1, fp_R);
    // fwrite(rgbquad, 256 * sizeof(RGBQUAD), 1, fp_R);
    // -------------------------------------------------------------------------

    BYTE data;
    unsigned int pointer_24=0;
    unsigned int pointer_8=0;
    for (unsigned int i=0; i<rawInfoHeader.biHeight; i+=1){
        for (unsigned int j=0; j<rawInfoHeader.biWidth; j+=1){

            // data = (BYTE)((rawImageData[pointer_24] * 77 + rawImageData[pointer_24+1] * 151 + rawImageData[pointer_24+2] * 28)>>8);
            // fwrite(&data, 1, 1, fp_grey);

            // data = 255-data;
            // fwrite(&data, 1, 1, fp_inverted);

            data = rawImageData[pointer_24];
            fwrite(&data, 1, 1, fp_B);

            // data = rawImageData[pointer_24+1];
            // fwrite(&data, 1, 1, fp_G);

            // data = rawImageData[pointer_24+2];
            // fwrite(&data, 1, 1, fp_R);

            pointer_24 += 3;
            pointer_8 += 1;
        }

        pointer_24 += count24;
        for(unsigned int k=rawInfoHeader.biWidth; k<lineBytes_8; k++){
            data = 0;
            // fwrite(&data, 1, 1, fp_grey);
            // fwrite(&data, 1, 1, fp_inverted);
            fwrite(&data, 1, 1, fp_B);
            // fwrite(&data, 1, 1, fp_G);
            // fwrite(&data, 1, 1, fp_R);
            pointer_8 += 1;
        }

    }
    // fclose(fp_grey); 
    // fclose(fp_inverted); 
    fclose(fp_B); 
    // fclose(fp_G); 
    // fclose(fp_R); 
}

unsigned char * SplitBmp::get_bgr_of_b(unsigned char * bmp, int height, int width, int linebyte, int lineByte2) {
	unsigned char * pBmpBuf_b = new unsigned char[height*linebyte]{ 255 };
	unsigned char * pBmpBuf_g = new unsigned char[height*linebyte]{ 0 };
	unsigned char * pBmpBuf_r = new unsigned char[height*linebyte]{ 0 };

	unsigned char * pBmpBuf = new unsigned char[height*linebyte]{ 0 };
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			int blue = bmp[i*lineByte2 + j * 3 + 0];
			int green = bmp[i*lineByte2 + j * 3 + 1];
			int red = bmp[i*lineByte2 + j * 3 + 2];
			pBmpBuf_b[i * linebyte + j] = bmp[i*lineByte2 + j * 3 + 0];
			pBmpBuf_g[i * linebyte + j] = bmp[i*lineByte2 + j * 3 + 1];
			pBmpBuf_r[i * linebyte + j] = bmp[i*lineByte2 + j * 3 + 2];
		}
	}
	// int w = 522;
	// int h = 442;
	// int p1[2] = {314, 260};
	// int p2[2] = {285, 360};
	// int p3[2] = {286, 250};
	// int p4[2] = {258, 354};

	// for (i = h - p1[0]; i < h - p1[0] + 10; i++) {
	// 	for (j = p1[1]; j < p1[1] + 30; j++) {
	// 		pBmpBuf_b[i * linebyte + j] = 0;
	// 	}
	// }
	// for (i = h - p2[0]; i < h - p2[0] + 10; i++) {
	// 	for (j = p2[1]; j < p2[1] + 30; j++) {
	// 		pBmpBuf_b[i * linebyte + j] = 0;
	// 	}
	// }
	// for (i = h - p3[0]; i < h - p3[0] + 10; i++) {
	// 	for (j = p3[1]; j < p3[1] + 30; j++) {
	// 		pBmpBuf_b[i * linebyte + j] = 0;
	// 	}
	// }
	// for (i = h - p4[0]; i < h - p4[0] + 10; i++) {
	// 	for (j = p4[1]; j < p4[1] + 30; j++) {
	// 		pBmpBuf_b[i * linebyte + j] = 0;
	// 	}
	// }
	return pBmpBuf_b;
}

unsigned char * SplitBmp::get_bgr_of_g(unsigned char * bmp, int height, int width, int linebyte, int lineByte2) {
	unsigned char * pBmpBuf_b = new unsigned char[height*linebyte]{ 0 };
	unsigned char * pBmpBuf_g = new unsigned char[height*linebyte]{ 0 };
	unsigned char * pBmpBuf_r = new unsigned char[height*linebyte]{ 0 };

	unsigned char * pBmpBuf = new unsigned char[height*linebyte]{ 0 };
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			int blue = bmp[i*lineByte2 + j * 3 + 0];
			int green = bmp[i*lineByte2 + j * 3 + 1];
			int red = bmp[i*lineByte2 + j * 3 + 2];
			pBmpBuf_b[i * linebyte + j] = bmp[i*lineByte2 + j * 3 + 0];
			pBmpBuf_g[i * linebyte + j] = bmp[i*lineByte2 + j * 3 + 1];
			pBmpBuf_r[i * linebyte + j] = bmp[i*lineByte2 + j * 3 + 2];
		}
	}
	return pBmpBuf_g;
}

unsigned char * SplitBmp::get_bgr_of_r(unsigned char * bmp, int height, int width, int linebyte, int lineByte2) {
	unsigned char * pBmpBuf_b = new unsigned char[height*linebyte]{ 0 };
	unsigned char * pBmpBuf_g = new unsigned char[height*linebyte]{ 0 };
	unsigned char * pBmpBuf_r = new unsigned char[height*linebyte]{ 0 };

	unsigned char * pBmpBuf = new unsigned char[height*linebyte]{ 0 };
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			int blue = bmp[i*lineByte2 + j * 3 + 0];
			int green = bmp[i*lineByte2 + j * 3 + 1];
			int red = bmp[i*lineByte2 + j * 3 + 2];
			pBmpBuf_b[i * linebyte + j] = bmp[i*lineByte2 + j * 3 + 0];
			pBmpBuf_g[i * linebyte + j] = bmp[i*lineByte2 + j * 3 + 1];
			pBmpBuf_r[i * linebyte + j] = bmp[i*lineByte2 + j * 3 + 2];
		}
	}
	return pBmpBuf_r;
}

//初始化灰度图的像素点
unsigned char * SplitBmp::init_gray(unsigned char * bmp, int height, int width, int linebyte, int lineByte2)
{
	// 灰度图只有亮度信息，无颜色信息，可用Y表示
	// lineByte2： 原图像宽度
	// 初始化输出的灰度图
	unsigned char * pBmpBuf = new unsigned char[height*linebyte]{ 0 };
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {	
			//取原来图像的像素X3, [BGR,BGR,BGR]
			int blue = bmp[i*lineByte2 + j * 3 + 0];
			int green = bmp[i*lineByte2 + j * 3 + 1];
			int red = bmp[i*lineByte2 + j * 3 + 2];
			// RGB彩色图像变换为灰度图理论中的参数
			pBmpBuf[i*linebyte + j] = 0.1140 * blue + 0.5870 * green + 0.2989 * red;
		}
	}
	return pBmpBuf;
}


unsigned char * SplitBmp::split_car_number(unsigned char * bmp, int height, int width, int linebyte, int index)
{
	// 灰度图只有亮度信息，无颜色信息，可用Y表示
	// lineByte2： 原图像宽度
	// 初始化输出的灰度图
	unsigned char * pBmpBuf = new unsigned char[height*linebyte]{ 0 };
	int w_set[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int index_ = 1;
	int open_key = true;
	for (j = 0; j < width; j++) {	
		bool is_cut = true;
		for (i = 0; i < height; i++) {
			if (bmp[i * linebyte + j] != 0) {
				is_cut = false;
				open_key = false;
				break;
			}
		}
		if (is_cut) {
			if (open_key == false) {
				open_key = true;
				w_set[index_] = j;
				index_++;
			}
		}
		if (index_ >= 10) {
			break;
		}
	}

	for (int i = 0; i < index_; i++) {
		std::cout << w_set[i] << std::endl;
	}

	for (j = w_set[index]; j < w_set[index + 1]; j++) {	
		for (i = 0; i < height; i++) {
			pBmpBuf[i * linebyte + j] = bmp[i * linebyte + j];
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
