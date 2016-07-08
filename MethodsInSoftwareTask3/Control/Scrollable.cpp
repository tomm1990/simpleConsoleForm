#include "Scrollable.h"

void Scrollable::setSelectedIndex(const size_t i){
	this->index = i;
	update();
}

Scrollable::Scrollable(const int width, const vector<string> list) : Panel(list.size(), width), index(0), size(list.size()) {
	for(int i = 0 ; i < size ; i++ ) valsMap[list[i]] = false;
}