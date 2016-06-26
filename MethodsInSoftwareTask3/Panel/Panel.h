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
	virtual void mousePressed(int x, int y, bool isLeft) override;
	void draw(Graphics& graphics, int left, int top, size_t p) override;
	void getAllControls(vector<Control*>* vector) override;

	void setForeground(Color color) override;
	void setBackground(Color color) override;
	bool canGetFocus() override;
	void addControl(Control& element, int left, int top);
	virtual ~Panel();
};

