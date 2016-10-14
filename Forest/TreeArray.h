#pragma once
#include <stdio.h>
#include "Node.h"
#include "Feature.h"
#include "opencv2/opencv.hpp"
using namespace cv;
const int dimension = 256; // the number of threshold candidates
class TreeArray{

public:
	TreeArray();

	~TreeArray();

public:

	void Load(char* file);
	inline void Apply(const Mat& response, int i, int j){
     	char v =0; 
		int current = 0;	

		while(root_[current].bIsSplit_){
			v = feature_.extractor0(response,
				i, j, root_[current].r0_,root_[current].c0_,
				root_[current].r1_,root_[current].c1_,1.0);	        
			if( v < root_[current].threshold_ ){
				current = root_[current].left_child_index_;
			}else{
				current = root_[current].right_child_index_; 
			}	  
			//printf("%d ",current);
		}
		//printf("\n");
		statistic_ = root_[current].statistic_;
	}

	inline int Apply0(const Mat& response, int i, int j){
		char v =0; 
		int current = 0;	

		while(root_[current].bIsSplit_){
			v = feature_.extractor0(response,
				i, j, root_[current].r0_,root_[current].c0_,
				root_[current].r1_,root_[current].c1_,1.0);	        
			if( v < root_[current].threshold_ ){
				current = root_[current].left_child_index_;
			}else{
				current = root_[current].right_child_index_; 
			}	  
			//printf("%d ",current);
		}
		//printf("\n");
		return root_[current].node_index_;
	}


public:
	double* statistic_;
	int num_class_;

private:
	Node* root_;
	int num_node_;
	Feature feature_;
};