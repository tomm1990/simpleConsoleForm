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

class Control{
public:
	virtual void keyDown(const WORD, const CHAR ) = 0;
	virtual void mousePressed(const int, const int, const bool) = 0;
	virtual size_t get_layer() const;
	virtual void set_layer(const size_t);
	void set_width(const int);
	void set_height(const int);
	virtual ~Control();
	explicit Control(const int);
	virtual void show() { visibility = true; }
	virtual void hide() { visibility = false; }
	bool isVisible() const { return visibility; }
	virtual void setForeground(const Color color = Color::White);
	virtual void setBackground(const Color);
	virtual Color& get_forground() { return forColor; }
	virtual Color& get_background() { return backcolor; }
	virtual void setBorder(const BorderType);
	virtual void draw(Graphics&, const int, const int, const size_t) = 0;
	virtual SHORT getLeft() { return left; }
	virtual SHORT getTop() { return top; }
	
	void set_left(const int left) { this->left = left; }
	void set_top(const int top) { this->top = top; }
	virtual void getAllControls(vector<Control*>* vector);
	virtual bool canGetFocus() { return true; }
	static void setFocus(Control& it);
	static Control* getFocus() { return onFocus; }
	template<typename T> static void swap(T& a, T& b);		// swap tool
	int getWidth() const { return width; }
	int getHeight() const { return height; }

protected:
	int width, height, left = 0, top = 0;
	bool visibility;
	Color forColor = Color::Black;
	BorderDrawer* drawer = nullptr;
	size_t layer = 0;
	Color backcolor = Color::White;
	static Control* onFocus;
};