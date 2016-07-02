#pragma once
#include "../Panel/Panel.h"
#include "../Button/Button.h"

class Scrollable :
	public Panel
{
private:
	int cursor;
	int selection;
	int size;
	vector<string>list;
public:
	Scrollable(int height, int width, vector<string> list);
	void keyDown(WORD code, CHAR chr) override;
	~Scrollable(){};
};

