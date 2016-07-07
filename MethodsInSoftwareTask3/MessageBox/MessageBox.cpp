#include "Messagebox.h"

Messagebox::Messagebox(int height, int width) : Panel(height, width) {
	setBorder(BorderType::Single);
	set_layer(2);
	setBackground(Color::Black);
	setForeground(Color::White);
	bOK = new Button(5);
	bOK->SetText("OK");
	bOK->set_layer(2);
	bOK->setBorder(BorderType::Single);
	bBack = new Button(5);
	bBack->set_layer(2);
	bBack->SetText("Back");
	bBack->setBorder(BorderType::Single);
	addControl(*bOK, width/4-1,height-2 );
	addControl(*bBack, width/2+1,height - 2);

	auto OkEvent = [](Control *c)
	{
		c->setBackground(Color::Blue);
		// need to implement OK click button
	};
	bOK->addListener(OkEvent, this);

	auto BackEvent = [](Control *c)
	{
		c->setBackground(Color::Green);
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
	description->set_layer(2);
	addControl(*description, (getWidth()- description->getWidth()) / 2, 4 );
}

void Messagebox::setTitle(string title) {
	if (title.length() == 0) title = "Title";
	this->title = new Label(title.length(), title);
	this->title->set_layer(2);
	this->title->setBorder(BorderType::Double);
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
	getFocus()->set_layer(2);
}
