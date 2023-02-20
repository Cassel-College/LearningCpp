#include <opencv2/core/core.hpp> 
#include <opencv2/highgui/highgui.hpp>   

using namespace cv;// 省去函数前面加cv::的必要性

int main()
{
    char imageName[] = "/home/Code/github/paly.png";   
    Mat M = imread(imageName, IMREAD_COLOR);   // 读入图片 
         
    if(M.empty())     // 判断文件是否正常打开  
    {
         fprintf(stderr, "Can not load image %s\n", imageName);
         waitKey(6000);  // 等待6000 ms后窗口自动关闭   
         return -1;
    }
    
    // imshow("image",M);  // 显示图片 
    waitKey();
    imwrite("/home/Code/github/paly.bmp",M); // 存为bmp格式图片
    
    return 0;
}
