#pragma once
#include "../Panel/Panel.h"
#include "../Button/Button.h"
#include <map>

class Scrollable : public Panel {
public:
	virtual ~Scrollable();
	Scrollable(const int, const vector<string>);
	void setSelectedIndex(const size_t);
	size_t getSelectedIndex() const { return index; }
	virtual void update() = 0;
	size_t getSize() const { return size; }
protected:
	map<string, bool> valsMap;
	size_t index;
	size_t size;
};