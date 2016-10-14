#pragma once
struct Node{
	bool bIsLeaf_;
	bool bIsSplit_;
	char threshold_;
	double* statistic_;
	struct Node* left_;
	struct Node* right_;
	int num_class_;
	int r0_;
	int c0_;
	int r1_;
	int c1_;
	int node_index_;
	int left_child_index_;
	int right_child_index_;
	int feature_index_;
	//bool initialNode(int node_index);
	//bool initialLeaf(int node_index);
	//bool initialSplit(int node_index);
	//bool destroyNode();
};