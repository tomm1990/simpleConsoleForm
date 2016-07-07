#pragma once
#include "../Panel/Panel.h"
#include "../Button/Button.h"

class Scrollable :
	public Panel
{
protected:
	
	vector<string> list;

private:
	size_t index;
	size_t size;
public:
	Scrollable (int width, vector<string> list);
	void setSelectedIndex(size_t index);
	size_t getSelectedIndex() const;

};

