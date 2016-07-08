#include "Messagebox.h"
#include "../Control/EventEngine.h"

Messagebox::Messagebox(const int height, const int width) : Panel(height, width) {
	setBorder(BorderType::Single);
	bOK = new Button(5);
	bOK->SetText("OK");
	bOK->setBorder(BorderType::Single);
	bBack = new Button(5);
	bBack->SetText("Back");
	bBack->setBorder(BorderType::Single);
	addControl(*bOK, width/4-1,height-2 );
	addControl(*bBack, width/2+1,height - 2);
	// "OK" button event listener
	auto OkEvent = [](Control *c){
		c->hide();
		restartFocus();
	};
	bOK->addListener(OkEvent, this);
	// "Back" button event listener
	auto BackEvent = [](Control *c){
		c->hide();
		restartFocus();
	};
	bBack->addListener(BackEvent, this);
	hide();
	set_layer(2);
}

Messagebox::~Messagebox(){
	for (int i = 0; i < getChildrens().size(); i++)
		if (getChildrens()[i]) delete getChildrens()[i];
}

void Messagebox::setText(string text) {
	if (text.length() == 0) text = "Title";
	description = new Label(text.length() , text);
	addControl(*description, (getWidth()- description->getWidth()) / 2, 4 );
	description->set_layer(2);
}

void Messagebox::setTitle(string title) {
	if (title.length() == 0) title = "Title";
	this->title = new Label(title.length(), title);
	this->title->setBorder(BorderType::Double);
	addControl(*this->title, (getWidth() - this->title->getWidth())/2, 1);
	this->title->set_layer(2);
}

void Messagebox::show(){
	Control::show();
	setFocus(*bOK);
}