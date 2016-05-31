#include "Container.h"

void Container::add(Control* element)
{
	elements.push_back(element);
}

void Container::traverse()
{
}

Container::Container(int width): Control(width)
{
}

Container::~Container()
{
}
