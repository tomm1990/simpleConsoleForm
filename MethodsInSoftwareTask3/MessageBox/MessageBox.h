#pragma once
#include "../Panel/Panel.h"
#include "../Label/Label.h"
#include "../Button/Button.h"

class Messagebox : public Panel{
public:
	Messagebox(const int, const int);
	virtual ~Messagebox();
	void setText(string);
	void setTitle(string);
	bool canGetFocus() override { return false; }
	void show() override;
private:
	// each MessageBox object contains these :
	Label *title, *description;
	Button *bOK, *bBack;
};
