#pragma once
#include "../Control/Control.h"

class TextBox:
	public Control
{
protected:
	string _value;
	int _textLength, counter;

	struct textBoxBorder {
		char top_left = '\xDA';
		char horizontal_line = '\xC4';
		char top_right = '\xBF';
		char vertical_line = '\xB3';
		char buttom_left = '\xC0';
		char buttom_right = '\xD9';
	} _textBoxBorder;

public:
	TextBox(const int width);
	virtual ~TextBox();
	void MouseEventProc(MOUSE_EVENT_RECORD) override;
	void KeyEventProc(KEY_EVENT_RECORD) override;
	
	void SetForeground(Color color) override;
	void SetBackground(Color color) override;
	void SetBorder(BorderType border) override;
	void SetText(string value);
	string getValuse();

	void draw(const Graphics& graphics, int i, int i1, size_t size_t) override;
	//virtual void draw(const Graphics& graphics, int i, int i1);
	
	void keyDown(WORD code, CHAR chr) override;
	void mousePressed(int i, int y, bool b) override;
	void getAllControls(vector<Control*>* vector) override;
	bool canGetFocus() override;

};
