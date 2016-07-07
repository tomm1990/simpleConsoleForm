#pragma once
#include "../Control/Control.h"

class Panel :
	public Control
{

protected:
	vector < Control* > children;
	static vector < Control* > focusVec;
public:
	Panel(int height, int width);


	virtual virtual void keyDown(WORD code, CHAR chr) override;
	virtual void mousePressed(int x, int y, bool isLeft) override;
	void draw(Graphics& graphics, int left, int top, size_t p) override;
	virtual void getAllControls(vector<Control*>* vector) override;
	bool canGetFocus() override{return false;};
	void addControl(Control& element, int left, int top);

	virtual void set_layer(size_t layer) override;
	virtual ~Panel();
};



