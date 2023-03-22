#include <iostream>
#include <fstream>
#include <vector>
#include "stdlib.h"
#include "stdio.h"
#include <cstdlib> 
#include <string>
#include <map>
#include <algorithm>
#include "pub.h"
#include "read_write_bmp.h"
#include "splitBmp.h"
#include <cstring>

using namespace std;

void ShowInfo(const std::string &info) {
    std::cout << info << std::endl;
}

void __inline__ ShowUserInformation(const std::vector<std::string> &infos) {
    for (auto item : infos) {
        ShowInfo(item);
    }
}

std::string get_root_path() {
    return "/home/Code/github/LearningCpp/picture_process";
}

std::string get_path(const std::string &path_name) {
    std::string path = "";
    std::map<std::string, std::string> myMap;
    myMap.insert(std::make_pair("welcome_sweet_system", "/config/welcome_sweet_system.txt"));
    myMap.insert(std::make_pair("user_interface", "/config/user_interface.txt"));
    myMap.insert(std::make_pair("shutdown_system", "/config/shutdown_system.txt"));
    myMap.insert(std::make_pair("clean_terminal", "/config/clean_terminal.txt"));
    myMap.insert(std::make_pair("user_input", "/config/user_input.txt"));
    myMap.insert(std::make_pair("function_run_over", "/config/function_run_over.txt"));
    myMap.insert(std::make_pair("line", "/config/line.txt"));
    myMap.insert(std::make_pair("inner_line", "/config/inner_line.txt"));
    myMap.insert(std::make_pair("not_dev", "/config/not_dev.txt"));
    myMap.insert(std::make_pair("no_task", "/config/homework/no_task.txt"));
    myMap.insert(std::make_pair("task_001", "/config/homework/task_001.txt"));
    myMap.insert(std::make_pair("task_002", "/config/homework/task_002.txt"));
    myMap.insert(std::make_pair("task_003", "/config/homework/task_003.txt"));
    myMap.insert(std::make_pair("task_004", "/config/homework/task_004.txt"));
    myMap.insert(std::make_pair("task_005", "/config/homework/task_005.txt"));
    myMap.insert(std::make_pair("task_006", "/config/homework/task_006.txt"));
    myMap.insert(std::make_pair("task_007", "/config/homework/task_007.txt"));
    myMap.insert(std::make_pair("task_008", "/config/homework/task_008.txt"));
    myMap.insert(std::make_pair("task_009", "/config/homework/task_009.txt"));
    myMap.insert(std::make_pair("task_010", "/config/homework/task_010.txt"));
    myMap.insert(std::make_pair("split_red_picture", "/config/info/split_red_picture.txt"));
    myMap.insert(std::make_pair("split_green_picture", "/config/info/split_green_picture.txt"));
    myMap.insert(std::make_pair("split_blue_picture", "/config/info/split_blue_picture.txt"));
    if (myMap.count(path_name) == 0) {
        std::cout << "Element with key " << path_name << " not found\n";
    } else {
        path = get_root_path() + "/" + myMap.find(path_name)->second;
    }
    return path;
}

std::vector<std::string> read_config_file(const std::string &file_path) {
    std::ifstream file(file_path);
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    file.close();
    return lines;
}

void init() {
    ShowUserInformation(read_config_file(get_path("user_interface")));
}

const char * read_bmp_1 = "/home/Code/github/LearningCpp/picture_process/bitmaps/image1.bmp";
const char * write_bmp_red = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageR.bmp";
const char * write_bmp_gray = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageGery.bmp";
const char * write_bmp_gray_red = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageGeryRed.bmp";
const char * write_bmp_gray_blue = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageGeryBlue.bmp";
const char * write_bmp_gray_green = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageGeryGreen.bmp";
const char * write_bmp_green = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageG.bmp";
const char * write_bmp_blue = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageB.bmp";
const char * write_bmp_alter = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageGeryAlter.bmp";
const char * read_bmp_1_ggggggggg = "/home/Code/github/LearningCpp/picture_process/bitmaps/imagegggggg.bmp";

Bmp in_bmp, out_bmp;
BmpOperation bmpOperation;
SplitBmp splitBmp;


Bmp init_colortable(Bmp bmp)
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

//24位图r,g,b三个分量分离
void split24(const char *read_bmp, const char *write_bmp_red, const char *write_bmp_green, const char *write_bmp_blue)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.biBitCount = 24;

	out_bmp.pBmpBuf = splitBmp.init_rgb(in_bmp.pBmpBuf, in_bmp.height, in_bmp.width, in_bmp.lineByte).red;
    ShowUserInformation(read_config_file(get_path("split_red_picture")));
	bmpOperation.writeBmp(out_bmp, write_bmp_red);

	out_bmp.pBmpBuf = splitBmp.init_rgb(in_bmp.pBmpBuf, in_bmp.height, in_bmp.width, in_bmp.lineByte).green;
    ShowUserInformation(read_config_file(get_path("split_green_picture")));
	bmpOperation.writeBmp(out_bmp, write_bmp_green);

	out_bmp.pBmpBuf = splitBmp.init_rgb(in_bmp.pBmpBuf, in_bmp.height, in_bmp.width, in_bmp.lineByte).blue;
    ShowUserInformation(read_config_file(get_path("split_blue_picture")));
	bmpOperation.writeBmp(out_bmp, write_bmp_blue);

	cout << "分离RGB成功！" << endl;
}

//将24位图变成灰度图
void change24to8(const char *read_bmp, const char *write_bmp)
{
    cout << "开始读取24位图 ..." << endl;
    // 读取图片
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;

	out_bmp.biBitCount = 8;

    // bmpWidth是位图的宽度，也就是每行有多少个像素块
    // 8：8位图像
    // 8：位数÷8即为每个像元占用字节数，bmpwidth*位数/8为有效字节数，在此基础上填充0
    // 3: 补齐 存储图像数据每行字节数为4的倍数，所以+3是怕出现不满足4的倍数这种情况
    // 4: BMP图片扫描引擎的最小单位是4字节，遵循4的整倍数
    // 目的： 用来计算8位图每行占多少个字节
	out_bmp.lineByte = (out_bmp.width * 8 / 8 + 3) / 4 * 4;

	out_bmp = init_colortable(out_bmp);

	out_bmp.pBmpBuf = splitBmp.init_gray(in_bmp.pBmpBuf, in_bmp.height, in_bmp.width, out_bmp.lineByte, in_bmp.lineByte);
    // 
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "成功转为8位灰度图" << endl;
}



//将24位图变成灰度图
void change24to8_to_b(const char *read_bmp, const char *write_bmp)
{
    cout << "开始读取24位图 ..." << endl;
    // 读取图片
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
    // splitBmp.rgb24_to_grey8("/home/Code/github/LearningCpp/picture_process/bitmaps/image1.bmp", in_bmp.pBmpBuf);
	out_bmp.biBitCount = 8;
	out_bmp.lineByte = (out_bmp.width * 8 / 8 + 3) / 4 * 4;
	out_bmp = init_colortable(out_bmp);
	out_bmp.pBmpBuf = splitBmp.get_bgr_of_b(in_bmp.pBmpBuf, in_bmp.height, in_bmp.width, out_bmp.lineByte, in_bmp.lineByte);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "成功转为8位灰度图-B" << endl;
}

void change24to8_to_g(const char *read_bmp, const char *write_bmp)
{
    cout << "开始读取24位图 ..." << endl;
    // 读取图片
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.biBitCount = 8;
	out_bmp.lineByte = (out_bmp.width * 8 / 8 + 3) / 4 * 4;
	out_bmp = init_colortable(out_bmp);
	out_bmp.pBmpBuf = splitBmp.get_bgr_of_g(in_bmp.pBmpBuf, in_bmp.height, in_bmp.width, out_bmp.lineByte, in_bmp.lineByte);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "成功转为8位灰度图-B" << endl;
}
void change24to8_to_r(const char *read_bmp, const char *write_bmp)
{
    cout << "开始读取24位图 ..." << endl;
    // 读取图片
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.biBitCount = 8;
	out_bmp.lineByte = (out_bmp.width * 8 / 8 + 3) / 4 * 4;
	out_bmp = init_colortable(out_bmp);
	out_bmp.pBmpBuf = splitBmp.get_bgr_of_r(in_bmp.pBmpBuf, in_bmp.height, in_bmp.width, out_bmp.lineByte, in_bmp.lineByte);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "成功转为8位灰度图-B" << endl;
}


void change24to24_gray(const char *read_bmp, const char *write_bmp)
{
    cout << "开始读取24位图 ..." << endl;
    // 读取图片
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;

	out_bmp.biBitCount = 24;

    // // bmpWidth是位图的宽度，也就是每行有多少个像素块
    // // 8：8位图像
    // // 8：位数÷8即为每个像元占用字节数，bmpwidth*位数/8为有效字节数，在此基础上填充0
    // // 3: 补齐 存储图像数据每行字节数为4的倍数，所以+3是怕出现不满足4的倍数这种情况
    // // 4: BMP图片扫描引擎的最小单位是4字节，遵循4的整倍数
    // // 目的： 用来计算8位图每行占多少个字节
	// out_bmp.lineByte = (out_bmp.width * 8 / 8 + 3) / 4 * 4;

	out_bmp = init_colortable(out_bmp);

	out_bmp.pBmpBuf = splitBmp.init_gray_24_to_24(in_bmp.pBmpBuf, in_bmp.height, in_bmp.width, out_bmp.lineByte, in_bmp.lineByte);
    // 
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "成功转为24位灰度图" << endl;
}

//8位图反色
void reverse8(const char *read_bmp, const char *write_bmp)
{
    cout << "开始读取8位图 ..." << endl;
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = splitBmp.init_opposite_gray(in_bmp.pBmpBuf, in_bmp.height, in_bmp.width, in_bmp.lineByte);
	out_bmp = init_colortable(out_bmp);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "成功反色8位灰度图" << endl;
}

std::string get_task_name(const std::string &input_id) {
    std::string task_name  = "";
    if (input_id == "1") {
        task_name = "task_001";
    } else if (input_id == "2") {
        task_name = "task_002";
    } else if (input_id == "3") {
        task_name = "task_003";
    } else if (input_id == "4") {
        task_name = "task_004";
    } else if (input_id == "5") {
        task_name = "task_005";
    } else if (input_id == "6") {
        task_name = "task_006";
    } else if (input_id == "7") {
        task_name = "task_007";
    } else if (input_id == "8") {
        task_name = "task_008";
    } else if (input_id == "9") {
        task_name = "task_009";
    } else if (input_id == "10") {
        task_name = "task_010";
    }
    return task_name;
}

void ShowTaskInfo(const std::string &func_id) {
    ShowUserInformation(read_config_file(get_path("line")));
    ShowUserInformation(read_config_file(get_path(get_task_name(func_id))));
    ShowUserInformation(read_config_file(get_path("line")));
}

void ExecTask001() {

    // 24位彩色图像转换为8位灰度图
    change24to8(read_bmp_1, write_bmp_gray);
    // change24to24_gray(read_bmp_1, read_bmp_1_ggggggggg);
    // 终端注释
    ShowUserInformation(read_config_file(get_path("inner_line")));
    reverse8(write_bmp_gray, write_bmp_alter);
    // 终端注释
    ShowUserInformation(read_config_file(get_path("inner_line")));
    // 分解 read_bmp_1 按不同的RGB 到 write_bmp_red, write_bmp_green, write_bmp_blue
    split24(read_bmp_1, write_bmp_red, write_bmp_green, write_bmp_blue);
    // split24(read_bmp_1_ggggggggg, write_bmp_red, write_bmp_green, write_bmp_blue);
    std::cout << "11" << std::endl;
    // 24位彩色图像转换为8位灰度图
    // change24to8(write_bmp_red, write_bmp_gray_red);
    // change24to8(write_bmp_green, write_bmp_gray_green);
    // change24to8(write_bmp_blue, write_bmp_gray_blue);

    change24to8_to_b(read_bmp_1, write_bmp_gray_blue);
    change24to8_to_g(read_bmp_1, write_bmp_gray_green);
    change24to8_to_r(read_bmp_1, write_bmp_gray_red);

    
}

int main()
{
    ExecTask001();
}