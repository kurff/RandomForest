#include "Response.h"

void Response::calcMap(Mat& image, Mat& response){






}

void Response::sobel(Mat& image, Mat& response){
	int i,j,k;
	// ÖÐÖµÂË²¨
	Mat median;
	medianBlur ( image, median, 3 );  
	response = Mat::zeros(image.rows, image.cols, CV_8UC1);
	for(i = 0; i < image.rows-1; i ++ ){
		Vec3b* p = image.ptr<Vec3b>(i);
		Vec3b* p0 = image.ptr<Vec3b>(i+1);
		uchar* res = response.ptr<uchar>(i);
		for( j = 0; j < image.cols-1; j ++ ){
			uchar m = 255;
			for( k = 0; k < 3; k ++ ){
				uchar v = min(abs(p[j].val[k] - p[j+1].val[k]) + 
					abs(p[j].val[k] - p0[j].val[k]),255);
				if(m>=v){
				  m = v;
				}
			}
			res[j] = m; 
		}
	}
	//cvShowImage("src",&(IplImage(response)));
	//cvWaitKey(1);
}

