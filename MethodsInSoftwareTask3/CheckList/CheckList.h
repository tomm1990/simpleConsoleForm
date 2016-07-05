#pragma once
#include "../Panel/Panel.h"

class CheckList :
	public Panel
{
private:


public:
	CheckList(int width, const vector<string>& list);
	//void mark() override{};
};
