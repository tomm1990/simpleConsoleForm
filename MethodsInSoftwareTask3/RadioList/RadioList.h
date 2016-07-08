#pragma once
#include "../Control/Scrollable.h"

class RadioList : 
	public Scrollable{

public:
	RadioList(int height,int width, vector<string> options);
	void update(size_t index) override;
};
