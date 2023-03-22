from PIL import Image

# 读取原始BMP图像
img = Image.open('image1.bmp')

# 获取图像宽度、高度和像素点RGB值
width, height = img.size
pixels = img.load()

# 创建新的灰度图像
r_img = Image.new('L', (width, height))
g_img = Image.new('L', (width, height))
b_img = Image.new('L', (width, height))

r_pixels = r_img.load()
g_pixels = g_img.load()
b_pixels = b_img.load()

# 分离R、G、B三个分量并保存到新的灰度图像中
for y in range(height):
    for x in range(width):
        r, g, b = pixels[x, y]
        r_pixels[x, y] = r
        g_pixels[x, y] = g
        b_pixels[x, y] = b

# 保存分离后的灰度图像为BMP文件
r_img.save('r.bmp')
g_img.save('g.bmp')
b_img.save('b.bmp')
