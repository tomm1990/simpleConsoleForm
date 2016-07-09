#include "RadioList.h"

RadioList::RadioList(const int height, const int width, const vector<string> options) : Scrollable(width, options) {
	this->set_height(height);
	auto e = [&](Control*c){
		auto b = dynamic_cast<Button*> (c);
		for(auto it : valsMap){
			it.second = false;
			auto word = it.first->getValue().substr(3);
			it.first->setValue("( )" + word);
		}
		valsMap[b] = true;
		auto word2 = b->getValue().substr(3);
		b->setValue("(*)" + word2);
	};
	for (int i = 0; i < options.size() ; ++i){
		auto b = new Button(width);
		b->setValue("( )" + options[i]);
		valsMap[b] = false;
		b->addListener(e, b);
		addControl(*b, 0, i);
	}
}

void RadioList::update(){
	auto b = dynamic_cast<Button*>(getChildrens()[getIndex()]);
	b->mousePressed(NULL, NULL, NULL);
}