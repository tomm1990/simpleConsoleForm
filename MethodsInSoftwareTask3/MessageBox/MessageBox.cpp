#include "Messagebox.h"

Messagebox::Messagebox(int height, int width) : Panel(height, width) {
	hide();
	set_layer(1);
}


Messagebox::~Messagebox()
{
}


void Messagebox::setText(const string text) {
	this->text = text;
}

void Messagebox::setTitle(const string title) {
	this->title = title;
}

void Messagebox::keyDown(WORD code, CHAR chr)
{
}

void Messagebox::mousePressed(int x, int y, bool isLeft)
{
}

void Messagebox::draw(Graphics& graphics, int left, int top, size_t p) {
	Panel::draw(graphics, left, top, p);
}

void Messagebox::getAllControls(vector<Control*>* vector)
{
}

bool Messagebox::canGetFocus()
{
	return false;
}
