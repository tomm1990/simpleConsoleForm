#pragma once
#include "../Panel/Panel.h"

class RadioList : public Panel{
	vector<string> list;


public:
	RadioList(int height,int width, vector<string> options);;
};
