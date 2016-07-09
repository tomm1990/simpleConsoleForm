#include "Combox.h"
#include "../Button/Button.h"

Combox::Combox(const int width, const vector<string>& options) : Scrollable(width, options), isListOpen(false){
	this->set_height(1);
	auto e = [&](Control* c){
		if (!c->isVisible()) open();
		else{
			auto b2 = dynamic_cast<Button*>(c);
			auto b1 = dynamic_cast<Button*>(getChildrens()[0]);
			string temp = b1->getValue();
			b1->setValue(b2->getValue());
			b2->setValue(temp);
			close();
		}
		setFocus(*getChildrens()[0]);
	};
	for(int i = 0 ; i < getSize() ; i++){
		auto *b = new Button(width-3);
		b->SetText(options[i]);
		b->hide();
		b->addListener(e,b);
		addControl(*b, 0 , i);
	}
	auto onClick = [&](Control* c){
		if (isListOpen)	close();
		else open();
	};
	button = new Button(3);
	button->addListener(onClick,this);
	button->setValue(" v ");
	getChildrens()[0]->show();
	addControl(*button, width - 3, 0);
}

void Combox::open(){
	this->set_height(getSize());
	for(auto i=getChildrens().begin() + 1 ; i < getChildrens().end() - 1 ; ++i){
		(*i)->show();
		(*i)->set_width(getWidth());
	}
	isListOpen = true;
	set_layer(1);
}

void Combox::close(){
	this->set_height(1);
	for (auto i = getChildrens().begin() + 1 ; i < getChildrens().end() - 1 ; ++i){
		(*i)->hide();
		(*i)->set_width(getWidth()-3);
	}
	isListOpen = false;
	set_layer(0);
}

void Combox::update(){
	auto b1 = dynamic_cast<TextBox*>(getChildrens()[0]);
	auto b2 = dynamic_cast<TextBox*>(getChildrens()[getIndex()]);
	auto temp = b1->getValue();
	b1->setValue(b2->getValue());
	b2->setValue(temp);
}