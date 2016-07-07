#include "Scrollable.h"


void Scrollable::setSelectedIndex(size_t index)
{
	this->index = index;
	update();
}

size_t Scrollable::getSelectedIndex() const
{
	return index;
}

Scrollable::Scrollable(int width, vector<string> list): Panel(list.size(), width),list(list), index(0), size(list.size())
{
}


