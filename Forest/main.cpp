#include "Forest.h"
#include "TreeArray.h"
#include "Data.h"
void main(){

	Forest forest;
	forest.Load("configuration.txt");

	Mat img;
	Mat label;
	char img_name[200];
	char save_name[200];

	Data data;
	
	data.LoadFileName("file_name.txt");
	data.LoadPixel("d.txt");

	int node_index;
	int counter = 0;
	for(int i = 0; i < data.pixel_.size(); i ++ ){
		if(i%100==0) printf("%d\n",i);
		img = imread(data.file_[data.pixel_[i].idx],0);
		node_index = forest.Apply0(img,data.pixel_[i].y,data.pixel_[i].x);
		if(data.pixel_[i].leafId == node_index){
		   counter ++;
		}
	}

	printf("%4.3f",double(counter) / double(data.pixel_.size()));


}