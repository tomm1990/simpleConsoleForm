#pragma once
#include "../Control/Control.h"

class RadioList : public Control{
	vector<string> list;
	size_t size;
	int selection = {};

public:
	RadioList(int height,int width, vector<string> options);;
	void setSelectedIndex(int index) { selection = index - 1; };
	void draw(Graphics& graphics, int left, int top, size_t p) override;
	void keyDown(WORD code, CHAR chr) override;
	void mousePressed(int x, int y, bool isLeft) override;

};
