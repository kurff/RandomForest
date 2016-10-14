#pragma once
#define MAX_PATH 260
#include <vector>
using namespace std;
class Configuration{
public:
	Configuration(){
	
	}

	~Configuration(){
	   for(int i = 0; i < tree_file_.size(); i ++ ){
	      delete [] tree_file_[i];
	   }
	}

public:
	void LoadConfiguration(char* file);

public:
	int tree_number_;
	vector<char* > tree_file_;


};

Configuration* Global();