#pragma once
#include "../Control/Control.h"

class Combox:
	public Control
{
private:
	vector<string> list;
	bool isListOpen;
	string currentWord;
	size_t cursorCurrent;
	size_t size;
public:
	Combox(int width, vector<string> options);
	void SetForeground(Color color) override;
	void SetBackground(Color color) override;
	void SetBorder(BorderType border) override;

	void open();
	void KeyEventProc(KEY_EVENT_RECORD mer) override;
	void MouseEventProc(MOUSE_EVENT_RECORD mer) override;

	void draw(Graphics& graphics, int left, int top, size_t p) override;
	void keyDown(WORD code, CHAR chr) override;
	void mousePressed(int x, int y, bool isLeft) override;
	void getAllControls(vector<Control*>* vector) override;
	bool canGetFocus() override;
};
