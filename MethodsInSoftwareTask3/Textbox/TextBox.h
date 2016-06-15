#pragma once
#include "../Control/Control.h"

class TextBox: public Control{
public:
	TextBox(int width);
	virtual void keyDown(WORD code, CHAR chr) override;
	virtual void mousePressed(int x, int y, bool isLeft) override;
	void getAllControls(vector<Control*>* vector) override;
	bool canGetFocus() override;
	void draw(Graphics& graphics, int left, int top, size_t p) override;
	string getValue() const;
	void setValue(const string& value);

private:
	string value;
	int cursor;
};
