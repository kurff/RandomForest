#include "Config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
Configuration config;

Configuration* Global(){
   return & config;
}

void Configuration::LoadConfiguration(char* file){
    FILE* f = fopen(file,"r");
	if(f==NULL){
	   printf("Can not find the configuration file\n");
	   exit(0);
	}
	fscanf(f,"%d",&tree_number_);
	tree_file_.resize(tree_number_);
	
	char tree_file[MAX_PATH];
	for( int i = 0; i < tree_number_; i ++ ){
		tree_file_[i] = new char [MAX_PATH];
	    fscanf(f,"%s",&(tree_file));
		strcpy(tree_file_[i],tree_file);
	}
	

	fclose(f);
}