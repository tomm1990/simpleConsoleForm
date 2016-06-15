#include "Combox.h"

Combox::Combox(int width, vector<string> options) : Control(width), list(options), isListOpen(false), size(static_cast<SHORT>(options.size())), selection(0)
{
	height = 1;
}



void Combox::open()
{
	height = size;
	isListOpen = true;
}

void Combox::close()
{
	height = 1;
	isListOpen = false;
}


void Combox::mousePressed(int x, int y, bool is)
{
	if (is)
	{
		if (!isListOpen)
		{
			open();
		}
		else
		{
			selection = y;
			close();
		}
	}
}



void Combox::draw(Graphics& graphics, int left, int top, size_t p)
{
	Control::draw(graphics, left, top , 0);
	if (!isListOpen)
	{
		graphics.write(list[selection]);
		auto i = list[selection].size();
		if (i < width)
		{
			for (; i < width; i++, graphics.moveTo(left + i, top))
			{
				if(i==width-1)
				{
					graphics.write("v");
				}
				else
				{
					graphics.write(" ");
				}
				
			}
		}
		graphics.moveTo(left, top);
	}
	else
	{
		for (auto i = 0; i < size; i++, graphics.moveTo(left, top + i))
		{
			graphics.write(list[i]);
			for (auto j = list[i].size(); j < width; j++, graphics.moveTo(left + j, top + i))
			{
				graphics.write(" ");

			}
		}
		graphics.moveTo(left, selection + top);
	}

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
