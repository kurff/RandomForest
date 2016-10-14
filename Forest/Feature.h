#pragma once
#include "opencv2/opencv.hpp"
#include "Config.h"
using namespace cv;
class Feature{
public:


	Feature(){
	
	}

	~Feature(){
	}

public:
		inline char extractor0(const Mat& response, int row, int col, int r0, int c0, int r1, int c1, float scale){
		assert(row < response.rows && col < response.cols);
		int x,y;
		uchar v;
		int x0,y0;
		uchar v0;
		int t;
		x = int(scale*c0) + col;
		y = int(scale*r0) + row;

		//if(x<0) x = -x;
		//if(y<0) y = -y;

		//if(x>= response.cols) x -= response.cols;
		//if(y>= response.rows) y -= response.rows;

		if(x >=0 && x < response.cols && y >=0 && y < response.rows){
			v = response.at<uchar>(y,x);
		}else{
			v = 0;
		}
		x0 = int(scale*c1) + col;
		y0 = int(scale*r1) + row;

		/*if(x0<0) x0 = -x0;
		if(y0<0) y0 = -y0;

		if(x0>= response.cols) x0 -= response.cols;
		if(y0>= response.rows) y0 -= response.rows;*/

		if(x0>=0 && x0 < response.cols && y0 >=0 && y0 < response.rows){
			v0 = response.at<uchar>(y0,x0);
		}
		else{
			v0 = 0;
		}

		t = (int) v - (int) v0;
		if( t >= 127 ){
			v = 127;
		}
		else if( t <= -128 ){
			v = -128;
		}
		else{
			v = char(t);
		}
		return v;
	
	
	}
	
};