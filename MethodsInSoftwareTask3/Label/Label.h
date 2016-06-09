#pragma once
#include "../Textbox/TextBox.h"

class Label : public TextBox
{
private:
	string _value;

public:
	Label(int width , string value);
	void SetText(string);
	
	void MouseEventProc(MOUSE_EVENT_RECORD) override;
	void KeyEventProc(KEY_EVENT_RECORD) override;
	
	void SetForeground(Color color) override;
	void SetBackground(Color color) override;
	void SetBorder(BorderType border) override;

	void draw(Graphics& graphics, int i, int i1, size_t size_t) override;

	void Show(){};
	void Hide(){};
	~Label();


};
