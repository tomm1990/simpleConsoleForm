#include "Messagebox.h"
#include "../Control/EventEngine.h"

Messagebox::Messagebox(const int height, const int width) : Panel(height, width) {
	setBorder(BorderType::Single);
	string tit = "Welcome!", des = "Methods in software Engineering";
	description = new Label(des.length(), des);
	addControl(*description, (getWidth() - description->getWidth()) / 2, 4);
	description->setBorder(BorderType::Double);
	description->set_layer(2);
	
	this->title = new Label(tit.length(), tit);
	this->title->setBorder(BorderType::Double);
	addControl(*this->title, (getWidth() - this->title->getWidth()) / 2, 1);
	this->title->set_layer(2);

	bOK = new Button(5);
	bOK->SetText(" OK");
	bOK->setBorder(BorderType::Single);
	
	bBack = new Button(5);
	bBack->SetText(" Back");
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
	if (text.length()!=0) description->setValue(text);
}

void Messagebox::setTitle(string title) {
	if (title.length() == 0) this->title->setValue(title);
}

void Messagebox::show(){
	Control::show();
	setFocus(*bOK);
}

void Messagebox::addControl(Control& c, const int x, const int y){
	Panel::addControl(c, x, y);
}

void Messagebox::draw(Graphics& graphics, const int x , const int y, const size_t p){
	Panel::draw(graphics, x, y, p);
}