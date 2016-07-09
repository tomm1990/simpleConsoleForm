#pragma once
#include "../Panel/Panel.h"
#include "../Label/Label.h"
#include "../Button/Button.h"

class NumericBox : public Panel{
public:
	NumericBox(int, const int, const int);
	virtual ~NumericBox();
	string getValue() const { return to_string(number); }
	void setValue(const int);
	Label* getLabel() const { return val; }
	void SetText(const Label&, string newText) const { val->setValue(newText); }
private:
	int min, max , number = 20;		// default value
	Label *val;						// Label object for value
	Button *bUP, *bDOWN;			// plus and minus buttons
};