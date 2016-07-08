#include "Control.h"
#include <cassert>

Control* Control::onFocus;


void Control::setForeground(Color color)
{
	forColor = color;
}

void Control::setBackground(Color color)
{
	backcolor = color;
}

void Control::setBorder(BorderType type)
{
	if (drawer) { delete(drawer); }
	switch (type)
	{
	case BorderType::None:
	{
		drawer = new NoneBorder();
		break;
	}
	case BorderType::Single:
	{
		drawer = new SingleBorder();
		break;
	}
	case BorderType::Double:
	{
		drawer = new DoubleBorder();
		break;
	}
	}
}

void Control::draw(Graphics& graphics, int left, int top, size_t p)
{
	graphics.setBackground(backcolor);
	graphics.setForeground(forColor);
	if (get_layer() != p) return;
	try 
	{
		if (!drawer) throw exception();	
	}
	catch(exception &e)
	{
	drawer = new NoneBorder();
	}
	drawer->draw(graphics, left + this->left, top + this->top, this->getWidth(), this->getHeight());		
	graphics.moveTo(left, top);
}

SHORT Control::getLeft(){
	return left;
}

SHORT Control::getTop(){
	return top;
}

size_t Control::get_layer() const
{
	return layer;
}

void Control::set_layer(size_t layer)
{
	this->layer = layer;
}

void Control::getAllControls(vector<Control*>* vector)
{
	if(canGetFocus())
	vector->push_back(this);
}



void Control::setFocus(Control& it) {
	if (onFocus)
	{	
		swap(onFocus->get_background(), onFocus->get_forground());
	}
	swap(it.backcolor, it.forColor);
	onFocus = &it;
}

Control* Control::getFocus(){
	return onFocus;
}

void Control::set_width(int width)
{
	this->width = width;
}

void Control::set_height(int height)
{
	this->height = height;
}

Control::~Control()
{
	if (drawer)
		delete(drawer);
}

// ReSharper disable once CppPossiblyUninitializedMember
Control::Control(int width) : width(width),height(1),layer(0)
{
}

