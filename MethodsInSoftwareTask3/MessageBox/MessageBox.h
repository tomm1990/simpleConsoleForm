#pragma once
#include "../Panel/Panel.h"
#include "../Label/Label.h"
#include "../Button/Button.h"

class Messagebox : public Panel{
public:
	Messagebox(int height, int width);
	~Messagebox();
	void setText(string text );
	void setTitle(string title );
	void keyDown(WORD code, CHAR chr);
	void getAllControls(vector<Control*>* vector);
	bool canGetFocus();
private:
	Label *title, *description;
	Button *bOK, *bBack;
};
