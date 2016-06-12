#pragma once
#include "../Control/Control.h"

class Combox:
	public Control
{
private:
	vector<string> list;
	bool isListOpen;
	size_t size;
	int selection;

public:
	Combox(int width, vector<string> options);

	void SetBorder(BorderType border) override;

	void open();
	void close();

	void setBackground(Color color) override;
	void draw(Graphics& graphics, int left, int top, size_t p) override;
	void keyDown(WORD code, CHAR chr) override;
	void mousePressed(int x, int y, bool isLeft) override;
	void getAllControls(vector<Control*>* vector) override;
	bool canGetFocus() override;
};
