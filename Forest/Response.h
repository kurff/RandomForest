#pragma once
#include "opencv2/opencv.hpp"
using namespace cv;
class Response{
public:
	Response(){
	
	}

	~Response(){
	
	}

public:
	void sobel(Mat& image, Mat& response);

	void calcMap(Mat& image, Mat& response);


};