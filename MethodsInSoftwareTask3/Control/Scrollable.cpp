#include "Scrollable.h"


Scrollable::Scrollable(int height, int width, vector<string> list): Panel(height, width), cursor(0),selection(0),list(list),size(list.size())
{
}

void Scrollable::keyDown(WORD code, CHAR chr)
{
	
	if ((code == VK_UP || code == VK_DOWN))
	{
		
		return;
	}
	switch (code)
	{
	case VK_UP:
	{
		if (cursor == 0)
		{
			cursor = size - 1;
		}
		else
		{
			--cursor;
		}
		break;
	}
	case VK_DOWN:
	{
		if (cursor < size - 1)
		{
			cursor++;
		}
		else
		{
			cursor = 0;
		}
		break;
	}
	case VK_RETURN:
	{
		selection=cursor;
		break;
	}
	}
	
}
