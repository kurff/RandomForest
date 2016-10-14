
#pragma once
#include "opencv2/opencv.hpp"
#include <windows.h>
using namespace cv;
struct Element{
	int x;
	int y;
	unsigned int idx;
};

struct DataNode{
	Mat image;
	Mat label;
	Mat response;
	char imageName[MAX_PATH];
	char labelName[MAX_PATH];
	vector<Element> pixel;
	vector<int> pixelLabel;
};

