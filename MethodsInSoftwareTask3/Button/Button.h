#pragma once
#include "../Label/Label.h"

class Button:
	public Label
{
public:
	Button(int width, string val);
	virtual ~Button();
};

