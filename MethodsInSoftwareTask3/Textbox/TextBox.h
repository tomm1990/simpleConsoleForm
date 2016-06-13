#pragma once
#include "../Control/Control.h"

class TextBox: public Control
{
public:

	TextBox(int width);
	void keyDown(WORD code, CHAR chr) override;
	void mousePressed(int x, int y, bool isLeft) override;
	void SetBorder(BorderType border) override;
	void getAllControls(vector<Control*>* vector) override;
	bool canGetFocus() override;

	void draw(Graphics& graphics, int left, int top, size_t p) override;
	string get_value() const;
	void set_value(const string& value);
private:
	string value;
	int cursor;
};
