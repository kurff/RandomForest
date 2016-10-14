#pragma once
#include <vector>
using namespace std;

struct Element{
	int x;
	int y;
	unsigned int idx;
	unsigned int cnt;
	unsigned int leafId;
	int label;
};

class Data{

public:
	Data();
	~Data();

public:
	void LoadFileName(char* file);
	void LoadPixel(char* file);


public:
	vector<char*> file_;
	vector<Element> pixel_;



};