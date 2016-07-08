#include "Scrollable.h"


void Scrollable::setSelectedIndex(size_t i)
{
	this->index = i;
	update();
}

size_t Scrollable::getSelectedIndex() const
{
	return index;
}

Scrollable::Scrollable(int width, vector<string> list): Panel(list.size(), width), index(0), size(list.size())
{
	for(auto i=0;i<size;i++)
	{
		valsMap[list[i]] = false;
	}
}


