#pragma once
#include "../Panel/Panel.h"

class CheckList :
	public Panel
{
private:
	vector<string> list;
	int listFlag[5] = { 0 };
	bool isListOpen;
	size_t size;
	int selection;

public:
	CheckList(int height,int width, vector<string> options);
	void setSelectedIndex(int index) { selection = index - 1; };
	void keyDown(WORD code, CHAR chr) override;
	void getAllControls(vector<Control*>* vector) override;
	bool canGetFocus() override;
};
