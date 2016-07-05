#include "RadioList.h"

RadioList::RadioList(int height,int width, vector<string> options) : Panel(height,width), list(options){
	this->height = height;
}

