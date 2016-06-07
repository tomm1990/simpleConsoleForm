#pragma once
#include "../Control/Control.h"

class Panel :
	public Control
{
public:
	Panel(int height, int width);
	void MouseEventProc(MOUSE_EVENT_RECORD) override;
	void KeyEventProc(KEY_EVENT_RECORD) override;
	void SetForeground(Color color) override;
	void SetBackground(Color color) override;
	void SetBorder(BorderType border) override;
	void draw(const Graphics& graphics, int i, int i1, size_t size_t) override;
	void keyDown(WORD code, CHAR chr) override;
	void mousePressed(int i, int y, bool b) override;
	void getAllControls(vector<Control*>* vector) override;
	bool canGetFocus() override;
	virtual ~Panel();
};

