#include "TreeArray.h"
#include <memory.h>
#include "Config.h"
#include "Feature.h"
#include "Response.h"

TreeArray::TreeArray(){

	root_ = NULL;
	statistic_ = NULL;
}

TreeArray::~TreeArray(){
	if(root_ != NULL){
	   delete [] root_;
	}
	if(statistic_ != NULL){
		delete [] statistic_;
	}
}



void TreeArray::Load(char* file){
	FILE* f = fopen(file,"r");
	fscanf(f,"%d",&num_node_);
	root_ = new Node [num_node_];
	int node_index;
	for(int i = 0; i < num_node_; i ++ ){
		fscanf(f,"%d ",&node_index);
		//printf("%d \n",node_index);
		root_[node_index].node_index_ = node_index;
		fscanf(f,"%d %d",&(root_[node_index].bIsLeaf_), &(root_[node_index].bIsSplit_));
		fscanf(f,"%d %d %d %d",
			&(root_[node_index].r0_),&(root_[node_index].c0_),
			&(root_[node_index].r1_),&(root_[node_index].c1_));
		fscanf(f,"%d ",&(root_[node_index].threshold_));
		fscanf(f,"%d ",&(root_[node_index].feature_index_));
		fscanf(f,"%d %d",&(root_[node_index].left_child_index_),
			&(root_[node_index].right_child_index_));
		fscanf(f,"%d",&(root_[node_index].num_class_));	
		if(root_[node_index].bIsLeaf_){
			root_[node_index].statistic_ = new double [root_[node_index].num_class_ + 1];
			for(int j = 0; j < root_[node_index].num_class_ + 1; j ++ ){
			   float s = 0;
			   fscanf(f,"%f ",&s);
			   root_[node_index].statistic_[j] = s;
			}
		}
	}
	num_class_ = root_[0].num_class_;
	fclose(f);

}


