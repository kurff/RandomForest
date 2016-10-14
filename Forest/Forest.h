#pragma once
#include "TreeArray.h"
#include "Response.h"
#include <vector>
using namespace std;
#include "opencv2/opencv.hpp"
using namespace cv;
class Forest{
public:
	Forest();
	~Forest();

public:
	void Save(char* file);
	void Load(char* file);

	void Train();
	void Apply(Mat& img, Mat& label);
	int Apply0(Mat& img, int row, int col);



private:
	int tree_number_;
	vector<TreeArray> trees_;
	int num_class_;
	double* statistic_;



};