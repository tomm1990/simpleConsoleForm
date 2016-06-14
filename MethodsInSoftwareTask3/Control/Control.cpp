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

void Control::setBorderDrawer(const BorderDrawer & borderDrawer)
{
	drawer = &borderDrawer;
}

void Control::draw(Graphics& graphics, int left, int top, size_t p)
{
	if (isVisibile){
		graphics.setBackground(backcolor);
		graphics.setForeground(forColor);
		if (drawer!=nullptr) {
			try{ drawer->draw(graphics, left, top, this->getWidth(), this->getHeight()); }
			catch (const std::exception& l){ }
		}
		graphics.moveTo(left, top);
	}
}

SHORT Control::getLeft(){
	return left;
}

SHORT Control::getTop(){
	return top;
}

void Control::setFocus(Control& it){
	onFocus = &it;
}

Control* Control::getFocus(){
	return onFocus;
}

Control::~Control()
{
}

// ReSharper disable once CppPossiblyUninitializedMember
Control::Control(int width) : width(width)
{
}

