#pragma once
#include "../Panel/Panel.h"
#include <map>
#include "../Button/Button.h"

typedef struct { Button* b; bool isCheck; } bsr;

class CheckList :
	public Panel
{
private:
	map<string,bsr> list;
	vector <string> options;
public:
	CheckList(int height,int width, const vector<string>& list);
	void deselctIndex(size_t index);
	void selectIndex(size_t index);
};
