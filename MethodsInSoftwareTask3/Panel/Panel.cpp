#include "Panel.h"



Panel::Panel(int height, int width) : Control(width)
{
	this->height = height;
}




void Panel::draw(Graphics& graphics, int left, int top, size_t p)
{
	Control::draw(graphics, left, top, 0);
	for (auto it = children.begin(); it != children.end(); ++it)
	{
		if((*it)->isVisible()) (*it)->draw(graphics, left+(this->left), top+(this->top), p);
	}
	//getFocus()->draw(graphics, getFocus()->getLeft(), getFocus()->getTop(),p);
}

void Panel::keyDown(WORD code, CHAR chr) {
	for (auto it=children.begin(); it != children.end(); ++it)
	{
		if((*it)==Control::getFocus())
		{
			(*it)->keyDown(code, chr);
		}
		
	}
}

void Panel::mousePressed(int x, int y, bool isLeft)
{
	if (isLeft)
	{
		for (auto it = children.begin(); it != children.end(); ++it)
		{
			int X = x - (*it)->getLeft();
			int Y = y - (*it)->getTop();
			if (X >= 0 && Y >= 0 && X < (*it)->getWidth() && Y < (*it)->getHeight())
			{
				(*it)->mousePressed(X, Y, isLeft);
				setFocus(**it);
				break;
			}
		}

	}
}


void Panel::getAllControls(vector<Control*>* vector)
{
	*vector = children;
}



void Panel::setForeground(Color color)
{
	for(auto it=children.begin();it!=children.end();++it)
	{
		(**it).setForeground(color);
	}
	Control::setForeground(color);
}

void Panel::setBackground(Color color)
{
	for (auto it = children.begin(); it != children.end(); ++it)
	{
		(**it).setBackground(color);
	}
	Control::setBackground(color);
}

bool Panel::canGetFocus()
{
	return false;
}

void Panel::addControl(Control& element, int left, int top)
{
	element.set_left(left);
	element.set_top(top);
	children.push_back(&element);
	setFocus(element);
}


Panel::~Panel()
{
}
