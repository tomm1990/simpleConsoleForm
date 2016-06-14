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


void RadioList::setForeground(Color color)
{
}

void RadioList::setBackground(Color color)
{
}

void RadioList::setBorderDrawer(const BorderDrawer & borderDrawer)
{
}

void RadioList::draw(Graphics& graphics, int left, int top, size_t p)
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
