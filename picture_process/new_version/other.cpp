#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;
typedef unsigned long LONG;


#pragma pack(2)
typedef struct tagBITMAPFILEHEADER{
    WORD bfType;         // 文件类型
    DWORD bfSize;           // 文件大小
    WORD bfReserved1;    // 保留字
    WORD bfReserved2;    // 保留字
    DWORD bfOffBits;        // 文件头到位图的实际偏移 
} BMFH; 


typedef struct tagBITMAPINFOHEADER{
    DWORD biSize;     //该结构的长度，为40
    LONG  biWidth;    //图像宽度
    LONG  biHeight;   //图像高度
    WORD  biPlanes;   //位平面数，必须为1
    WORD  biBitCount; //颜色位数，
    DWORD biCompression; //是否压缩
    DWORD biSizeImage; //实际位图数据占用的字节数
    LONG  biXPelsPerMeter; //目标设备水平分辨率
    LONG  biYPelsPerMeter; //目标设备垂直分辨率
    DWORD biClrUsed; //实际使用的颜色数
    DWORD biClrImportant; //图像中重要的颜色数
} BMIH;

typedef struct tagRGBQUAD {
    BYTE   rgbBlue;
    BYTE   rgbGreen;
    BYTE   rgbRed;
    BYTE   rgbReserved;
} RGBQUAD;
#pragma pack()


void rgb24_to_grey8(char* image_path){
    FILE* fp = fopen(image_path, "rb");
    BMFH rawFileHeader;
    fread(&rawFileHeader, sizeof(BMFH), 1, fp);
    BMIH rawInfoHeader;
    fread(&rawInfoHeader, sizeof(BMIH), 1, fp);

    unsigned int bitSize = rawFileHeader.bfSize - rawFileHeader.bfOffBits;
    BYTE* rawImageData = (BYTE*)malloc(bitSize);
    fread(rawImageData, bitSize, 1, fp);
    fclose(fp);

    struct tagBITMAPFILEHEADER newBmpFileHeader = rawFileHeader;
    struct tagBITMAPINFOHEADER newBmpInfoHeader = rawInfoHeader;
    unsigned int lineBytes_24 =  ((rawInfoHeader.biWidth*3 + 3) / 4) * 4;
    unsigned int lineBytes_8 =  ((rawInfoHeader.biWidth + 3) / 4) * 4;
    unsigned int count24 = lineBytes_24-rawInfoHeader.biWidth*3;

    newBmpInfoHeader.biSizeImage = lineBytes_8 * rawInfoHeader.biHeight;
    newBmpInfoHeader.biClrUsed = 256;
    newBmpFileHeader.bfOffBits = 54 + newBmpInfoHeader.biClrUsed * sizeof(RGBQUAD);
    newBmpFileHeader.bfSize = newBmpInfoHeader.biSizeImage + newBmpFileHeader.bfOffBits;
    newBmpInfoHeader.biBitCount = 8;

    // -------------------------------------------------------------------------
    RGBQUAD rgbquad[256];
    for(int i=0;i<256;i++) {
        rgbquad[i].rgbBlue     = i;
        rgbquad[i].rgbGreen    = i;
        rgbquad[i].rgbRed      = i;
        rgbquad[i].rgbReserved = 0;
    }

    // -------------------------------------------------------------------------
    FILE* fp_grey = fopen("./test1-8-grey.bmp", "wb");
    fwrite(&newBmpFileHeader, 14, 1, fp_grey);
    fwrite(&newBmpInfoHeader, 40, 1, fp_grey);
    fwrite(rgbquad, 256 * sizeof(RGBQUAD), 1, fp_grey);

    FILE* fp_inverted = fopen("./test1-8-inverted.bmp", "wb");
    fwrite(&newBmpFileHeader, 14, 1, fp_inverted);
    fwrite(&newBmpInfoHeader, 40, 1, fp_inverted);
    fwrite(rgbquad, 256 * sizeof(RGBQUAD), 1, fp_inverted);

    FILE* fp_B = fopen("./test1-8-B.bmp", "wb");
    fwrite(&newBmpFileHeader, 14, 1, fp_B);
    fwrite(&newBmpInfoHeader, 40, 1, fp_B);
    fwrite(rgbquad, 256 * sizeof(RGBQUAD), 1, fp_B);

    FILE* fp_G = fopen("./test1-8-G.bmp", "wb");
    fwrite(&newBmpFileHeader, 14, 1, fp_G);
    fwrite(&newBmpInfoHeader, 40, 1, fp_G);
    fwrite(rgbquad, 256 * sizeof(RGBQUAD), 1, fp_G);

    FILE* fp_R = fopen("./test1-8-R.bmp", "wb");
    fwrite(&newBmpFileHeader, 14, 1, fp_R);
    fwrite(&newBmpInfoHeader, 40, 1, fp_R);
    fwrite(rgbquad, 256 * sizeof(RGBQUAD), 1, fp_R);
    // -------------------------------------------------------------------------

    BYTE data;
    unsigned int pointer_24=0;
    unsigned int pointer_8=0;
    for (unsigned int i=0; i<rawInfoHeader.biHeight; i+=1){
        for (unsigned int j=0; j<rawInfoHeader.biWidth; j+=1){

            data = (BYTE)((rawImageData[pointer_24] * 77 + rawImageData[pointer_24+1] * 151 + rawImageData[pointer_24+2] * 28)>>8);
            fwrite(&data, 1, 1, fp_grey);

            data = 255-data;
            fwrite(&data, 1, 1, fp_inverted);

            data = rawImageData[pointer_24];
            fwrite(&data, 1, 1, fp_B);

            data = rawImageData[pointer_24+1];
            fwrite(&data, 1, 1, fp_G);

            data = rawImageData[pointer_24+2];
            fwrite(&data, 1, 1, fp_R);

            pointer_24 += 3;
            pointer_8 += 1;
        }

        pointer_24 += count24;
        for(unsigned int k=rawInfoHeader.biWidth; k<lineBytes_8; k++){
            data = 0;
            fwrite(&data, 1, 1, fp_grey);
            fwrite(&data, 1, 1, fp_inverted);
            fwrite(&data, 1, 1, fp_B);
            fwrite(&data, 1, 1, fp_G);
            fwrite(&data, 1, 1, fp_R);
            pointer_8 += 1;
        }

    }
    fclose(fp_grey); 
    fclose(fp_inverted); 
    fclose(fp_B); 
    fclose(fp_G); 
    fclose(fp_R); 
}

BYTE* draw_point(int* hist, int width, int height, int color=50){
    unsigned int lineBytes_8 =  ((width + 3) / 4) * 4;

    float trans;   // 数量对应于高度的转换比
    int max_hist=0;
    for (int i = 0; i < 256; ++i){
        if (hist[i] > max_hist){
            max_hist = hist[i];
        }
    }
    trans = height*1.0 / max_hist;

    int tempHeight;
    int tempIndex;
    BYTE* pointData = (BYTE*)malloc(lineBytes_8*height);
    memset(pointData, -1, lineBytes_8*height);
    for (int i = 0; i < width; ++i){
        tempIndex = i/(width/256);
        tempHeight = int(hist[tempIndex] * trans);
        for (int j = 0; j < tempHeight; ++j){
            pointData[lineBytes_8*j+i] = color;
        }
    }

    return pointData;   
}

void rgb8_to_histogram(char* image_path){
    FILE* fp = fopen(image_path, "rb");
    BMFH rawFileHeader;
    fread(&rawFileHeader, sizeof(BMFH), 1, fp);
    BMIH rawInfoHeader;
    fread(&rawInfoHeader, sizeof(BMIH), 1, fp);
    RGBQUAD rawRgbquad[256];
    fread(&rawRgbquad, 256 * sizeof(RGBQUAD), 1, fp);

    unsigned int lineBytes_8 =  ((rawInfoHeader.biWidth + 3) / 4) * 4;
    unsigned int bitSize = rawFileHeader.bfSize - rawFileHeader.bfOffBits;
    printf("%d\n", bitSize);
    printf("biWidth: %d, biHeight: %d, biBitCount: %d\n", rawInfoHeader.biWidth, rawInfoHeader.biHeight, rawInfoHeader.biBitCount);
    printf("lineBytes_8: %d\n", lineBytes_8);

    BYTE* rawImageData = (BYTE*)malloc(bitSize);
    printf("lineB");
    fread(rawImageData, bitSize, 1, fp);
    printf("lineB");
    fclose(fp);
    printf("lineB");
    int hist[256];
    memset(hist, 0, sizeof(int) * 256);

    for (int i = 0; i < rawInfoHeader.biHeight; ++i){
        for (int j = 0; j < rawInfoHeader.biWidth; ++j){
            hist[rawImageData[i*lineBytes_8+j]] ++;
        }
    }

    int width = 256;
    int height = 256;
    int drawLB = ((width + 3) / 4) * 4;
    BMFH drawFileHeader = rawFileHeader;
    BMIH drawInfoHeader = rawInfoHeader;
    drawFileHeader.bfSize = 54+256*sizeof(RGBQUAD) + drawLB*height;
    drawInfoHeader.biWidth = width;
    drawInfoHeader.biHeight = height;
    drawInfoHeader.biSizeImage = drawLB*height;
    FILE* fp_draw = fopen("./test2-draw1.bmp", "wb");
    fwrite(&drawFileHeader, 14, 1, fp_draw);
    fwrite(&drawInfoHeader, 40, 1, fp_draw);
    fwrite(&rawRgbquad, 256 * sizeof(RGBQUAD), 1, fp_draw);
    BYTE* pointData = draw_point(hist, width, height);
    fwrite(pointData, ((width + 3) / 4) * 4 * height, 1, fp_draw);
    fclose(fp_draw);
    
    // -------------------------------------
    float fpHist[256];
    float eqHistTemp[256];
    int eqHist[256];
    unsigned int size = rawInfoHeader.biHeight * rawInfoHeader.biWidth;
    memset(fpHist, 0x00, sizeof(float) * 256);
    memset(eqHistTemp, 0x00, sizeof(float) * 256);
    for (int i = 0; i< 256; i++){
        fpHist[i] = (float)hist[i] / (float)size;
    }
    for (int i = 0; i< 256; i++){
        if (i == 0)
            eqHistTemp[i] = fpHist[i];
        else
            eqHistTemp[i] = eqHistTemp[i - 1] + fpHist[i];
    }
    for (int i = 0; i< 256; i++){
        eqHist[i] = (int)(255.0 * eqHistTemp[i] + 0.5);
    }
    for (int i = 0; i < rawInfoHeader.biHeight; i++){
        for (int j = 0; j < rawInfoHeader.biWidth; j++){
            rawImageData[i*lineBytes_8+j] = eqHist[rawImageData[i*lineBytes_8+j]];
        }
    }
    // -------------------------------------
    FILE* fp_equalization = fopen("./test2-equalization.bmp", "wb");
    fwrite(&rawFileHeader, 14, 1, fp_equalization);
    fwrite(&rawInfoHeader, 40, 1, fp_equalization);
    fwrite(&rawRgbquad, 256 * sizeof(RGBQUAD), 1, fp_equalization);
    fwrite(rawImageData, lineBytes_8*rawInfoHeader.biHeight, 1, fp_equalization);
    fclose(fp_equalization);

    memset(hist, 0x00, sizeof(float) * 256);
    for (int i = 0; i < rawInfoHeader.biHeight; ++i){
        for (int j = 0; j < rawInfoHeader.biWidth; ++j){
            hist[rawImageData[i*lineBytes_8+j]] ++;
        }
    }

    FILE* fp_draw2 = fopen("./test2-draw2.bmp", "wb");
    fwrite(&drawFileHeader, 14, 1, fp_draw2);
    fwrite(&drawInfoHeader, 40, 1, fp_draw2);
    fwrite(&rawRgbquad, 256 * sizeof(RGBQUAD), 1, fp_draw2);
    BYTE* pointData2 = draw_point(hist, width, height);
    fwrite(pointData2, ((width + 3) / 4) * 4 * height, 1, fp_draw2);
    fclose(fp_draw2);
}

int main()
{
    char * read_bmp_1 = "/home/Code/github/LearningCpp/picture_process/bitmaps/image1.bmp";
    rgb24_to_grey8(read_bmp_1);
    // rgb8_to_histogram(read_bmp_1);
    return 0;
}
