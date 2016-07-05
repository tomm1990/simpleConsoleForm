#include "Messagebox.h"

Messagebox::Messagebox(int height, int width) : Panel(height, width) {
	set_layer(2);
	bOK = new Button(6);
	bOK->SetText(" OK");
	bOK->setBorderDrawer(BorderType::Single);
	bBack = new Button(6);
	bBack->SetText("Back");
	bBack->setBorderDrawer(BorderType::Single);
	addControl(*bOK,  getWidth() / 4,getHeight()-2 );
	addControl(*bBack, getWidth() / 2 ,getHeight() - 2);

	auto OkEvent = [](Control *c)
	{
		c->hide();
		// need to implement OK click button
	};
	bOK->addListener(OkEvent, this);

	auto BackEvent = [](Control *c)
	{
		c->hide();
		// need to implement Back click button
	};
	bBack->addListener(BackEvent, this);
	hide();
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
	description = new Label(text.length() , text);
	description->setBorderDrawer(BorderType::Double);
	addControl(*description, (getWidth()- description->getWidth()) / 2, 4 );
}

void Messagebox::setTitle(string title) {
	if (title.length() == 0) title = "Title";
	this->title = new Label(title.length(), title);
	this->title->setBorderDrawer(BorderType::Double);
	addControl(*this->title, (getWidth() - this->title->getWidth())/2, 1);
}



bool Messagebox::canGetFocus()
{
	return false;
}

void Messagebox::show()
{
	Control::show();
	setFocus(*bOK);
}
