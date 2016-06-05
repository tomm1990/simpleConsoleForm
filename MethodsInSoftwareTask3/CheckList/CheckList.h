#pragma once
#include "../Control/Control.h"

class CheckList:
	public Control
{
public:
	CheckList(int height, int width, vector<string> options);
	void MouseEventProc(MOUSE_EVENT_RECORD) override;
	void KeyEventProc(KEY_EVENT_RECORD) override;
	void Show() override;
	void Hide() override;
	void SetForeground(ForegroundColor color) override;
	void SetBackground(BackgroundColor color) override;
	void SetBorder(BorderType border) override;
	virtual ~CheckList();
	void draw(const Graphics& graphics, int i, int i1, size_t size_t) override;
	void keyDown(WORD code, CHAR chr) override;
	void mousePressed(int i, int y, bool b) override;
	void getAllControls(vector<Control*>* vector) override;
	bool canGetFocus() override;
};
