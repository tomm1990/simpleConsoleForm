#pragma once
#include "../Textbox/TextBox.h"

class Label : public TextBox
{
public:
	Label(int width);
	void MouseEventProc(MOUSE_EVENT_RECORD) override;
	void KeyEventProc(KEY_EVENT_RECORD) override;
	void Show() override;
	void Hide() override;
	void SetForeground(ForegroundColor color) override;
	void SetBackground(BackgroundColor color) override;
	void SetBorder(BorderType border) override;
	~Label();


};
