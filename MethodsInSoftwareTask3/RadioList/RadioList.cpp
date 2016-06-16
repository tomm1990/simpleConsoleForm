#include "RadioList.h"

RadioList::RadioList(int height,int width, vector<string> options) : Control(width), list(options), size(static_cast<SHORT>(options.size())), selection(0){
	this->height = height;
}


void RadioList::mousePressed(int x, int y, bool is){
	if (is)	
	{
		selection = y;	
	}
}

void RadioList::draw(Graphics& graphics, int left, int top, size_t p)
{
	Control::draw(graphics, left, top, 0);
	for(auto i=0;i<size;i++)
	{
		if(i==selection)
		{
			graphics.write(left, top + i, "(*) " + list[i]);
		}
		else
		{
			graphics.write(left, top + i,"( ) "+list[i]);
		}
	}
	graphics.moveTo(left + 1, selection + top);
	graphics.setBackground();
	graphics.setForeground();
}

void RadioList::keyDown(WORD code, CHAR chr){
	switch (code) {
		case VK_UP:
		{
			if (selection == 0)	selection = size - 1;
			else --selection;
			break;
		}
		case VK_DOWN:
		{
			if (selection < size - 1) selection++;
			else selection = 0;
			break;
		}
		case VK_RETURN:
		{
			break;
		}
	}
	
}
