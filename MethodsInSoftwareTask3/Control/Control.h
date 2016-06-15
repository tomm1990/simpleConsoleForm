#pragma once
#include <Windows.h>
#include <vector>
#include <iostream>
#include <string>
#include "Graphics.h"
#include "BorderDrawer.h"

using namespace std;

enum class BorderType
{
	Single, Double, None
};

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class Control
{
protected:
	int width, height, left = 0, top = 0;
	bool isVisibile;
	Color forColor = Color::Black;
	BorderDrawer* drawer=nullptr; //changed to nullptr to note Panels
	Color backcolor = Color::White;
	static Control* onFocus;

public:
	virtual void keyDown(WORD code, CHAR chr)=0;
	virtual void mousePressed(int x, int y, bool isLeft)=0;

	virtual ~Control() = 0;
	explicit Control(int width);
	virtual void show() { isVisibile = true; }
	virtual void hide() { isVisibile = false; }
	virtual void setForeground(Color color = Color::White);
	virtual void setBackground(Color color);
	virtual void setBorderDrawer(BorderType type);
	virtual void draw(Graphics& graphics, int left, int top, size_t p)=0;
	virtual SHORT getLeft();
	virtual SHORT getTop();
	int getWidth() const { return width; }
	int getHeight() const { return height; }
	void set_left(int left) { this->left = left; }
	void set_top(int top) { this->top = top; }

	virtual void getAllControls(vector<Control*>* vector)=0;
	virtual bool canGetFocus()=0;
	static void setFocus(Control& it);
	static Control* getFocus();
};
