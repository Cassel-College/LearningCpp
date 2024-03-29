//
// Created by peng liu on 2/25/23.
//

#include "basicOperation.h"
#include <math.h>
#include <iostream>
#include "stdlib.h"
#include "stdio.h"

#include "perspective_transform.h"

using namespace std;

unsigned char * basicOperation::bmpScale(unsigned char * bmp, int width, int height, int linebyte, float times1, float times2)
{
    double matrix[3][3] = { 0 };
    int newWidth = width * times1;
    int newHeight = height * times2;
    int linebyteT = (newWidth * 8 / 8 + 3) / 4 * 4;
    int size = newHeight*linebyteT;
    pBmpBuf = new unsigned char[size] {0};
    matrix[0][0] = times1;
    matrix[1][1] = times2;
    matrix[2][2] = 1;
    int matrixX, matrixY;
    int k[3];

    for (i = 0; i < newWidth; i++) {
        for (j = 0; j < newHeight; j++) {
            int x = i / times1;
            int y = j / times2;
            pBmpBuf[j * linebyteT + i] = bmp[y*linebyte + x];
        }
    }
    return pBmpBuf;
}

unsigned char * basicOperation::bmpMove(unsigned char * bmp, int width, int height, int linebyte, int x, int y)
{
    pBmpBuf = new unsigned char[height*linebyte];
    int matrix[3][3] = {{1, 0, x},
                        {0, 1, y},
                        {0, 0, 1}};

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            int new_x = j + x;
            int new_y = i + y;
            if ((j + x) >= 0 && (j + x) < height && (i + y) >= 0 && (i + y) < width) {
                pBmpBuf[new_x * linebyte + new_y] = bmp[j*linebyte + i];
            }
        }
    }
    return pBmpBuf;
}

unsigned char * basicOperation::bmpCreate(unsigned char * bmp, int width, int height, int linebyte, std::vector<int> &infos) {
    linebyte = (infos[0] * 8 / 8 + 3) / 4 * 4;
    pBmpBuf = new unsigned char[infos[1] * linebyte] {0};
    int newlineByte = ((width * 2) * 8 / 8 + 3) / 4 * 4;
    for (int i = infos[4], new_y = 0; i < infos[5]; i++, new_y++) {
        int ii = 0;
        for (int j = infos[2], new_x = 0; j < infos[3]; j++, new_x++) {
            pBmpBuf[new_y * linebyte + new_x] = bmp[i*newlineByte + j];
            ii = ii + 1;
        }
    }
    return pBmpBuf;
}

unsigned char * basicOperation::bmpRotate(unsigned char * bmp, int width, int height, int linebyte, double angle)
{
    pBmpBuf = new unsigned char[height*linebyte]{ 0 };
    angle = angle * 3.1415926 / 180;
    int matrixX, matrixY;
    double matrix[3][3] = {{cos(angle),  sin(angle), 0},
                           {-sin(angle), cos(angle), 0},
                           {0,           0,          1}};

    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            int m[3] = {0};
            int k[3] = {i - width/2, 
                        j - height/2,
                        1};
            // 矩阵乘法
            for (matrixX = 0; matrixX < 3; matrixX++) {
                for (matrixY = 0; matrixY < 3; matrixY++) {
                    m[matrixX] = m[matrixX] + matrix[matrixX][matrixY] * k[matrixY];
                }
            }
            // 移动图片
            m[0] = m[0] + width / 2;
            m[1] = m[1] + height / 2;
            // 映射补点
            if (m[0] >= 0 && m[0] < height && m[1] >= 0 && m[1] < width) {
                pBmpBuf[m[0] * linebyte + m[1]] = bmp[i*linebyte + j];
            }
        }
    }
    // 将黑点 用 它左边的非黑点代替
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            if (pBmpBuf[i*linebyte + j] == 0 && pBmpBuf[i*linebyte + j - 1] != 0 && pBmpBuf[i*linebyte + j + 1] != 0) {
                if (i*linebyte + j - 1 != 0) {
                    pBmpBuf[i*linebyte + j] = pBmpBuf[i*linebyte + j - 1];
                }
            }
        }
    }
    return pBmpBuf;
}

unsigned char * basicOperation::bmpRotateII(unsigned char * bmp, int width, int height, int linebyte, double angle, std::vector<int> &infos)
{
    int newlineByte = ((width * 2) * 8 / 8 + 3) / 4 * 4;
    pBmpBuf = new unsigned char[height * 2 * newlineByte]{ 0 };
    angle = angle * 3.1415926 / 180;
    int matrixX, matrixY;
    double matrix[3][3] = {{cos(angle),  sin(angle), 0},
                           {-sin(angle), cos(angle), 0},
                           {0,           0,          1}};
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            int m[3] = {0};
            int k[3] = {i - width/2, 
                        j - height/2,
                        1};
            for (matrixX = 0; matrixX < 3; matrixX++) {
                for (matrixY = 0; matrixY < 3; matrixY++) {
                    m[matrixX] = m[matrixX] + matrix[matrixX][matrixY] * k[matrixY];
                }
            }
            m[0] = m[0] + width;
            m[1] = m[1] + height;
            if (m[0] >= 0 && m[0] < height * 2 && m[1] >= 0 && m[1] < width * 2) {
                pBmpBuf[m[0]*newlineByte + m[1]] = bmp[i*linebyte + j];
            }
        }
    }
    for (int i = 0; i < width * 2; i++) {
        for (j = 0; j < height * 2; j++) {
            if (pBmpBuf[i*newlineByte + j] == 0 && pBmpBuf[i*newlineByte + j - 1] != 0 && pBmpBuf[i*newlineByte + j + 1] != 0) {
                pBmpBuf[i*newlineByte + j] = pBmpBuf[i*newlineByte + j - 1];
            }
        }
    }
    std::cout << "探生成图像的边界" << std::endl;
    int h1 = -1;
    int h2 = -1;
    int w1 = -1;
    int w2 = -1;
    for (int i = 0; i < width * 2; i++) {
        for (int j = 0; j < height * 2 - 1; j++) {
            if (int(pBmpBuf[i * newlineByte + j]) != 0) {
                h1 = i;
                std::cout << "探生成图像的边界上" << h1 <<std::endl;
                break;
            }
        }
        if (h1 != -1) {
            break;
        }
    }
    for (int i = h1 + 1; i < width * 2; i++) {
        bool is_picture = false;
        for (int j = 0; j < height * 2; j++) {
            if (pBmpBuf[i*newlineByte + j] != 0) {
                is_picture = true;
                break;
            }
        }
        if (is_picture == false) {
            h2 = i;
            std::cout << "探生成图像的边界下" << h2 <<std::endl;
            break;
        }
    }

    for (int j = 0; j < height * 2; j++) {
        for (int i = 0; i < width * 2 - 1; i++) {
            if (int(pBmpBuf[i * newlineByte + j]) != 0) {
                w1 = j;
                break;
            }
        }
        if (w1 != -1) {
            break;
        }
    }
    for (int j = w1; j < height * 2; j++) {
        bool is_picture = false;
        for (int i = 0; i < width * 2 - 1; i++) {
            if (pBmpBuf[i*newlineByte + j] != 0) {
                is_picture = true;
                break;
            }
        }
        if (is_picture == false) {
            w2 = j;
            std::cout << "探生成图像的边界右" << w2 <<std::endl;
            break;
        }
    }
    std::cout << "探生成图像的边界完毕" << std::endl;

    // 新图片高度
    int hh = h2 - h1;
    int ww = w2 - w1;
    std::cout << "新图像的高度:" << hh << std::endl;
    std::cout << "新图像的高度:" << ww << std::endl;
    
    infos.push_back(ww);
    infos.push_back(hh);
    infos.push_back(w1);
    infos.push_back(w2);
    infos.push_back(h1);
    infos.push_back(h2);
    return pBmpBuf;
}

unsigned char * basicOperation::bmpMirroring(unsigned char * bmp, int width, int height, int linebyte, int flag)
{
    pBmpBuf = new unsigned char[height*linebyte];
    if (flag == 0) {
        for (i = 0; i < height; i++) {
            for (j = 0; j < width; j++) {
                pBmpBuf[(height - 1 - i) * linebyte + j] = bmp[i * linebyte + j];
            }
        }
    }
    if (flag == 1) {
        for (i = 0; i < height; i++) {
            for (j = 0; j < width; j++) {
                pBmpBuf[i * linebyte + width - 1 - j] = bmp[i * linebyte + j];
            }
        }
    }
    return pBmpBuf;
}

unsigned char * basicOperation::bmpPerspect(unsigned char * bmp, int width, int height, int linebyte) {

    pBmpBuf = new unsigned char[height*linebyte];
    std::cout << width << "," << height << std::endl;
    int target = 700;
    PerspectiveTransform tansform = PerspectiveTransform::quadrilateralToQuadrilateral(
		0, 0,
		width-1 + target, -target,
		0, height-1,
		width-1 + target, height+target,
        0, 0,
		width-1, 0,
		0, height-1,
		width-1, height-10);
    
    vector<float> ponits;
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			ponits.push_back(j);
			ponits.push_back(i);
		}
	}

	tansform.transformPoints(ponits);

    for(int i=0;i< height;i++) {
		for (int j = 0; j < width; j++){
			int tmp = i * width + j;
			int x = ponits[tmp * 2];
			int y = ponits[tmp * 2 + 1];
			if(x < 0 || x > (width - 1) || y < 0 || y > (height - 1))
				continue;

            pBmpBuf[i * linebyte + j] = bmp[y * linebyte + x];
		}
	}
    return pBmpBuf;
}

unsigned char * basicOperation::bmpPerspect_10(unsigned char * bmp, int width, int height, int linebyte) {

    pBmpBuf = new unsigned char[height*linebyte];
    std::cout << width << "," << height << std::endl;
    int target = 700;
    // PerspectiveTransform tansform = PerspectiveTransform::quadrilateralToQuadrilateral(
	// 	0, 0,
	// 	width-1 + target, -target,
	// 	0, height-1,
	// 	width-1 + target, height+target,
    //     0, 0,
	// 	width-1, 0,
	// 	0, height-1,
	// 	width-1, height-10);

    // 522,442
    // PerspectiveTransform tansform =  PerspectiveTransform::quadrilateralToQuadrilateral(
	// 	0, 0,
	// 	width-1 + target, -target,
	// 	0, height-1,
	// 	width-1 + target, height+target,

    //     0, 0,
	// 	width-1, 0,
	// 	0, height-1,
	// 	width-1, height-1);
    
    PerspectiveTransform tansform =  PerspectiveTransform::quadrilateralToQuadrilateral(
		-600, -300,
        2100, -750,
		-600, 800,
		2100, 2000,
        0, 0,
		width-1, 0,
		0, height-1,
		width-1, height-1);

    // //p3   p4
    // //p1   p2
    // int w = 522;
	// int h = 442;
	// int p1[2] = {442 - 314, 260};
	// int p2[2] = {442 - 285, 360};
	// int p3[2] = {442 - 286, 250};
	// int p4[2] = {442 - 258, 354};
    //     // h - 314, 260,
    //     // h - 285, 360,
    //     // h - 286, 250,
    //     // h - 258, 354

    // PerspectiveTransform tansform =  PerspectiveTransform::quadrilateralToQuadrilateral(
    //     0, 0,
	// 	w-1, 0,
	// 	0, h-1,
	// 	w-1, h-1,

    //     0, 0,
    //     h - 285, 360,
    //     h - 286, 250,
    //     w-1, h-1
    // );
    
    vector<float> ponits;
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			ponits.push_back(j);
			ponits.push_back(i);
		}
	}

	tansform.transformPoints(ponits);

    for(int i=0;i< height;i++) {
		// uchar*  t= img_trans.ptr<uchar>(i);
		for (int j = 0; j < width; j++){
			int tmp = i * width + j;
			int x = ponits[tmp * 2];
			int y = ponits[tmp * 2 + 1];
			if(x < 0 || x > (width - 1) || y < 0 || y > (height - 1))
				continue;

            pBmpBuf[i * linebyte + j] = bmp[y * linebyte + x];
		}
	}
    return pBmpBuf;
}

