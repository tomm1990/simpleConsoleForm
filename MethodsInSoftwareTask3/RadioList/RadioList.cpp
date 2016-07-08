#include "RadioList.h"

RadioList::RadioList(int height,int width, vector<string> options) : Scrollable(width,options){
	this->height = height;
}

void RadioList::update(size_t index)
{
}
