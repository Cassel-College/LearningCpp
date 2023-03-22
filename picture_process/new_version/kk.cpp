#include <iostream>
#include <fstream>

using namespace std;

int main()
{
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
    int image_width = *(int*)&header[18];
    int image_height = *(int*)&header[22];
    // const int image_width = 640; // 假设原始图像宽度为640像素
    // const int image_height = 480; // 假设原始图像高度为480像素

    unsigned char* image_data = new unsigned char[image_width * image_height * 3]; // 申请原始图像像素数据存储空间
    // 读取原始图像像素数据，这里省略读取过程
    int imageSize = *(int*)&header[34];
    bmpFile.read((char*)image_data, imageSize);

    // 申请3个unsigned char类型的数组分别存储RGB三个分量的像素数据
    unsigned char* red_data = new unsigned char[image_width * image_height];
    unsigned char* green_data = new unsigned char[image_width * image_height];
    unsigned char* blue_data = new unsigned char[image_width * image_height];

    // 将原始图像的RGB三个分量分离出来存储到相应的数组中
    for (int y = 0; y < image_height; y++) {
        for (int x = 0; x < image_width; x++) {
            int index = (y * image_width + x) * 3; // 计算像素在原始图像数据中的下标
            red_data[y * image_width + x] = image_data[index]; // 提取R分量
            green_data[y * image_width + x] = image_data[index + 1]; // 提取G分量
            blue_data[y * image_width + x] = image_data[index + 2]; // 提取B分量
        }
    }

    // 将RGB三个分量的像素数据分别写入三个灰度图像文件中
    ofstream red_file("red_image.pgm", ios::binary);
    ofstream green_file("green_image.pgm", ios::binary);
    ofstream blue_file("blue_image.pgm", ios::binary);

    // 写入PGM文件头
    red_file << "P5" << endl << image_width << " " << image_height << endl << "255" << endl;
    green_file << "P5" << endl << image_width << " " << image_height << endl << "255" << endl;
    blue_file << "P5" << endl << image_width << " " << image_height << endl << "255" << endl;

    // 写入像素数据
    red_file.write(reinterpret_cast<const char*>(red_data), image_width * image_height);
    green_file.write(reinterpret_cast<const char*>(green_data), image_width * image_height);
    blue_file.write(reinterpret_cast<const char*>(blue_data), image_width * image_height);

    // 释放申请的内存空间
    delete[] image_data;
    delete[] red_data;
    delete[] green_data;
    delete[] blue_data;

    return 0;
}
