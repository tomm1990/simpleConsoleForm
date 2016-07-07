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
	bool visibility;
	Color forColor = Color::Black;
	BorderDrawer* drawer=nullptr; 
	size_t layer = 0;
	Color backcolor = Color::White;
	static Control* onFocus;



public:
	virtual void keyDown(WORD code, CHAR chr)=0;
	virtual void mousePressed(int x, int y, bool isLeft)=0;
	
	size_t get_layer() const;
	virtual void set_layer(size_t layer);
	void set_width(int width);
	void set_height(int height);
	virtual ~Control() = 0;
	explicit Control(int width);
	virtual void show() { visibility = true; }
	virtual void hide() { visibility = false; }
	bool isVisible() const{ return visibility; }
	virtual void setForeground(Color color = Color::White);
	virtual void setBackground(Color color);
	virtual Color& get_forground() { return forColor; };
	virtual Color& get_background() { return backcolor; };
	virtual void setBorder(BorderType type);
	virtual void draw(Graphics& graphics, int left, int top, size_t p)=0;
	virtual SHORT getLeft();
	virtual SHORT getTop();
	int getWidth() const { return width; }
	int getHeight() const { return height; }
	void set_left(int left) { this->left = left; }
	void set_top(int top) { this->top = top; }
	
	template<typename T> static void swap(T& a, T& b);


	virtual void getAllControls(vector<Control*>* vector);
	virtual bool canGetFocus() { return true; };
	static void setFocus(Control& it);
	static Control* getFocus();
};

template <typename T>
void Control::swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
