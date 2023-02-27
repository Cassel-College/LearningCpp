#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// typedef long LONG;
// typedef unsigned long DWORD;
// typedef unsigned short WORD;

typedef unsigned short int WORD;
typedef unsigned int DWORD;
typedef signed int LONG;
typedef unsigned char BYTE;
typedef long int UINT;

typedef struct tagPOINT {
    LONG x;
    LONG y;
} POINT;
// } POINT, *PPOINT, *NPPOINT, *LPPOINT;

// //typedef struct
// //{
// //     char ciSize[4]; /* size of BITMAPINFOHEADER */
// //     char ciWidth[4]; /* 位图宽度(像素) */
// //     char ciHeight[4]; /* 位图高度(像素) */
// //     char ciPlanes[2]; /* 目标设备的位平面数, 必须置为1 */
// //     char ciBitCount[2]; /* 每个像素的位数, 1,4,8或24 */
// //     char ciCompress[4]; /* 位图阵列的压缩方法,0=不压缩 */
// //     char ciSizeImage[4]; /* 图像大小(字节) */
// //     char ciXPelsPerMeter[4];/* 目标设备水平每米像素个数 */
// //     char ciYPelsPerMeter[4];/* 目标设备垂直每米像素个数 */
// //     char ciClrUsed[4]; /* 位图实际使用的颜色表的颜色数 */
// //     char ciClrImportant[4]; /* 重要颜色索引的个数 */
// //
// //}BITMAPINFOHEADER; /* 位图信息头结构 */

typedef struct {
    char rgbBlue;
    char rgbGreen;
    char rgbRed;
    char rgbReserved;
}RGBQUAD;

// typedef struct tagBITMAPINFOHEADER{
//     DWORD      biSize;           //结构体的大小（包括颜色表）
//     LONG       biWidth;          //图片的宽
//     LONG       biHeight;         //图片的长
//     WORD       biPlanes;         //目标绘图设备包含的层数，必须设置为1
//     WORD       biBitCount;       //图像的的位数，例如24位，8位等（位数是色彩的深度，比如八位是只用2的八次方表示颜色）
//     DWORD      biCompression;
//     DWORD      biSizeImage;      //图像数据的大小 = biWidth * biHeight * biBitCount
//     LONG       biXPelsPerMeter;  //是现实世界中每米包含的像素数 一般设为3780
//     LONG       biYPelsPerMeter;  //同上
//     DWORD      biClrUsed;
//     DWORD      biClrImportant;
// } BITMAPINFOHEADER;
// // } BITMAPINFOHEADER, *LPBITMAPINFOHEADER, *PBITMAPINFOHEADER;


// typedef struct tagBITMAPFILEHEADER {
//     WORD    bfType;              //图片的类型 必须是BM 填0x4d42即十进制的19778
//     DWORD   bfSize;              //图片的大小 bf0ffBits+长*宽*位数
//     WORD    bfReserved1;         //必须是0
//     WORD    bfReserved2;         //必须是0
//     DWORD   bfOffBits;           //从文件头开始到颜色数据的偏移量 54+sizeof(RGBQUAD)*256
// } BITMAPFILEHEADER;
// // } BITMAPFILEHEADER, *LPBITMAPFILEHEADER, *PBITMAPFILEHEADER;


typedef struct tagBITMAPFILEHEADER {
    WORD   bfType;           /* "BM" */
    DWORD  bfSize;           /* Size of file in bytes */
    WORD   bfReserved1;      /* set to 0 */
    WORD   bfReserved2;      /* set to 0 */
    DWORD  bfOffBits;        /* Byte offset to actual bitmap data (= 54 if RGB) */
}__attribute__((packed)) BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER {
    DWORD  biSize;           /* Size of BITMAPINFOHEADER, in bytes (= 40) */
    LONG   biWidth;          /* Width of image, in pixels */
    LONG   biHeight;         /* Height of images, in pixels */
    WORD   biPlanes;         /* Number of planes in target device (set to 1) */
    WORD   biBitCount;       /* Bits per pixel (24 in this case) */
    DWORD  biCompression;    /* Type of compression (0 if no compression) */
    DWORD  biSizeImage;      /* Image size, in bytes (0 if no compression) */
    LONG   biXPelsPerMeter;  /* Resolution in pixels/meter of display device */
    LONG   biYPelsPerMeter;  /* Resolution in pixels/meter of display device */
    DWORD  biClrUsed;        /* Number of colors in the color table (if 0, use
                                maximum allowed by biBitCount) */
    DWORD  biClrImportant;   /* Number of important colors.  If 0, all colors
                                are important */
}__attribute__((packed)) BITMAPINFOHEADER;


// int read_bmp_00(unsigned char** image, int* out_width, int* out_height,  int* bitCount,  char* fileName){

// 	FILE* input;
//     int width, height, level;
//     BITMAPFILEHEADER bmfhdr;
//     BITMAPINFOHEADER bmihdr;
//  	printf("filename %s", fileName); 
// 	if (!(input = fopen(fileName, "r"))) {
//             printf("Cannot open file %s.\n", fileName);
// 			return 0;
//      }
// 	    fread(&bmfhdr.bfType, sizeof(WORD), 1, input);
//         fread(&bmfhdr.bfSize, sizeof(DWORD), 1, input);
//         fread(&bmfhdr.bfReserved1, sizeof(WORD), 1, input);
//         fread(&bmfhdr.bfReserved2, sizeof(WORD), 1, input);
//         fread(&bmfhdr.bfOffBits, sizeof(DWORD), 1, input);
//         fread(&bmihdr.biSize, sizeof(DWORD), 1, input);
//         fread(&bmihdr.biWidth, sizeof(LONG), 1, input);
//         fread(&bmihdr.biHeight, sizeof(LONG), 1, input);
//         fread(&bmihdr.biPlanes, sizeof(WORD), 1, input);
//         fread(&bmihdr.biBitCount, sizeof(WORD), 1, input);
//         fread(&bmihdr.biCompression, sizeof(DWORD), 1, input);
//         fread(&bmihdr.biSizeImage, sizeof(DWORD), 1, input);
//         fread(&bmihdr.biXPelsPerMeter, sizeof(LONG), 1, input);
//         fread(&bmihdr.biYPelsPerMeter, sizeof(LONG), 1, input);
//         fread(&bmihdr.biClrUsed, sizeof(DWORD), 1, input);
//         fread(&bmihdr.biClrImportant, sizeof(DWORD), 1, input);
//         printf("+------------------+\n");
//         printf("| bfType: %d\n", bmfhdr.bfType);
//         printf("| bfSize: %d\n", bmfhdr.bfSize);
//         printf("| bfReserved1: %d\n", bmfhdr.bfReserved1);
//         printf("| bfReserved2: %d\n", bmfhdr.bfReserved2);
//         printf("| bfOffBits: %d\n", bmfhdr.bfOffBits);
//         printf("| biSize: %d\n", bmihdr.biSize);
//         printf("| biWidth: %d\n", bmihdr.biWidth);
//         printf("| biHeight: %d\n", bmihdr.biHeight);
//         printf("| biPlanes: %d\n", bmihdr.biPlanes);
//         printf("| biBitCount: %d\n", bmihdr.biBitCount);
//         printf("| biCompression: %d\n", bmihdr.biCompression);
//         printf("| biSizeImage: %d\n", bmihdr.biSizeImage);
//         printf("| biXPelsPerMeter: %d\n", bmihdr.biXPelsPerMeter);
//         printf("| biYPelsPerMeter: %d\n", bmihdr.biYPelsPerMeter);
//         printf("| biClrUsed: %d\n", bmihdr.biClrUsed);
//         printf("| biClrImportant: %d\n", bmihdr.biClrImportant);
//         printf("+------------------+\n");
//         /* width and height of bmp image. */
//         width = bmihdr.biWidth;
//         height = bmihdr.biHeight;
//         level = 4; 
// 		*out_width = width;
// 		*out_height = height;	
//         *image = (BYTE*)malloc(height * width * level * sizeof(BYTE));
//         memset(*image, 0x00, height * width * level * sizeof(BYTE));
//         /* read pixel from file to array image. */
//         /*
//           bmihdr.biBitCount = 1  -> Binary image.
//           bmihdr.biBitCount = 8  -> Gray-Level or Indexed image.
//           bmihdr.biBitCount = 24 -> RGB image.
//         */
//         if ((bmihdr.biBitCount == 1) || (bmihdr.biBitCount == 8)) {
// 			return 0;
// 			/*
//             offset = bmfhdr.bfOffBits - 54;
//             fseek(input, offset, SEEK_CUR);
//             auto size = height* width* bmihdr.biBitCount / 8;
//             fread(image, 1, size, input);
//             fclose(input);
// 			*///libavif did not surport this format
//         }
//     	else if (bmihdr.biBitCount == 24 || bmihdr.biBitCount == 32) {
//         	int readPos = 0;
//         	for (int i = height - 1; i >= 0; i--) {
//            	 	readPos = i * width * (bmihdr.biBitCount / 8);
//             	int s = (size_t)(long)width * (bmihdr.biBitCount / 8);
//             	 fread(*image + readPos, 1, s, input);
//         }
//         fclose(input);
//     	}
//         else {
//             printf("Something wrong with biBitCount of image\n");
//             return 0;
//         }
// 		*bitCount = bmihdr.biBitCount;
// 		return 1;
// }
