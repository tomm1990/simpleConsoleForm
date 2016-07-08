#pragma once
#include "../Panel/Panel.h"
#include "../Label/Label.h"
#include "../Button/Button.h"

class NumericBox : public Panel{
public:
	NumericBox(int, const int, const int);
	virtual ~NumericBox();
	string getValue() const { return to_string(number); }
	void setValue(const int value);
	Label* getLabel() const { return val; }
	void SetText(const Label& l, string newText) const { val->setValue(newText); }
private:
	int min, max , number = 20;
	Label *val;
	Button *bUP, *bDOWN;
};