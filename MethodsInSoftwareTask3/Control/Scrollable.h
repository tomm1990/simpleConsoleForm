#pragma once
#include "../Panel/Panel.h"
#include "../Button/Button.h"

class Scrollable :
	public Panel
{
protected:
	
	vector<string> list;
	size_t index;
	size_t size;

private:

public:
	Scrollable (int width, vector<string> list);
	void setSelectedIndex(size_t index);
	size_t getSelectedIndex() const;
	virtual void update() = 0;

};

