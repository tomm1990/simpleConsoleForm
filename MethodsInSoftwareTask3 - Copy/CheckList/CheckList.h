#pragma once
#include "../Control/Control.h"

class CheckList :
	public Control
{
private:
	vector<string> list;
	int listFlag[5]={0};
	bool isListOpen;
	size_t size;
	int selection;

public:
	CheckList(int width, vector<string> options);
	void open();
	void close();
	void setSelectedIndex(int index) { selection = index - 1; };
	void draw(Graphics& graphics, int left, int top, size_t p) override;
	void keyDown(WORD code, CHAR chr) override;
	void mousePressed(int x, int y, bool isLeft) override;
	void getAllControls(vector<Control*>* vector) override;
	bool canGetFocus() override;
};
