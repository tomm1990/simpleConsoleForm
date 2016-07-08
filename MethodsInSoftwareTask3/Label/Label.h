#pragma once
#include "../Textbox/TextBox.h"

class Label : public TextBox{
public:
	Label(const int , const string);
	Label(const int);
	virtual ~Label(){ }
	void SetText(const string);
	virtual void draw(Graphics&, const int, const int, const size_t) override;
	bool canGetFocus() override { return false; }
	virtual void keyDown(const WORD, const CHAR) override { }
	virtual void mousePressed(const int, const int, const bool) override { }
	virtual void set_cursor( Graphics&, const int, const int) override;
};