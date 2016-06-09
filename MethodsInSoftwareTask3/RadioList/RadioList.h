#pragma once
#include "../Control/Control.h"

class RadioList:
	public Control
{
public:
	RadioList(int width);
	void MouseEventProc(MOUSE_EVENT_RECORD) override;
	void KeyEventProc(KEY_EVENT_RECORD) override;
	~RadioList() override;
	void SetForeground(Color color) override;
	void SetBackground(Color color) override;
	void SetBorder(BorderType border) override;

	void draw(Graphics& graphics, int left, int top, size_t p) override;
	void keyDown(WORD code, CHAR chr) override;
	void mousePressed(int x, int y, bool isLeft) override;
	void getAllControls(vector<Control*>* vector) override;
	bool canGetFocus() override;
};
