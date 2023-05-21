#include "outlineExtraction.h"

unsigned char * outlineExtraction::regionMark(unsigned char * bmp, int width, int height, int linebyte)
{
	unsigned char * p = new unsigned char[height*linebyte];
	int label = 1;
	int *values = new int[height*width]{ 0 };
	std::vector<POINT> s;
	for ( i = 1; i < height - 1; i++)
	{
		for ( j = 1; j < width - 1; j++)
		{
			if (bmp[i*linebyte + j] == 255 && values[i*linebyte + j] == 0)
			{
				values[i*linebyte + j] = label;
				label++;
				POINT p;
				p.x = j;
				p.y = i;
				s.push_back(p);
				while (!s.empty())
				{
					POINT currPt = s.back();
					s.pop_back();
					origin.x = currPt.x;
					origin.y = currPt.y;
					for (i = 0; i < 8; i++)
					{
						p.x = currPt.x + dir[i][0];
						p.y = currPt.y + dir[i][1];
						if (p.x < 0 || p.y<0 || p.x > width - 1 || p.y>height - 1)
							continue;
						if (bmp[p.y * linebyte + p.x] == 255 && values[p.y * linebyte + p.x] == 0)
						{
							s.push_back(p);
							values[p.y * linebyte + p.x] = values[origin.y*linebyte + origin.x];
						}
					}
				}
			}
		}
	}

	std::set<int> re;
	for (j = 0; j < height*linebyte; j++)
	{
		re.insert(values[j]);
	}
	for ( i = 0; i < height*linebyte; i++)
	{
		if (values[i] == 0)
		{
			p[i] = bmp[i];
		}
		else
		{
			p[i] = values[i] * 20;
		}

	}
	// RAdd(p, width, height, linebyte);
	return p;
}


void outlineExtraction::RAdd(unsigned char * in_bmp, int width, int height, int linebyte)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (in_bmp[i * linebyte + j] == 255) {
				in_bmp[i * linebyte + j] = 0;
				continue;
			}
			if (in_bmp[i * linebyte + j] == 0) {
				in_bmp[i * linebyte + j] = 255;
				continue;
			}
			
		}
	}
}

unsigned char * outlineExtraction::extractOutline(unsigned char * bmp, int width, int height, int linebyte)
{
	unsigned char * pBmpBuf = new unsigned char[height*linebyte]{ 255 };
	int x, y, count[2]{ 0 };
	int target = 0;
	for ( i = 0; i < height; i++)
	{
		for ( j = 0; j < width; j++)
		{
			count[0] = 0;
			count[1] = 0;
			for (int k = 0; k < 8; k++)
			{
				x = dir[k][0];
				y = dir[k][1];
				if (bmp[(i + x)*linebyte + j + y] == 0)
					count[0]++;
				if (bmp[(i + x)*linebyte + j + y] == 255)
					count[1]++;
			}
			if (count[0] == 8 || count[1] == 8)
			{
				pBmpBuf[i*linebyte + j] = 255;
			}
			else
			{
				pBmpBuf[i*linebyte + j] = target;
			}
		}
	}
	return pBmpBuf;
}



