#include "CheckList.h"

CheckList::CheckList(int width) : Control(width)
{
}

void CheckList::MouseEventProc(MOUSE_EVENT_RECORD)
{
}

void CheckList::KeyEventProc(KEY_EVENT_RECORD)
{
}

void CheckList::Show()
{
}

void CheckList::Hide()
{
}

void CheckList::SetForeground(ForegroundColor color)
{
}

void CheckList::SetBackground(BackgroundColor color)
{
}

void CheckList::SetBorder(BorderType border)
{
}

CheckList::~CheckList()
{
}

void CheckList::draw(const Graphics& graphics, int i, int i1, size_t size_t)
{
}

void CheckList::keyDown(WORD code, CHAR chr)
{
}

void CheckList::mousePressed(int i, int y, bool b)
{
}

void CheckList::getAllControls(vector<Control*>* vector)
{
}

bool CheckList::canGetFocus()
{
	return true;
}
