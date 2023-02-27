//
// Created by peng liu on 2/25/23.
//

#ifndef PICTUREPROCESS_BASICOPERATION_H
#define PICTUREPROCESS_BASICOPERATION_H


#include "stdlib.h"
#include "stdio.h"

class basicOperation
{
public:
    unsigned char *pBmpBuf;
    int i, j;

    unsigned char * bmpScale(unsigned char * bmp, int width, int height, int linebyte, float times1, float times2);
    unsigned char * bmpMove(unsigned char * bmp, int width, int height, int linebyte, int x, int y);
    unsigned char * bmpRotate(unsigned char * bmp, int width, int height, int linebyte, double angle);
    unsigned char * bmpMirroring(unsigned char * bmp, int width, int height, int linebyte, int flag);
};

#endif //PICTUREPROCESS_BASICOPERATION_H
