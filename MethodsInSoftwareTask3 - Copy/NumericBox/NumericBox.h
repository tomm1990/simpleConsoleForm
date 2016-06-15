#pragma once
#include "../Label/Label.h"

class NumericBox : public Label
{
public:
	NumericBox(int width, int min, int max);
	~NumericBox();

	void draw(Graphics& graphics, int left, int top, size_t p);
	void keyDown(WORD code, CHAR chr) override;
	void mousePressed(int x, int y, bool isLeft) override;


	string getValue() const override;
	void setValue(const string& value) override;
	bool canGetFocus() override;
private:
	int min, max , number = 20;
};

