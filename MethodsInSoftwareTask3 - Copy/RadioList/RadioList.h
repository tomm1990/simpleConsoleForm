#pragma once
#include "../Panel/Panel.h"

class RadioList : public Panel{
	vector<string> list;
	size_t size;
	int selection = {};

public:
	RadioList(int height,int width, vector<string> options);;
	void setSelectedIndex(int index) { selection = index - 1; };
	void keyDown(WORD code, CHAR chr) override;

};
