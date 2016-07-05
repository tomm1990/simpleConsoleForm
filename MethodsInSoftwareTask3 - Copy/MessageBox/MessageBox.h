#pragma once
#include "../Panel/Panel.h"

class Messagebox : public Panel
{
public:
	Messagebox(int height, int width);
	~Messagebox();
	void setText(const string text);
	void setTitle(const string title);
	void keyDown(WORD code, CHAR chr);
	void getAllControls(vector<Control*>* vector);
	bool canGetFocus();
private:
	string text;
	string title;
};