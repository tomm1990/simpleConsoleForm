#pragma once
#include "../Control/Control.h"

class CheckList:
	public Control
{
public:
	CheckList(int height, int width, vector<string> options);
	void MouseEventProc(MOUSE_EVENT_RECORD) ;
	void KeyEventProc(KEY_EVENT_RECORD) ;
	void setForeground(Color color) override;
	void setBackground(Color color) override;
	void SetBorder(BorderType border) override;
	virtual ~CheckList();
	void draw(Graphics& graphics, int left, int top, size_t p) override;
	void keyDown(WORD code, CHAR chr) override;
	void mousePressed(int x, int y, bool isLeft) override;
	void getAllControls(vector<Control*>* vector) override;
	bool canGetFocus() override;
};
