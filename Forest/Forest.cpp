#include "Forest.h"
#include "Config.h"
Forest::Forest(){
	statistic_ = NULL;
}

Forest::~Forest(){

	if(statistic_!=NULL) delete [] statistic_;

}


void Forest::Load(char* file){
	Configuration* conf = Global();
	conf->LoadConfiguration(file);
	tree_number_ = conf->tree_number_;
	trees_.resize(tree_number_);
	for(int i = 0; i < tree_number_; i ++ ){
		trees_[i].Load(conf->tree_file_[i]);
	}
	num_class_ = trees_[0].num_class_;
	statistic_ = new double [num_class_+1];
}


void Forest::Save(char* file){


}

int Forest::Apply0(Mat& img, int row, int col){
	int idx;
	for(int k = 0; k < tree_number_; k++ ){
		idx = trees_[k].Apply0(img,row,col);       
	}	
    return idx;
}

void Forest::Apply(Mat& img, Mat& label){
	Response response;
	Mat resp;
	img.copyTo(resp);
	//resp = img;
	//response.sobel(img, resp);
	//cvShowImage("resp",&(IplImage(resp)));
	//cvWaitKey(0);
	label = Mat::zeros(resp.rows, resp.cols, CV_16UC1);
	int i,j,k,l;
	double maxScore = 0;
	int idxScore = 0;


	//FILE* f = fopen("1.txt","w");
	for( i = 0; i < resp.rows; i ++ ){
		for( j = 0; j < resp.cols; j ++ ){
			//fprintf(f,"%d ",resp.at<uchar>(i,j));
			//if(resp.at<uchar>(i,j)!=0) {
				memset(statistic_, 0, (num_class_+1)*sizeof(double));
				for( k = 0; k < tree_number_; k++ ){
					trees_[k].Apply(resp,i,j);
					for( l = 0; l < num_class_+1; l ++ ){
						statistic_[l] += trees_[k].statistic_[l];
					}
				}	
				for(l = 0; l < num_class_+1; l ++ ){
					if(maxScore <= statistic_[l] ){
						maxScore = statistic_[l];
						idxScore = l;
					}
				}

				maxScore /= tree_number_;
				label.at<ushort>(i,j) = (ushort)idxScore;




			//}


			//for(l = 0; l < num_class_+1; l++){
			//  fprintf(f, "%f ", statistic_[l]);
			//}
			//fprintf(f,"\n");


		}
		//fprintf(f,"\n");
	}

	//fclose(f);
	//printf("Done");

}
