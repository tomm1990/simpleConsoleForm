#pragma once
#include <map>
#include "../Button/Button.h"
#include "../Control/Scrollable.h"

class CheckList : public Panel {
public:
	CheckList(const int , const int , const vector<string>&);
	virtual ~CheckList();
	void deselctIndex(const size_t index) { valsMap[list[index]] = false; }
	void selectIndex(const size_t index) { valsMap[list[index]] = true; }
private:
	map< string, bool > valsMap; // map of string values and bool type
	size_t size;
	vector<string> list;
};