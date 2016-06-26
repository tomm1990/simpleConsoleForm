#include "Control.h"

Control* Control::onFocus;


void Control::setForeground(Color color)
{
	forColor = color;
}

void Control::setBackground(Color color)
{
	backcolor = color;
}

void Control::setBorderDrawer(BorderType type)
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
		try 
		{
			if (!drawer) throw exception();	
			drawer->draw(graphics, left, top, this->getWidth(), this->getHeight());
		}
		catch(exception){}
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
}

bool Control::canGetFocus()
{
	return true;
}

void Control::setFocus(Control& it){
	onFocus = &it;
}

Control* Control::getFocus(){
	return onFocus;
}

Control::~Control()
{
	if (drawer)
		delete(drawer);
}

// ReSharper disable once CppPossiblyUninitializedMember
Control::Control(int width) : width(width)
{
}

