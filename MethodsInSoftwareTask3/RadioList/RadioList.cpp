#include "RadioList.h"

RadioList::RadioList(int height,int width, vector<string> options) : Panel(height,width), list(options), size(static_cast<SHORT>(options.size())), selection(0){
	this->height = height;
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
