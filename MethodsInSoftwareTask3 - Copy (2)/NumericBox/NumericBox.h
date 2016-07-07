#pragma once
#include "../Panel/Panel.h"
#include "../Label/Label.h"
#include "../Button/Button.h"

class NumericBox : public Panel{
public:
	NumericBox(int width, int min, int max);
	~NumericBox();
	string getValue() const;
	void setValue(int value);
	Label* getLabel() const { return val; }
	void SetText(Label& l, string newText){	val->setValue(newText);}

private:
	int min, max , number = 20;
	Label *val;
	Button *bUP, *bDOWN;
};
