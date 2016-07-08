#pragma once
#include <map>
#include "../Button/Button.h"
#include "../Control/Scrollable.h"


class CheckList :
	public Panel
{
private:
	map<string, bool> valsMap;
	size_t size;
	vector<string> list;
public:
	CheckList(int height,int width, const vector<string>& list);
	void deselctIndex(size_t index);
	void selectIndex(size_t index);
};
