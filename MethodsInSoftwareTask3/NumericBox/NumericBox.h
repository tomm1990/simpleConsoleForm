#pragma once
#include "../Panel/Panel.h"
#include "../Label/Label.h"
#include "../Button/Button.h"

class NumericBox : public Panel{
public:
	NumericBox(int width, int min, int max);
	~NumericBox();
	string getValue() const;
	void setValue(const string& value);
	Label* getLabel() const { return val; }
	void SetText(Label& l, string newText){	val->setValue(newText);}

private:
	void addControl(Control& element, int left, int top) ;
	int min, max , number = 20;
	Label *val;
	Button *bUP, *bDOWN;
};
