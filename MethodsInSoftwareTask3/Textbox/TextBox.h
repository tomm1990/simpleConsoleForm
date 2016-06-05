#pragma once
#include "../Control/Control.h"

class TextBox:
	public Control
{
protected:
	string _value;
	int _textLength, _widthTextBox, counter;


public:
	TextBox(int width);
	virtual ~TextBox();
	void MouseEventProc(MOUSE_EVENT_RECORD) override;
	void KeyEventProc(KEY_EVENT_RECORD) override;
	void Show() override;
	void Hide() override;
	void SetForeground(ForegroundColor color) override;
	void SetBackground(BackgroundColor color) override;
	void SetBorder(BorderType border) override;
	void SetText(string value);
	string getValuse();

	void draw(const Graphics& graphics, int i, int i1, size_t size_t) override;
	void keyDown(WORD code, CHAR chr) override;
	void mousePressed(int i, int y, bool b) override;
	void getAllControls(vector<Control*>* vector) override;
	bool canGetFocus() override;

};
