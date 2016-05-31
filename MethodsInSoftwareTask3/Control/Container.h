#pragma once
#include "Control.h"

class Container : public Control
{
protected:
	vector<Control*> elements;

public:


	explicit Container(int width);
	virtual ~Container() =0;

	virtual Control* getElement(int pos)
	{
		try
		{
			return elements[pos];
		}
		catch (exception e)
		{
			cout << "error get element" << endl;
		}
		return nullptr;
	}

	virtual void add(Control*);
	virtual void traverse();

	void MouseEventProc(MOUSE_EVENT_RECORD mer) override
	{
	}

	void KeyEventProc(KEY_EVENT_RECORD mer) override
	{
	}
};
