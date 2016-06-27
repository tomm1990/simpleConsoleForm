#include "CheckList.h"

CheckList::CheckList(int height,int width, vector<string> options) : Panel(height,width), list(options), isListOpen(false), size(static_cast<SHORT>(options.size())), selection(0)
{
	this->height = height;
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