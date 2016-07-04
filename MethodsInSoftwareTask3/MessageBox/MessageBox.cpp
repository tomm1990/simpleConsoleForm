#include "Messagebox.h"

Messagebox::Messagebox(int height, int width) : Panel(height, width) {
	set_layer(1);
	
	this->bOK = new Button(6);
	bOK->SetText(" OK");
	bOK->setBorderDrawer(BorderType::Single);
	this->bBack = new Button(6);
	bBack->SetText("Back");
	bBack->setBorderDrawer(BorderType::Single);
	addControl(*this->bOK,  this->getWidth() / 4  ,this->getHeight()-2 );
	addControl(*this->bBack, this->getWidth() / 2 , this->getHeight() - 2);

	auto OkEvent = [&](Control *c)
	{
		// need to implement OK click button
	};
	bOK->addListener(OkEvent, bOK);

	auto BackEvent = [&](Control *c)
	{
		// need to implement Back click button
	};
	bBack->addListener(BackEvent, bBack);
}


Messagebox::~Messagebox()
{
	if (title) delete title;
	if (description)delete description;
	if (bOK) delete bOK;
	if (bBack) delete bBack;
}


void Messagebox::setText(string text ) {
	if (text.length() == 0) text = "Title";
	this->description = new Label(text.length() , text);
	this->description->setBorderDrawer(BorderType::Double);
	addControl(*this->description, (this->getWidth()- description->getWidth()) / 2, 4 );
}

void Messagebox::setTitle(string title) {
	if (title.length() == 0) title = "Title";
	this->title = new Label(title.length(), title);
	this->title->setBorderDrawer(BorderType::Double);
	addControl(*this->title, (this->getWidth() - this->title->getWidth())/2, 1);
}

void Messagebox::keyDown(WORD code, CHAR chr)
{
}


void Messagebox::getAllControls(vector<Control*>* vector)
{
}

bool Messagebox::canGetFocus()
{
	return false;
}
