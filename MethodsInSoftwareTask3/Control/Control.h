#pragma once
#include <Windows.h>
#include <vector>
#include <iostream>
#include <string>
#include "ForegroundColor.h"
#include "BackgroundColor.h"
#include "BorderType.h"
#include "Graphics.h"

using namespace std;

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class Control
{
protected:
	HANDLE hOut;
	HANDLE hIn;
	COORD dim;
	DWORD fontColor;
	int width, height, left = 0, top = 0;
	COORD position;
	bool isVisibile;
	Color forColor = Color::Black;
	Color backcolor = Color::White;
	BorderType border;
	Graphics graphics;
	static Control* onFocus;

public:
	virtual void keyDown(WORD code, CHAR chr) = 0;
	virtual void mousePressed(int x, int y, bool isLeft) = 0;

	virtual ~Control() = 0;
	explicit Control(int width);
	virtual void show() { isVisibile = true; }
	virtual void hide() { isVisibile = false; }
	void getCursorXY(SHORT& x, SHORT& y) const;
	void setConsole_CursorPos_TextAttr(const HANDLE handle, const COORD, const int);
	virtual void setForeground(Color color = Color::White);
	virtual void setBackground(Color color) = 0;
	virtual void SetBorder(BorderType border) = 0;
	virtual void draw(Graphics& graphics, int left, int top, size_t p);
	virtual SHORT getLeft();
	virtual SHORT getTop();
	int getWidth() const { return width; }
	int getHeight() const { return height; }
	void set_left(int left) { this->left = left; }
	void set_top(int top) { this->top = top; }

	virtual void getAllControls(vector<Control*>* vector) =0;
	virtual bool canGetFocus() =0;
	static void setFocus(Control& it);
	static Control* getFocus();
};
