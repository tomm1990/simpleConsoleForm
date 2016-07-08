#pragma once
#include "../Control/Scrollable.h"


class RadioList : 
	public Scrollable{

private:
	map <Button*, bool> valsMap;
public:
	RadioList(int height,int width, vector<string> options);
	virtual ~RadioList() { }
	void update() override;
};
