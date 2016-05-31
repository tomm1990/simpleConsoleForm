#pragma once
#include "Container.h"

class Root :
	public Container
{
private:
	Root(int width): Container(width)
	{
	};

	static Root* root;

public:
	virtual ~Root()
	{
	};

	void SetForeground(ForegroundColor color) override
	{
	};

	void SetBackground(BackgroundColor color) override
	{
	};

	void SetBorder(BorderType border) override
	{
	};

	void Show() override
	{
	};

	void Hide() override
	{
	};

	void MouseEventProc(MOUSE_EVENT_RECORD) override;
	void KeyEventProc(KEY_EVENT_RECORD) override;

	static Root* getInstance(int width)
	{
		if (!root)
		{
			root = new Root(width);
		}
		return root;
	};


	void draw(const Graphics& graphics, int i, int i1, size_t size_t) override;
	void keyDown(WORD code, CHAR chr) override;
	void mousePressed(int i, int y, bool b) override;
	void getAllControls(vector<Control*>* vector) override;
	bool canGetFocus() override;
};


Root* Root::root;
