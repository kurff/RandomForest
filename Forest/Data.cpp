#include "Data.h"
#include <iostream>
Data::Data(){

}

Data::~Data(){
	for(int i = 0; i < file_.size(); i ++)
		delete [] file_[i];
}

void Data::LoadFileName(char* file){
	FILE* f = fopen(file,"r");
	int num = 0;
	fscanf(f,"%d",&num);
	file_.resize(num);
	for(int i = 0; i < num; i ++){
		file_[i] = new char [200];
	    fscanf(f,"%s",file_[i]);
	}
	fclose(f);
}

void Data::LoadPixel(char* file){
	FILE* f = fopen(file,"r");
	int num = 0;
	fscanf(f,"%d",&num);
	pixel_.resize(num);

	for(int i = 0; i < num; i ++ ){
	  fscanf(f,"%d %d %d %d %d %d",&(pixel_[i].idx),&(pixel_[i].y),&(pixel_[i].x),
			&(pixel_[i].cnt), &(pixel_[i].leafId), &(pixel_[i].label));
	}
	fclose(f);

}