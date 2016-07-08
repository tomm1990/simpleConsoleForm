#pragma once
#include "../Panel/Panel.h"
#include "../Label/Label.h"
#include "../Button/Button.h"

class Messagebox : public Panel{
public:
	Messagebox(int height, int width);
	virtual ~Messagebox();
	void setText(string text );
	void setTitle(string title );
	bool canGetFocus() override;

	virtual void show() override;
private:
	Label *title, *description;
	Button *bOK, *bBack;
};
