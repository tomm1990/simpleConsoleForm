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


#define NO_BORDER 's'
#define SINGLE_BORDER 'd'
#define DOUBLE_BORDER 'f'

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class Control
{
	static Control* Focus;
protected:
	HANDLE hOut;
	HANDLE hIn;
	COORD dim;
	DWORD fontColor;
	int width;
	COORD position;
	bool isVisibile;
	Color forColor;
	Color backcolor;
	BorderType border;
	Graphics graphics;
public:
	virtual void MouseEventProc(MOUSE_EVENT_RECORD) =0;
	virtual void KeyEventProc(KEY_EVENT_RECORD) =0;
	virtual void keyDown(WORD code, CHAR chr) = 0;
	virtual void mousePressed(int x, int y, bool isLeft) = 0;

	virtual ~Control() =0;
	 Control(int width);
	virtual void Show();
	virtual void Hide();
	void getCursorXY(SHORT& x, SHORT& y) const;
	void setConsole_CursorPos_TextAttr(const HANDLE handle, const COORD, const int);
	virtual void SetForeground(Color color) =0;
	virtual void SetBackground(Color color) =0;
	virtual void SetBorder(BorderType border) =0;
	virtual void draw(Graphics& graphics, int left, int top, size_t p) = 0;
	virtual SHORT getLeft();
	virtual SHORT getTop();
	virtual void getAllControls(vector<Control*>* vector) =0;
	virtual bool canGetFocus() =0;
	static void setFocus(const Control& it);
	static Control* getFocus();
};
