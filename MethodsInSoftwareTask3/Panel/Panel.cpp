#include "Panel.h"
#include "../Control/EventEngine.h"
#include "../TextBox/TextBox.h"
#include <cassert>

vector<Control*> Panel::focusVec;



Panel::Panel(int height, int width) : Control(width)
{
	this->height = height;
}




void Panel::draw(Graphics& graphics, int left, int top, size_t p)
{
	Control::draw(graphics, left, top, p);
	if(focusVec.empty())
		getAllControls(&focusVec);
	for (auto it = children.begin(); it != children.end(); ++it)
	{
		if((*it)->isVisible() && p==(**it).get_layer())
			(*it)->draw(graphics, left+(this->left), top+(this->top), p);
	}
	auto textbox = dynamic_cast<TextBox*>(getFocus());
	if (textbox)
		textbox->set_cursor(graphics, left, top);
}

void Panel::keyDown(WORD code, CHAR chr) 
{
	try{
	switch (code)
	{
	case VK_UP:
	{
		EventEngine::moveFocusBackword(*this,getFocus());
		break;
	}
	case VK_DOWN:
	{
		EventEngine::moveFocusForword(*this, getFocus());
		break;
	}
	default:
	{
		for (auto it = focusVec.begin(); it != focusVec.end(); ++it)
		{
			if ((*it) == getFocus())
			{
				(*it)->keyDown(code, chr);
				break;
			}

		}
		break;
	}
	}
	}
	catch(exception& e)
	{
		perror("undefined key");
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
				if ((*it)->canGetFocus())
					setFocus(**it);
				(*it)->mousePressed(X, Y, isLeft);
				break;
			}
		}

	}
}


void Panel::getAllControls(vector<Control*>* vec)
{
	for(auto it=children.begin();it!=children.end();++it)
	{
		(*it)->getAllControls(vec);
	}
}


void Panel::addControl(Control& element, int left, int top)
{
	element.set_left(left);
	element.set_top(top);
	children.push_back(&element);
}


Panel::~Panel()
{
}
