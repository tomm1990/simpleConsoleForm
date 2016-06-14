#pragma once
#include "../Control/Control.h"

class Panel :
	public Control
{
private:
	vector < Control* > children;
public:
	Panel(int height, int width);


	void keyDown(WORD code, CHAR chr) override;
	void mousePressed(int x, int y, bool isLeft) override;
	void draw(Graphics& graphics, int left, int top, size_t p) override;
	void getAllControls(vector<Control*>* vector) override;
	bool canGetFocus() override;
	void addControl(Control& element, int left, int top);
	virtual ~Panel();
};

