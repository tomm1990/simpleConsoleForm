#include "Panel.h"



Panel::Panel(int height,int width): Control(width) {
}

void Panel::MouseEventProc(MOUSE_EVENT_RECORD)
{
}

void Panel::KeyEventProc(KEY_EVENT_RECORD)
{
}

void Panel::Show()
{
}

void Panel::Hide()
{
}

void Panel::SetForeground(Color color)
{
}

void Panel::SetBackground(Color color)
{
}

void Panel::SetBorder(BorderType border)
{
}

void Panel::draw(const Graphics& graphics, int i, int i1, size_t size_t)
{
}

void Panel::keyDown(WORD code, CHAR chr)
{
}

void Panel::mousePressed(int i, int y, bool b)
{
}

void Panel::getAllControls(vector<Control*>* vector)
{
}

bool Panel::canGetFocus()
{
	return false;
}

Panel::~Panel()
{
}
