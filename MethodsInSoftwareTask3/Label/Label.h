#pragma once
#include "../Textbox/TextBox.h"

class Label : public TextBox
{
private:
	string _value;

public:
	Label(int width , string value);
	void SetText(string);
	
	void MouseEventProc(MOUSE_EVENT_RECORD) ;
	void KeyEventProc(KEY_EVENT_RECORD) ;
	
	void setForeground(Color color) override;
	void setBackground(Color color) override;
	void SetBorder(BorderType border) override;

	void draw(Graphics& graphics, int i, int i1, size_t size_t) override;

	void show(){};
	void hide(){};
	~Label();


};
