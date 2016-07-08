#pragma once
#include "../Panel/Panel.h"
#include "../Button/Button.h"
#include <map>

class Scrollable :
	public Panel
{
protected:
	map<string, bool> valsMap;
	size_t index;
	size_t size;

private:

public:
	Scrollable (int width, vector<string> list);
	void setSelectedIndex(size_t index);
	size_t getSelectedIndex() const;
	virtual void update(size_t i) = 0;

};

