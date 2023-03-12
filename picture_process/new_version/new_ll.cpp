#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // 打开24位BMP图像文件
    ifstream bmpFile("/home/Code/github/LearningCpp/picture_process//bitmaps/image1.bmp", ios::binary);
    if (!bmpFile.is_open())
    {
        cout << "Failed to open file" << endl;
        return 1;
    }

    // 读取BMP文件头信息
    char header[54];
    bmpFile.read(header, 54);

    // 读取像素数据
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    
    int pixelSize = *(int*)&header[28];
    int imageSize = *(int*)&header[34];
    unsigned char* pixelData = new unsigned char[imageSize];
    bmpFile.read((char*)pixelData, imageSize);

    // 创建三个灰度图像文件
    FILE* fileR = fopen("red.bmp", "wb");
    FILE* fileG = fopen("green.bmp", "wb");
    FILE* fileB = fopen("blue.bmp", "wb");

    // 写入BMP文件头信息
    fwrite(header, 1, 54, fileR);
    fwrite(header, 1, 54, fileG);
    fwrite(header, 1, 54, fileB);

    // 写入像素数据
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int index = (y * width + x) * pixelSize;

            // 分离R，G和B三个分量
            unsigned char r = pixelData[index + 2];
            unsigned char g = pixelData[index + 1];
            unsigned char b = pixelData[index];

            // 写入R分量灰度图像
        unsigned char gray = (r + g + b) / 3;
        fwrite(&gray, 1, 1, fileR);

        // 写入G分量灰度图像
        gray = (r + g + b) / 3;
        fwrite(&gray, 1, 1, fileG);

        // 写入B分量灰度图像
        gray = (r + g + b) / 3;
        fwrite(&gray, 1, 1, fileB);
    }
}

// 关闭文件
fclose(fileR);
fclose(fileG);
fclose(fileB);
bmpFile.close();

// 释放内存
delete[] pixelData;

return 0;
}

// css
// Copy code

// 注意，这里将R，G和B分量分别写入了三个不同的灰度图像文件中，因此最终产生了三幅8位灰度图像。如果需要将三个分量合并为一幅24位BMP图像，只需要将它们重新合并到像素数据中，然后写入BMP文件即可。





