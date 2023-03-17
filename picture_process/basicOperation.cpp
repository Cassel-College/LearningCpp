// //
// // Created by peng liu on 2/25/23.
// //

// #include "basicOperation.h"
// #include <math.h>
// #include <iostream>
// #include "stdlib.h"
// #include "stdio.h"

// using namespace std;

// unsigned char * basicOperation::bmpScale(unsigned char * bmp, int width, int height, int linebyte, float times1, float times2)
// {
//     double matrix[3][3] = { 0 };
//     int newWidth = width * times1;
//     int newHeight = height * times2;
//     int linebyteT = (newWidth * 8 / 8 + 3) / 4 * 4;
//     int size = newHeight*linebyteT;
//     pBmpBuf = new unsigned char[size] {0};

//     /*for (i = 0; i < height; i++)
//     {
//         for (j = 0; j < width; j++)
//         {
//             int k1 = times1 * i*linebyteT;
//             int k2 = j * times2;
//             pBmpBuf[k1 + k2] = bmp[i*linebyte + j];
//         }
//     }*/
//     matrix[0][0] = times1;
//     matrix[1][1] = times2;
//     matrix[2][2] = 1;

//     int matrixX, matrixY;
//     int k[3];

//     for (i = 0; i < newWidth; i++)
//     {
//         for (j = 0; j < newHeight; j++)
//         {
//             int x = int(i / times1);
//             int y = int(j / times2);
//             pBmpBuf[j * linebyteT + i] = bmp[y*linebyte + x];

//         }
//     }
//     return pBmpBuf;
// }

// unsigned char * basicOperation::bmpMove(unsigned char * bmp, int width, int height, int linebyte, int x, int y)
// {
//     double matrix[3][3] = { 0 };
//     pBmpBuf = new unsigned char[height*linebyte];

//     matrix[0][0] = 1;
//     matrix[1][1] = 1;
//     matrix[2][2] = 1;
//     matrix[0][2] = x;
//     matrix[1][2] = y;
//     int matrixX, matrixY;
//     int k[3];

//     for (i = 0; i < width; i++) {
//         for (j = 0; j < height; j++) {
//             int m[3] = { 0 };
//             k[0] = i;
//             k[1] = j;
//             k[2] = 1;
//             for (matrixX = 0; matrixX < 3; matrixX++) {
//                 for (matrixY = 0; matrixY < 3; matrixY++) {
//                     m[matrixX] = m[matrixX] + matrix[matrixX][matrixY] * k[matrixY];
//                 }
//             }
//             if (m[0] >= 0 && m[0] < height && m[1] >= 0 && m[1] < width) {
//                 pBmpBuf[m[1] * linebyte + m[0]] = bmp[j*linebyte + i];
//             }
//         }
//     }
//     return pBmpBuf;
// }

// unsigned char * basicOperation::bmpRotate(unsigned char * bmp, int width, int height, int linebyte, double angle)
// {
//     double matrix[3][3] = { 0 };
//     pBmpBuf = new unsigned char[height*linebyte]{ 0 };
//     angle = angle * 3.1415926 / 180;

//     matrix[0][0] = cos(angle);
//     matrix[0][1] = sin(angle);
//     matrix[1][0] = -sin(angle);
//     matrix[1][1] = cos(angle);
//     matrix[2][2] = 1;
//     int matrixX, matrixY;
//     int k[3];

//     for (i = 0; i < width; i++) {
//         for (j = 0; j < height; j++) {
//             int m[3] = { 0 };
//             k[0] = i - width/2;
//             k[1] = j - height/2;
//             k[2] = 1;
//             for (matrixX = 0; matrixX < 3; matrixX++) {
//                 for (matrixY = 0; matrixY < 3; matrixY++) {
//                     m[matrixX] = m[matrixX] + matrix[matrixX][matrixY] * k[matrixY];
//                 }
//                 m[matrixX] = m[matrixX] + width / 2;
//             }
//             if (m[0] >= 0 && m[0] < height && m[1] >= 0 && m[1] < width) {
//                 pBmpBuf[m[0] * linebyte + m[1]] = bmp[i*linebyte + j];
//             }

//         }
//     }
//     for (i = 0; i < width; i++) {
//         for (j = 0; j < height; j++) {
//             if (pBmpBuf[i*linebyte + j] == 0 && pBmpBuf[i*linebyte + j - 1] != 0 && pBmpBuf[i*linebyte + j + 1] != 0) {
//                 pBmpBuf[i*linebyte + j] = pBmpBuf[i*linebyte + j - 1];
//             }

//         }
//     }
//     return pBmpBuf;
// }

// unsigned char * basicOperation::bmpMirroring(unsigned char * bmp, int width, int height, int linebyte, int flag)
// {
//     pBmpBuf = new unsigned char[height*linebyte];
//     if (flag == 0) {
//         for (i = 0; i < height; i++) {
//             for (j = 0; j < width; j++) {
//                 pBmpBuf[(height - 1 - i) * linebyte + j] = bmp[i * linebyte + j];
//             }
//         }
//     }
//     if (flag == 1) {
//         for (i = 0; i < height; i++) {
//             for (j = 0; j < width; j++) {
//                 pBmpBuf[i * linebyte + width - 1 - j] = bmp[i * linebyte + j];
//             }
//         }
//     }
//     return pBmpBuf;
// }
