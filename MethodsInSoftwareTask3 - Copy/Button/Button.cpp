#include "Button.h"

Control* MouseListener::get_root() const
{
	return root;
}

void MouseListener::set_root(Control* root)
{
	this->root = root;
}

Button::Button(int width):Label(width,"[X]")
{
}


