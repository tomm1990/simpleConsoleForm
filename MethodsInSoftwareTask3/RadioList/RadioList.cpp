#include "RadioList.h"

RadioList::RadioList(int width): Control(width)
{
}

void RadioList::MouseEventProc(MOUSE_EVENT_RECORD)
{
}

void RadioList::KeyEventProc(KEY_EVENT_RECORD)
{
}


void RadioList::SetForeground(Color color)
{
}

void RadioList::SetBackground(Color color)
{
}

void RadioList::SetBorder(BorderType border)
{
}

void RadioList::draw(const Graphics& graphics, int i, int i1, size_t size_t)
{
}

void RadioList::keyDown(WORD code, CHAR chr)
{
}

void RadioList::mousePressed(int i, int y, bool b)
{
}

void RadioList::getAllControls(vector<Control*>* vector)
{
}

bool RadioList::canGetFocus()
{
	return true;
}

RadioList::~RadioList()
{
}
