#pragma once
#include "../Control/Scrollable.h"

class CheckList :
	public Scrollable
{
private:


public:
	CheckList(int width, const vector<string>& list);
	void mark() override{};
};
