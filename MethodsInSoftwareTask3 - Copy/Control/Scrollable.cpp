#include "Scrollable.h"
#include "EventEngine.h"


Scrollable::Scrollable(int width, vector<string> list): Panel(list.size(), width), cursor(0),selection(0),list(list),size(list.size())
{
}



void Scrollable::keyDown(WORD code, CHAR chr)
{
	if(code==VK_RETURN && 	this != getFocus())	
	{
		mark();
	}
}

void Scrollable::getAllControls(vector<Control*>* vec)
{
	vec->push_back(this);
	Panel::getAllControls(vec);
}


int Scrollable::get_cursor() const
{
	return cursor;
}

void Scrollable::set_cursor(int cursor)
{
	this->cursor = cursor;
}

int Scrollable::get_selection() const
{
	return selection;
}

void Scrollable::set_selection(int selection)
{
	this->selection = selection;
}

int Scrollable::get_size() const
{
	return size;
}

void Scrollable::set_size(int size)
{
	this->size = size;
}

vector<string> Scrollable::get_list() const
{
	return list;
}

