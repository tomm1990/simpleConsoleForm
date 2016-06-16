#include "CheckList.h"

CheckList::CheckList(int height,int width, vector<string> options) : Control(width), list(options), isListOpen(false), size(static_cast<SHORT>(options.size())), selection(0)
{
	this->height = height;
}




void CheckList::mousePressed(int x, int y, bool is)
{
	if (is)
	{
		selection = y;
		if (listFlag[y] != 1)
		{
			listFlag[y] = 1;
		}
		else
		{
			listFlag[y] = 0;
		}
	}
}


void CheckList::draw(Graphics& graphics, int left, int top, size_t p)
{
	Control::draw(graphics, left, top, 0);
		auto j = list[selection].size();
		for (auto i = 0; i < size; i++, graphics.moveTo(left, top + i))
		{
			if (listFlag[i] == 1)
			{
				graphics.write("[x] " + list[i]);
			}
			if (listFlag[i] != 1) {
				graphics.write("[ ] " + list[i]);
			}
		}
	graphics.setBackground();
	graphics.setForeground();
	graphics.moveTo(left + 1, top+selection);

}

void CheckList::keyDown(WORD code, CHAR chr)
{
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
		if (listFlag[selection] != 1)
		{
			listFlag[selection] = 1;
		}
		else
		{
			listFlag[selection] = 0;
		}
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