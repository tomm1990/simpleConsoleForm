#include "Combox.h"
#include "../Button/Button.h"


Combox::Combox(int width, vector<string> options) :Panel(options.size(), width),list(options),isListOpen(false), size(options.size()), selection(0)
{
	height = 1;
	onClick = [&]()
	{
		if (this->isListOpen)
		{
			this->close();
		}
		else
		{
			this->open();
		}
	};
}



void Combox::open()
{
	height = size;
	set_layer(1);
	isListOpen = true;
}

void Combox::close()
{
	height = 1;
	set_layer(0);
	isListOpen = false;
}


Combox::~Combox()
{
	delete (button);
}

void Combox::mousePressed(int x, int y, bool isLeft)
{
	if(x== button->getLeft()-left && y== button->getTop()-top)
	{
		button->mousePressed(x,y,isLeft);
		return;
	}
	if (isListOpen)
	{
		selection = y;
		close();
	}
}

void Combox::draw(Graphics& graphics, int left, int top, size_t p)
{
	Control::draw(graphics, left, top, p);
	if (!isListOpen)
	{
		graphics.write(left,top,list[selection]);
		graphics.moveTo(left, top);
	}
	else
	{
		for (auto i = 0; i < size; i++, graphics.moveTo(left, top + i))
		{
			graphics.write(list[i]);
		}
		graphics.moveTo(left, selection + top);
	}
	if (!button)
	{
		button = new Button(1);
		button->addListener(onClick);
		button->setValue("v");
		addControl(*button, width - 1, 0);
	}
	button->draw(graphics, button->getLeft(), button->getTop(), p);
	graphics.setBackground();
	graphics.setForeground();
	
}

void Combox::keyDown(WORD code, CHAR chr)
{
	if (!isListOpen && (code==VK_UP  || code == VK_DOWN))
	{
		open();
		return;
	}
	switch (code)
	{
	case VK_UP:
	{
		if (selection == 0)
		{
			selection = size - 1;
		}
		else
		{
			--selection;
		}
		break;
	}
	case VK_DOWN:
	{
		if (selection < size - 1)
		{
			selection++;
		}
		else
		{
			selection = 0;
		}
		break;
	}
	case VK_RETURN:
	{
		isListOpen = false;
		close();
		break;
	}
	}
}



void Combox::getAllControls(vector<Control*>* vector)
{
//	vector->push_back(this);
}

bool Combox::canGetFocus()
{
	return true;
}
