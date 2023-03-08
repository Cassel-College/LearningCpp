import cv2
import matplotlib.pyplot as plt
'''
彩色图像转化为RGB三幅灰度图像
'''
def main():
  img='/home/Code/github/LearningCpp/picture_process/bitmaps/image1.bmp'
  im=cv2.imread(img)
  B,G,R=cv2.split(im)

  #结果展示
#   plt.rcParams['font.sans-serif'] = ['SimHei']  # 中文乱码
  #子图1，原始图像
  plt.subplot(141)
  #plt默认使用三通道显示图像，所以需要制定cmap参数为gray
  #imshow()对图像进行处理，画出图像，show()进行图像显示
  #opencv的颜色通道顺序为[B,G,R]，而matplotlib颜色通道顺序为[R,G,B],所以需要调换一下通道位置
  plt.imshow(im[:,:,(2,1,0)])
  plt.title('原图像')
  
  #不显示坐标轴
  plt.axis('off')
  #子图2，通道R灰度图像
  plt.subplot(142)
  plt.imshow(R,cmap='gray')
  print(type(R))
  print(R.size)
  plt.title('通道R')
  plt.axis('off')
  print("channel[R]")
  print(im[:, :, 2])
  plt.savefig('./testR.jpg')

  #子图3，通道G
  plt.subplot(143)
  plt.imshow(G,cmap='gray')
  plt.title('通道G')
  plt.axis('off')
  plt.savefig('./testG.jpg')
  print("channel[G]")
  print(im[:, :, 1])

  #子图4，B
  plt.subplot(144)
  plt.imshow(B,cmap='gray')
#   plt.imshow(B)
  plt.title('通道B')
  plt.axis('off')
  print("channel[B]")
  print(im[:, :, 0])
  plt.savefig('./testB.jpg')
  plt.show()


if __name__== '__main__':
  main()