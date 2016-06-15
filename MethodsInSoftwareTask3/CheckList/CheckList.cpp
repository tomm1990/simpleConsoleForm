#include "CheckList.h"

CheckList::CheckList(int width, vector<string> options) : Control(width), list(options), isListOpen(false), size(static_cast<SHORT>(options.size())), selection(0)
{
	height = 1;
	open();
}



void CheckList::open()
{
	height = size;
	isListOpen = true;
}

void CheckList::close()
{
	isListOpen = false;
}



void CheckList::mousePressed(int x, int y, bool is)
{
	if (is)
	{
			selection = y;
			if(listFlag[y]!=1)
			{
				listFlag[y] = 1;
			}
			else
			{
				listFlag[y] = 0;
			}
			
			close();
	}
}


void CheckList::draw(Graphics& graphics, int left, int top, size_t p)
{
		Control::draw(graphics, left, top, 0);
		if (!isListOpen)
		{
			auto j = list[selection].size();
			for (auto i = 0; i < size; i++, graphics.moveTo(left, top + i))	
			{
				if (listFlag[i]==1)
				{
					graphics.write("[x] " + list[i]);
				}
				if (listFlag[i] != 1) {
					graphics.write("[ ] " + list[i]);
				}
			}
		}
		else
		{
			for (auto i = 0; i < size; i++, graphics.moveTo(left, top + i))
			{
				graphics.write("[ ] "+list[i]);
			}
		}

		graphics.setBackground();
		graphics.setForeground();
		graphics.moveTo(left+1, top);

}

void CheckList::keyDown(WORD code, CHAR chr)
{
	if (!isListOpen && (code == VK_UP || code == VK_DOWN))
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
		break;
	}
	}
}



void CheckList::getAllControls(vector<Control*>* vector)
{
	//	vector->push_back(this);
}

bool CheckList::canGetFocus()
{
	return true;
}
