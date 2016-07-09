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
	void show() override;

protected:
	void addControl(Control&, const int, const int) override;
	bool canGetFocus() override { return false; }
	void draw(Graphics& graphics, const int, const int, const size_t) override ;

private:
	// each MessageBox object contains these :
	Label *title, *description;
	Button *bOK, *bBack;
};
