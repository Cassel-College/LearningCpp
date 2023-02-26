#include <iostream>
#include <fstream>
#include "stdlib.h"
#include "stdio.h"
#include <cstdlib> 
#include <string>
#include <map>
#include <algorithm>
#include "pub.h"
#include "splitBmp.h"
#include "histogramEqualize.h"
#include "spatialFilter.h"
#include "basicOperation.h"
#include "threshold.h"
#include "regionGrowing.h"
#include "edgeDetection.h"
#include "HoughTransform.h"
#include "outlineExtraction.h"
#include "read_write_bmp.h"
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
const char * read_bmp_2 = "/home/Code/github/LearningCpp/picture_process/bitmaps/image2.bmp";
const char * read_bmp_3 = "/home/Code/github/LearningCpp/picture_process/bitmaps/image3.bmp";
const char * read_bmp_4 = "/home/Code/github/LearningCpp/picture_process/bitmaps/image4.bmp";
const char * read_bmp_5 = "/home/Code/github/LearningCpp/picture_process/bitmaps/image5.bmp";
const char * write_bmp_red = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageR.bmp";
const char * write_bmp_gray = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageGery.bmp";
const char * write_bmp_green = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageG.bmp";
const char * write_bmp_blue = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageB.bmp";
const char * write_bmp_alter = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageGeryAlter.bmp";
const char * write_bmp_equalize = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageEqualize.bmp";
const char * write_bmp_histogram= "/home/Code/github/LearningCpp/picture_process/bitmaps/imageHistogram.bmp";
const char * write_bmp_histoEqualize = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageHistoEqualize.bmp";
const char * write_bmp_ab = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageAverageWithBorder.bmp";
const char * write_bmp_aob = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageAverageWithoutBorder.bmp";
const char * write_bmp_mb = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageMedianWithBorder.bmp";
const char * write_bmp_mob = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageMedianWithoutBorder.bmp";
const char * write_bmp_mirroring = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageMirroring.bmp";
const char * write_bmp_rotate = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageRotate.bmp";
const char * write_bmp_move = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageMove.bmp";
const char * write_bmp_scale = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageScale.bmp";
const char * write_bmp_givenT = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageGivenT.bmp";
const char * write_bmp_iteration = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageIteration.bmp";
const char * write_bmp_otsu = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageOtsu.bmp";
const char * write_bmp_gs = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageRegionGrowingWS.bmp";
const char * write_bmp_gws = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageRegionGrowingWOS.bmp";
const char * write_bmp_prewitt = "/home/Code/github/LearningCpp/picture_process/bitmaps/imagePrewitt.bmp";
const char * write_bmp_sobel = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageSobel.bmp";
const char * write_bmp_LOG = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageLOG.bmp";
const char * write_bmp_hough = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageLineDetection.bmp";
const char * write_bmp_regionMark = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageRegionMark.bmp";
const char * write_bmp_outline = "/home/Code/github/LearningCpp/picture_process/bitmaps/imageOutlineExtraction.bmp";

Bmp in_bmp, out_bmp;
BmpOperation bmpOperation;
SplitBmp splitBmp;
basicOperation basic;
edgeDetection edge;
HistogramEqualize histogram;
HoughTransform hough;
outlineExtraction outline;
regionGrowing region;
spatialFiltering spatial;
threshold thres;


Bmp init_colortable(Bmp bmp)
{
	int i;
	bmp.pColorTable = (RGBQUAD*)malloc(256 * sizeof(RGBQUAD));
	memset(bmp.pColorTable, 0, 256 * sizeof(RGBQUAD));
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
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.biBitCount = 8;
	out_bmp.lineByte = (out_bmp.width * 8 / 8 + 3) / 4 * 4;
	out_bmp = init_colortable(out_bmp);
	out_bmp.pBmpBuf = splitBmp.init_gray(in_bmp.pBmpBuf, in_bmp.height, in_bmp.width, out_bmp.lineByte, in_bmp.lineByte);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "成功转为8位灰度图" << endl;
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

//直方图均衡化
void equalize(const char *read_bmp, const char *write_bmp_equalize, const char *write_bmp_histoequalize)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = histogram.equalization(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte);
	out_bmp = init_colortable(out_bmp);
	bmpOperation.writeBmp(out_bmp, write_bmp_equalize);
	cout << "均衡化成功！" << endl;
	in_bmp = bmpOperation.readBmp(write_bmp_equalize);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = histogram.saveHistogram(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte);
	out_bmp = init_colortable(out_bmp);
	out_bmp.height = 1000;
	out_bmp.width = 512;
	bmpOperation.writeBmp(out_bmp, write_bmp_histoequalize);
	cout << "生成均衡化后的直方图" << endl;
}

//绘制直方图
void paintHistogram(const char *read_bmp, const char *write_bmp_histogram)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = histogram.saveHistogram(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte);
	out_bmp = init_colortable(out_bmp);
	out_bmp.height = 1000;
	out_bmp.width = 512;
	bmpOperation.writeBmp(out_bmp, write_bmp_histogram);
	cout << "生成直方图" << write_bmp_histogram << endl;
}

//均值滤波_无边界
void averageWithoutBorder(const char *read_bmp, const char *write_bmp)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = spatial.average_without_border(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte);
	out_bmp = init_colortable(out_bmp);//可能不需要再次初始化调色板
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "均值滤波_无边界 完成" << endl;
}

//均值滤波_有边界
void averageWithBorder(const char *read_bmp, const char *write_bmp)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = spatial.average_with_border(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte);
	out_bmp = init_colortable(out_bmp);//可能不需要再次初始化调色板
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "均值滤波_有边界 完成" << endl;
}

//中值滤波_无边界
void medianWithoutBorder(const char *read_bmp, const char *write_bmp)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = spatial.median_without_border(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte);
	out_bmp = init_colortable(out_bmp);//可能不需要再次初始化调色板
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "中值滤波_无边界 完成" << endl;
}

//中值滤波_有边界
void medianWithBorder(const char *read_bmp, const char *write_bmp)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = spatial.median_with_border(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte);
	out_bmp = init_colortable(out_bmp);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "中值滤波_有边界 完成" << endl;
}

//镜像
void mirroing(const char *read_bmp, const char *write_bmp, int flag)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = basic.bmpMirroring(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte, flag);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "图像镜像 完成" << endl;
}

//旋转
void rotate(const char *read_bmp, const char *write_bmp, int angle)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = basic.bmpRotate(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte, angle);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "图像旋转 完成" << endl;
}

//平移
void move(const char *read_bmp, const char *write_bmp, int x, int y)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = basic.bmpMove(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte, x, y);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "图像平移 完成" << endl;
}

//放缩
void scale(const char *read_bmp, const char *write_bmp, float times1, float times2)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = basic.bmpScale(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte, times1, times2);
	out_bmp.width = out_bmp.width * times1;
	out_bmp.height = out_bmp.height * times2;
	out_bmp.lineByte = (out_bmp.width * 8 / 8 + 3) / 4 * 4;
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "图像放缩 完成" << endl;
}

//给定阈值分割
void thresholdByGivenT(const char *read_bmp, const char *write_bmp, int T)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = thres.givenT(T, in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "给定阈值分割 完成" << endl;
}

//迭代阈值分割
void thresholdByIteration(const char *read_bmp, const char *write_bmp)
{
	int T;
	in_bmp = bmpOperation.readBmp(read_bmp);
	T = thres.iterationT(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte);
	cout << "迭代出的阈值为：" << T << endl;
	out_bmp.pBmpBuf = thres.givenT(T, in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "迭代阈值分割 完成" << endl;
}

//Otsu阈值分割
void thresholdByOtsu(const char *read_bmp, const char *write_bmp)
{
	int T;
	in_bmp = bmpOperation.readBmp(read_bmp);
	T = thres.OtsuT(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte);
	cout << "Otsu算法得出的阈值为：" << T << endl;
	out_bmp.pBmpBuf = thres.givenT(T, in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "Otsu阈值分割 完成" << endl;
}

//区域生长
void regionGrowingWithSeed(const char *read_bmp, const char *write_bmp, POINT seed, int speed)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = region.growwWithSeed(seed, in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte, speed);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "区域生长 完成" << endl;
}

//区域分裂
void regionGrowingWithoutSeed(const char *read_bmp, const char *write_bmp)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = region.growWithoutSeed(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "区域分裂 完成" << endl;
}

//边缘检测Prewitt
void prewitt(const char *read_bmp, const char *write_bmp)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = edge.Prewitt(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "边缘检测Prewitt 完成" << endl;
}

//边缘检测Sobel
void Sobel(const char *read_bmp, const char *write_bmp)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = edge.Sobel(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "边缘检测Sobel 完成" << endl;
}

//LOG
void LOG(const char *read_bmp, const char *write_bmp)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = edge.LOG(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte);
	bmpOperation.writeBmp(out_bmp, write_bmp); 
	cout << "边缘检测LOG 完成" << endl;
}

//Hough变换 需事先知道直线数量
void Hough(const char *read_bmp, const char *write_bmp, int number)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = hough.lineDetection(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte, number);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "Hough变换 完成" << endl;
}

//区域标记与轮廓提取
void regionMark(const char *read_bmp, const char *write_bmp)
{
	int label;
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = outline.regionMark(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "区域标记 完成" << endl;
}

//轮廓提取
void extractOutline(const char *read_bmp, const char *write_bmp)
{
	in_bmp = bmpOperation.readBmp(read_bmp);
	out_bmp = in_bmp;
	out_bmp.pBmpBuf = outline.extractOutline(in_bmp.pBmpBuf, in_bmp.width, in_bmp.height, in_bmp.lineByte);
	bmpOperation.writeBmp(out_bmp, write_bmp);
	cout << "轮廓提取 完成" << endl;
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
    change24to8(read_bmp_1, write_bmp_gray);
    ShowUserInformation(read_config_file(get_path("inner_line")));
    reverse8(write_bmp_gray, write_bmp_alter);
    ShowUserInformation(read_config_file(get_path("inner_line")));
    split24(read_bmp_1, write_bmp_red, write_bmp_green, write_bmp_blue);
}

void ExecTask002() {
    paintHistogram(write_bmp_gray, write_bmp_histogram);
    ShowUserInformation(read_config_file(get_path("inner_line")));
	equalize(write_bmp_gray, write_bmp_equalize, write_bmp_histoEqualize);
}

void ExecTask003() {
    averageWithBorder(read_bmp_2, write_bmp_ab);
    ShowUserInformation(read_config_file(get_path("inner_line")));
	averageWithoutBorder(read_bmp_2, write_bmp_aob);
    ShowUserInformation(read_config_file(get_path("inner_line")));
	medianWithBorder(read_bmp_2, write_bmp_mb);
    ShowUserInformation(read_config_file(get_path("inner_line")));
	medianWithoutBorder(read_bmp_2, write_bmp_mob);
}

void ExecTask004() {
    scale(write_bmp_gray, write_bmp_scale, 2.0f, 0.5f);
    ShowUserInformation(read_config_file(get_path("inner_line")));
	move(write_bmp_gray, write_bmp_move, 100, 100);
    ShowUserInformation(read_config_file(get_path("inner_line")));
    mirroing(write_bmp_gray, write_bmp_mirroring, 1);
    ShowUserInformation(read_config_file(get_path("inner_line")));
	rotate(write_bmp_gray, write_bmp_rotate, 30);
//	std::cout << "透视变换 not dev" << std::endl;
}

void ExecTask005() {
    thresholdByGivenT(write_bmp_gray, write_bmp_givenT, 128);
    ShowUserInformation(read_config_file(get_path("inner_line")));
	thresholdByIteration(write_bmp_gray, write_bmp_iteration);
    ShowUserInformation(read_config_file(get_path("inner_line")));
	thresholdByOtsu(write_bmp_gray, write_bmp_otsu);
}

void ExecTask006() {
    POINT seed;
    seed.x = 91;
    seed.y = 45;
    regionGrowingWithSeed(write_bmp_gray, write_bmp_gs, seed, 5);
    ShowUserInformation(read_config_file(get_path("inner_line")));
    regionGrowingWithoutSeed(write_bmp_gray, write_bmp_gws);
}

void ExecTask007() {
    Hough(read_bmp_3, write_bmp_hough, 5);
}

void ExecTask008() {
    regionMark(read_bmp_4, write_bmp_regionMark);
    extractOutline(read_bmp_4, write_bmp_outline);
}

void ExecTask009() {
    prewitt(write_bmp_gray, write_bmp_prewitt);
    Sobel(write_bmp_gray, write_bmp_sobel);
    LOG(write_bmp_gray, write_bmp_LOG);
}

void ExecTask010() {
    ShowUserInformation(read_config_file(get_path("not_dev")));
}

void ExecTesk(const std::string &func_id) {
    ShowTaskInfo(func_id);
    if (func_id == "1") {
        ExecTask001();
    } else if (func_id == "2") {
        ExecTask002();
    } else if (func_id == "3") {
        ExecTask003();
    } else if (func_id == "4") {
        ExecTask004();
    } else if (func_id == "5") {
        ExecTask005();
    } else if (func_id == "6") {
        ExecTask006();
    } else if (func_id == "7") {
        ExecTask007();
    } else if (func_id == "8") {
        ExecTask008();
    } else if (func_id == "9") {
        ExecTask009();
    } else if (func_id == "10") {
        ExecTask010();
    }
    ShowUserInformation(read_config_file(get_path("function_run_over")));
}


void SweetSystem() {
    ShowUserInformation(read_config_file(get_path("welcome_sweet_system")));
    std::string has_next_command = "y";
    transform(has_next_command.begin(),has_next_command.end(),has_next_command.begin(),::toupper);
    while(has_next_command == "Y" || has_next_command == "YES") {
        ShowUserInformation(read_config_file(get_path("user_interface")));
        ShowUserInformation(read_config_file(get_path("user_input")));
        std::string func_id = "1";
        std::cin >> func_id;
        std::string task_name = get_task_name(func_id);
        if (task_name == "") {
            ShowUserInformation(read_config_file(get_path("no_task")));
            continue;
        }
        ExecTesk(func_id);
        std::cin >> has_next_command;
        transform(has_next_command.begin(),has_next_command.end(),has_next_command.begin(),::toupper);
        if (has_next_command == "Y" || has_next_command == "YES") {
            ShowUserInformation(read_config_file(get_path("clean_terminal")));
        }
    }
    ShowUserInformation(read_config_file(get_path("shutdown_system")));
}

int main()
{
    SweetSystem();
}