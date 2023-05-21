#include "regionGrowing.h"

unsigned char * regionGrowing::growwWithSeed(POINT ptGrowing, unsigned char * bmp, int width, int height, int linebyte, int speed)
{
	unsigned char * pBmpBuf = new unsigned char[height*linebyte]{ 0 };
	int* tab = new int[height*linebyte]{ 0 };
	pt.push_back(ptGrowing);
	while (!pt.empty())
	{
		POINT currPt = pt.back();
		pt.pop_back();
		origin.x = currPt.x;
		origin.y = currPt.y;
		for ( i = 0; i < 8; i++)
		{
			ptGrowing.x = currPt.x + dir[i][0];
			ptGrowing.y = currPt.y + dir[i][1];
			if (ptGrowing.x < 0 || ptGrowing.y<0 || ptGrowing.x > width - 1 || ptGrowing.y>height - 1)
				continue;
			if (tab[ptGrowing.y * linebyte + ptGrowing.x] == 0)
			{
				
				if (bmp[ptGrowing.y * linebyte + ptGrowing.x] - bmp[origin.y * linebyte + origin.x] <= speed && bmp[ptGrowing.y * linebyte + ptGrowing.x] - bmp[origin.y * linebyte + origin.x] >= -speed)
				{
					pt.push_back(ptGrowing);
					tab[ptGrowing.y * linebyte + ptGrowing.x] = 1;
					pBmpBuf[ptGrowing.y * linebyte + ptGrowing.x] = 255;
				}
			}
		}
	}
	return pBmpBuf;
}




unsigned char * regionGrowing::growWithoutSeed(unsigned char * bmp, int width, int height, int linebyte)
{
	unsigned char * pBmpBuf = new unsigned char[height*linebyte]{ 0 };
	//int* judge = new int[height*linebyte]{ 0 };
	//std::vector<subImage>sub;
	//subImage si;
	//POINT n, m;
	//n.x = 0;
	//n.y = 0;
	//m.x = width;
	//m.y = height;
	//si.left_bottom = n;
	//si.right_top = m;
	//sub.push_back(si);
	//while (!sub.empty())
	//{
	//	POINT a, b;
	//	si = sub.back();
	//	sub.pop_back();
	//	m = si.right_top;
	//	n = si.left_bottom;
	//	int max = 0, min = 256, length;
	//	int value[2][2]{ 0 };// 区域分裂 记录灰度值
	//	//求出四个区域的平均灰度值
	//	length = (m.y - n.y) / 2;
	//	for (int i = n.x; i < n.x + length; i++)
	//	{
	//		for (int j = n.y; j < n.y + length; j++)
	//		{
	//			x = bmp[j*linebyte + i];
	//			value[0][0] += x;
	//		}
	//	}
	//	for (int i = n.x; i < n.x + length; i++)
	//	{
	//		for (int j = n.y + length; j < m.y; j++)
	//		{
	//			x = bmp[j*linebyte + i];
	//			value[1][0] += x;
	//		}
	//	}
	//	for (int i = n.x + length; i < m.x; i++)
	//	{
	//		for (int j = n.y; j < n.y + length; j++)
	//		{
	//			x = bmp[j*linebyte + i];
	//			value[0][1] += x;
	//		}
	//	}
	//	for (int i = n.x + length; i < m.x; i++)
	//	{
	//		for (int j = n.y + length; j < m.y; j++)
	//		{
	//			x = bmp[j*linebyte + i];
	//			value[1][1] += x;
	//		}
	//	}
	//	for (int i = 0; i < 2; i++)
	//	{
	//		for (int j = 0; j < 2; j++)
	//		{
	//			value[i][j] /= (length * length);
	//		}
	//	}
	//	for (int i = 0; i < 2; i++)
	//	{
	//		for (int j = 0; j < 2; j++)
	//		{
	//			if (max < value[i][j])
	//				max = value[i][j];
	//			if (min > value[i][j])
	//				min = value[i][j];
	//			
	//		}
	//	}
	//	if (max - min > speed)
	//	{
	//		a.x = n.x;
	//		a.y = n.y;
	//		b.x = n.x + length;
	//		b.y = n.y + length;
	//		si.left_bottom = a;
	//		si.right_top = b;
	//		if (length > 1)
	//		{
	//			sub.push_back(si);
	//		}
	//		else
	//		{
	//			if (value[0][0] > 122)
	//			{
	//				if (length == 0 && judge[a.y*linebyte + a.x] == 0)
	//				{
	//					pBmpBuf[a.y*linebyte + a.x] = 255;
	//					judge[a.y*linebyte + a.x] = 1;
	//				}
	//				if (length == 1)
	//				{
	//					if (judge[a.y*linebyte + a.x] == 0)
	//					{
	//						pBmpBuf[a.y*linebyte + a.x] = 255;
	//						judge[a.y*linebyte + a.x] = 1;
	//					}
	//					if (judge[a.y*linebyte + a.x + 1] == 0)
	//					{
	//						pBmpBuf[a.y*linebyte + a.x + 1] = 255;
	//						judge[a.y*linebyte + a.x + 1] = 1;
	//					}
	//					if (judge[(a.y + 1)*linebyte + a.x] == 0)
	//					{
	//						pBmpBuf[(a.y + 1)*linebyte + a.x] = 255;
	//						judge[(a.y + 1)*linebyte + a.x] = 1;
	//					}
	//					if (judge[(a.y + 1)*linebyte + a.x + 1] == 0)
	//					{
	//						pBmpBuf[(a.y + 1)*linebyte + a.x + 1] = 255;
	//						judge[(a.y + 1)*linebyte + a.x + 1] = 1;
	//					}	
	//				}
	//			}
	//			else
	//			{
	//				if (length == 0 && judge[a.y*linebyte + a.x] == 0)
	//				{
	//					pBmpBuf[a.y*linebyte + a.x] = 0;
	//					judge[a.y*linebyte + a.x] = 1;
	//				}
	//				if (length == 1)
	//				{
	//					if (judge[a.y*linebyte + a.x] == 0)
	//					{
	//						pBmpBuf[a.y*linebyte + a.x] = 0;
	//						judge[a.y*linebyte + a.x] = 1;
	//					}
	//					if (judge[a.y*linebyte + a.x + 1] == 0)
	//					{
	//						pBmpBuf[a.y*linebyte + a.x + 1] = 0;
	//						judge[a.y*linebyte + a.x + 1] = 1;
	//					}
	//					if (judge[(a.y + 1)*linebyte + a.x] == 0)
	//					{
	//						pBmpBuf[(a.y + 1)*linebyte + a.x] = 0;
	//						judge[(a.y + 1)*linebyte + a.x] = 1;
	//					}
	//					if (judge[(a.y + 1)*linebyte + a.x + 1] == 0)
	//					{
	//						pBmpBuf[(a.y + 1)*linebyte + a.x + 1] = 0;
	//						judge[(a.y + 1)*linebyte + a.x + 1] = 1;
	//					}
	//				}
	//			}
	//		}
	//		//cout << "a:(" << n.x << "," << n.y << "), b:(" << m.x << "," << m.y << ")" << endl;
	//		a.x = n.x;
	//		a.y = n.y + length;
	//		b.x = n.x + length;
	//		b.y = m.y;
	//		si.left_bottom = a;
	//		si.right_top = b;
	//		if (length > 1)
	//		{
	//			sub.push_back(si);
	//		}
	//		else
	//		{
	//			if (value[0][1] > 220)
	//			{
	//				if (length == 0 && judge[a.y*linebyte + a.x] == 0)
	//				{
	//					pBmpBuf[a.y*linebyte + a.x] = 255;
	//					judge[a.y*linebyte + a.x] = 1;
	//				}
	//				if (length == 1)
	//				{
	//					if (judge[a.y*linebyte + a.x] == 0)
	//					{
	//						pBmpBuf[a.y*linebyte + a.x] = 255;
	//						judge[a.y*linebyte + a.x] = 1;
	//					}
	//					if (judge[a.y*linebyte + a.x + 1] == 0)
	//					{
	//						pBmpBuf[a.y*linebyte + a.x + 1] = 255;
	//						judge[a.y*linebyte + a.x + 1] = 1;
	//					}
	//					if (judge[(a.y + 1)*linebyte + a.x] == 0)
	//					{
	//						pBmpBuf[(a.y + 1)*linebyte + a.x] = 255;
	//						judge[(a.y + 1)*linebyte + a.x] = 1;
	//					}
	//					if (judge[(a.y + 1)*linebyte + a.x + 1] == 0)
	//					{
	//						pBmpBuf[(a.y + 1)*linebyte + a.x + 1] = 255;
	//						judge[(a.y + 1)*linebyte + a.x + 1] = 1;
	//					}
	//				}
	//			}
	//			else
	//			{
	//				if (length == 0 && judge[a.y*linebyte + a.x] == 0)
	//				{
	//					pBmpBuf[a.y*linebyte + a.x] = 255;
	//					judge[a.y*linebyte + a.x] = 1;
	//				}
	//				if (length == 1)
	//				{
	//					if (judge[a.y*linebyte + a.x] == 0)
	//					{
	//						pBmpBuf[a.y*linebyte + a.x] = 0;
	//						judge[a.y*linebyte + a.x] = 1;
	//					}
	//					if (judge[a.y*linebyte + a.x + 1] == 0)
	//					{
	//						pBmpBuf[a.y*linebyte + a.x + 1] = 0;
	//						judge[a.y*linebyte + a.x + 1] = 1;
	//					}
	//					if (judge[(a.y + 1)*linebyte + a.x] == 0)
	//					{
	//						pBmpBuf[(a.y + 1)*linebyte + a.x] = 0;
	//						judge[(a.y + 1)*linebyte + a.x] = 1;
	//					}
	//					if (judge[(a.y + 1)*linebyte + a.x + 1] == 0)
	//					{
	//						pBmpBuf[(a.y + 1)*linebyte + a.x + 1] = 0;
	//						judge[(a.y + 1)*linebyte + a.x + 1] = 1;
	//					}
	//				}
	//			}
	//		}
	//		//cout << "a:(" << n.x << "," << n.y << "), b:(" << m.x << "," << m.y << ")" << endl;
	//		a.x = n.x + length;
	//		a.y = n.y;
	//		b.x = m.x;
	//		b.y = n.y + length;
	//		si.left_bottom = a;
	//		si.right_top = b;
	//		if (length > 1)
	//		{
	//			sub.push_back(si);
	//		}
	//		else
	//		{
	//			if (value[1][0] > 220)
	//			{
	//				if (length == 0 && judge[a.y*linebyte + a.x] == 0)
	//				{
	//					pBmpBuf[a.y*linebyte + a.x] = 255;
	//					judge[a.y*linebyte + a.x] = 1;
	//				}
	//				if (length == 1)
	//				{
	//					if (judge[a.y*linebyte + a.x] == 0)
	//					{
	//						pBmpBuf[a.y*linebyte + a.x] = 255;
	//						judge[a.y*linebyte + a.x] = 1;
	//					}
	//					if (judge[a.y*linebyte + a.x + 1] == 0)
	//					{
	//						pBmpBuf[a.y*linebyte + a.x + 1] = 255;
	//						judge[a.y*linebyte + a.x + 1] = 1;
	//					}
	//					if (judge[(a.y + 1)*linebyte + a.x] == 0)
	//					{
	//						pBmpBuf[(a.y + 1)*linebyte + a.x] = 255;
	//						judge[(a.y + 1)*linebyte + a.x] = 1;
	//					}
	//					if (judge[(a.y + 1)*linebyte + a.x + 1] == 0)
	//					{
	//						pBmpBuf[(a.y + 1)*linebyte + a.x + 1] = 255;
	//						judge[(a.y + 1)*linebyte + a.x + 1] = 1;
	//					}
	//				}
	//			}
	//			else
	//			{
	//				if (length == 0 && judge[a.y*linebyte + a.x] == 0)
	//				{
	//					pBmpBuf[a.y*linebyte + a.x] = 0;
	//					judge[a.y*linebyte + a.x] = 1;
	//				}
	//				if (length == 1)
	//				{
	//					if (judge[a.y*linebyte + a.x] == 0)
	//					{
	//						pBmpBuf[a.y*linebyte + a.x] = 0;
	//						judge[a.y*linebyte + a.x] = 1;
	//					}
	//					if (judge[a.y*linebyte + a.x + 1] == 0)
	//					{
	//						pBmpBuf[a.y*linebyte + a.x + 1] = 0;
	//						judge[a.y*linebyte + a.x + 1] = 1;
	//					}
	//					if (judge[(a.y + 1)*linebyte + a.x] == 0)
	//					{
	//						pBmpBuf[(a.y + 1)*linebyte + a.x] = 0;
	//						judge[(a.y + 1)*linebyte + a.x] = 1;
	//					}
	//					if (judge[(a.y + 1)*linebyte + a.x + 1] == 0)
	//					{
	//						pBmpBuf[(a.y + 1)*linebyte + a.x + 1] = 0;
	//						judge[(a.y + 1)*linebyte + a.x + 1] = 1;
	//					}
	//				}
	//			}
	//		}
	//		//cout << "a:(" << a.x << "," << a.y << "), b:(" << a.x << "," << a.y << ")" << endl;
	//		//cout << "a:(" << n.x << "," << n.y << "), b:(" << m.x << "," << m.y << ")" << endl;
	//		a.x = n.x + length;
	//		a.y = n.y + length;
	//		b.x = m.x;
	//		b.y = m.y;
	//		si.left_bottom = a;
	//		si.right_top = b;
	//		if (length > 1)
	//		{
	//			sub.push_back(si);
	//		}
	//		else
	//		{
	//			if (value[1][1] > 220)
	//			{
	//				if (length == 0 && judge[a.y*linebyte + a.x] == 0)
	//				{
	//					pBmpBuf[a.y*linebyte + a.x] = 255;
	//					judge[a.y*linebyte + a.x] = 1;
	//				}
	//				if (length == 1)
	//				{
	//					if (judge[a.y*linebyte + a.x] == 0)
	//					{
	//						pBmpBuf[a.y*linebyte + a.x] = 255;
	//						judge[a.y*linebyte + a.x] = 1;
	//					}
	//					if (judge[a.y*linebyte + a.x + 1] == 0)
	//					{
	//						pBmpBuf[a.y*linebyte + a.x + 1] = 255;
	//						judge[a.y*linebyte + a.x + 1] = 1;
	//					}
	//					if (judge[(a.y + 1)*linebyte + a.x] == 0)
	//					{
	//						pBmpBuf[(a.y + 1)*linebyte + a.x] = 255;
	//						judge[(a.y + 1)*linebyte + a.x] = 1;
	//					}
	//					if (judge[(a.y + 1)*linebyte + a.x + 1] == 0)
	//					{
	//						pBmpBuf[(a.y + 1)*linebyte + a.x + 1] = 255;
	//						judge[(a.y + 1)*linebyte + a.x + 1] = 1;
	//					}
	//				}
	//			}
	//			else
	//			{
	//				if (length == 0 && judge[a.y*linebyte + a.x] == 0)
	//				{
	//					pBmpBuf[a.y*linebyte + a.x] = 0;
	//					judge[a.y*linebyte + a.x] = 1;
	//				}
	//				if (length == 1)
	//				{
	//					if (judge[a.y*linebyte + a.x] == 0)
	//					{
	//						pBmpBuf[a.y*linebyte + a.x] = 0;
	//						judge[a.y*linebyte + a.x] = 1;
	//					}
	//					if (judge[a.y*linebyte + a.x + 1] == 0)
	//					{
	//						pBmpBuf[a.y*linebyte + a.x + 1] = 0;
	//						judge[a.y*linebyte + a.x + 1] = 1;
	//					}
	//					if (judge[(a.y + 1)*linebyte + a.x] == 0)
	//					{
	//						pBmpBuf[(a.y + 1)*linebyte + a.x] = 0;
	//						judge[(a.y + 1)*linebyte + a.x] = 1;
	//					}
	//					if (judge[(a.y + 1)*linebyte + a.x + 1] == 0)
	//					{
	//						pBmpBuf[(a.y + 1)*linebyte + a.x + 1] = 0;
	//						judge[(a.y + 1)*linebyte + a.x + 1] = 1;
	//					}
	//				}
	//			}
	//		}
	//		//cout << "a:(" << n.x << "," << n.y << "), b:(" << m.x << "," << m.y << ")" << endl;
	//	}
	//	else
	//	{
	//	    //cout << max << endl;
	//		if (max > 220)
	//		{
	//			for (int i = n.x; i < m.x + 1; i++)
	//			{
	//				for (int j = n.y; j < m.y + 1; j++)
	//				{
	//					if (judge[j*linebyte + i] == 0)
	//					{
	//						pBmpBuf[j*linebyte + i] = 255;
	//						judge[j*linebyte + i] = 1;
	//					}
	//				}
	//			}
	//		}
	//		else
	//		{
	//			for (int i = n.x; i < m.x + 1; i++)
	//			{
	//				for (int j = n.y; j < m.y + 1; j++)
	//				{
	//					if (judge[j*linebyte + i] == 0)
	//					{
	//						pBmpBuf[j*linebyte + i] = 0;
	//						judge[j*linebyte + i] = 1;
	//					}
	//				}
	//			}
	//		}
	//	}
	//}
	//int totalx = 0, totaly = 0;
	//for (int i = 0; i < width; i++)
	//{
	//	for (int j = 0; j < height; j++)
	//	{
	//		if (judge[j*linebyte + i] == 0)
	//		{
	//			totalx++;
	//			if (bmp[j*linebyte + i] > 128)
	//			{
	//				pBmpBuf[j*linebyte + i] = 255;
	//			}
	//			else
	//			{
	//				pBmpBuf[j*linebyte + i] = 255;
	//			}
	//		}
	//	}
	//}
	////cout << totalx << endl;
	std::stack<SplitStruct> nMyStack;
	SplitStruct splitStruct, splitStructTemp;
	splitStruct.x = 0;
	splitStruct.y = 0;
	splitStruct.w = linebyte;
	splitStruct.h = height;
	nMyStack.push(splitStruct);
	int nValueS[2][2];// 用于存储块图像的平均灰度值
	int nAV;
	int nWidthTemp[3], nHeightTemp[3], nTemp;
	int nWidth, nHeigh;
	int n, m;
	double dOver;
	while (!nMyStack.empty())
	{
		splitStruct = nMyStack.top();
		nMyStack.pop();
		n = (splitStruct.y * linebyte + splitStruct.x);// 该块图像的左上角 是左上角！！！ 坐标原点在左上角！！！
		nWidthTemp[0] = 0;
		nWidthTemp[2] = (splitStruct.w + 1) / 2;
		nWidthTemp[1] = splitStruct.w - nWidthTemp[2];
		nHeightTemp[0] = 0;
		nHeightTemp[2] = (splitStruct.h + 1) / 2;
		nHeightTemp[1] = splitStruct.h - nHeightTemp[2];
		// 计算每一块图像的属性值
		int nValue;
		int nValueTemp;
		nAV = 0;
		for (i = 1; i < 3; ++i)
		{
			for (j = 1; j < 3; ++j)
			{
				nValue = 0;
				m = (n + linebyte * nHeightTemp[i - 1] + nWidthTemp[j - 1]);
				for (nHeigh = 0; nHeigh < nHeightTemp[i]; ++nHeigh)
				{
					for (nWidth = 0; nWidth < nWidthTemp[j]; ++nWidth)
					{
						if (k < linebyte * height)
						{
							k = (m + linebyte * nHeigh + nWidth);
							nValueTemp = (int)bmp[k];
							// 灰度值之和
							nValue += nValueTemp;
						}
					}
				}
				if (nHeightTemp[i] * nWidthTemp[j] == 0)
				{
					continue;
				}
				if (nHeightTemp[i] * nWidthTemp[j] == 1)
				{
					k = m;
					if (k < linebyte * height - 1)
					{
						if (bmp[k] < 128)
						{
							pBmpBuf[k] = 0;
							pBmpBuf[k + 1] = 0;
						}
						else
						{
							pBmpBuf[k] = 255;
							pBmpBuf[k + 1] = 255;
						}
					}
					continue;
				}
				nValueS[i - 1][j - 1] = nValue / (nHeightTemp[i] * nWidthTemp[j]);
				if (nValueS[i - 1][j - 1] < 200)
				{
					splitStructTemp.w = nWidthTemp[j];
					splitStructTemp.h = nHeightTemp[i];
					splitStructTemp.x = splitStruct.x + nWidthTemp[j - 1];
					splitStructTemp.y = splitStruct.y + nHeightTemp[i - 1];
					nMyStack.push(splitStructTemp);
				}
				else
				{
					for (nHeigh = 0; nHeigh < nHeightTemp[i]; ++nHeigh)
					{
						for (nWidth = 0; nWidth < nWidthTemp[j]; ++nWidth)
						{
							k = (m + linebyte * nHeigh + nWidth);
							if (k < linebyte * height - 1)
							{
								pBmpBuf[k] = 255;
								pBmpBuf[k + 1] = 255;
							}
						}
					}
				}
			}
		}
	}
	return pBmpBuf;
}


