#pragma once
#include "../Control/Control.h"

class TextBox: public Control{
public:
	TextBox(const int);
	virtual ~TextBox() { }
	virtual void keyDown(const WORD, const CHAR) override;
	virtual void mousePressed(const int, const int, const bool) override;
	virtual void draw(Graphics&, const int, const int, const size_t) override;
	virtual string getValue() const;
	virtual void setValue(const string&);
	virtual void set_cursor(Graphics&,const int, const int);
private:
	string value;
	int cursor;
};