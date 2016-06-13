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

void Control::draw(Graphics& graphics, int left, int top, size_t p)
{
	if (isVisibile)
	{
		graphics.moveTo(left, top);
		graphics.setBackground(backcolor);
		graphics.setForeground(forColor);
	}
}

SHORT Control::getLeft()
{
	//return position.X;
	return left;
}

SHORT Control::getTop()
{
	//return position.Y;
	return top;
}

void Control::setFocus(Control& it)
{
	onFocus = &it;
}

Control* Control::getFocus()
{
	return onFocus;
}

Control::~Control()
{
}

// ReSharper disable once CppPossiblyUninitializedMember
Control::Control(int width) : width(width)
{

}

