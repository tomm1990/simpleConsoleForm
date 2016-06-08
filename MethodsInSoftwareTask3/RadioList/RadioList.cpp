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

void RadioList::draw(const Graphics& graphics, int left, int top)
{
}

void RadioList::keyDown(WORD code, CHAR chr)
{
}

void RadioList::mousePressed(int x, int y, bool isLeft)
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
