#pragma once
#include "../Control/Control.h"

class TextBox: public Control{
public:
	TextBox(int width);
	virtual void keyDown(WORD code, CHAR chr) override;
	virtual void mousePressed(int x, int y, bool isLeft) override;
	bool canGetFocus() override;
	virtual void draw(Graphics& graphics, int left, int top, size_t p) override;
	virtual string getValue() const;
	virtual void setValue(const string& value);

private:
	string value;
	int cursor;
};
