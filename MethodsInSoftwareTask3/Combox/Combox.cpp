#include "Combox.h"
#include "../Button/Button.h"


Combox::Combox(int width, vector<string> options) :Panel(options.size(), width),list(options),isListOpen(false), size(options.size()), selection(0)
{
	height = 1;
	for(auto i=0;i<size;i++)
	{
		Button *b = new Button(width-2);
		b->SetText(list[i]);
		b->hide();
		b->addListener([&]() {b->show(); });
		addControl(*b, 0 , 0 + i);

	}
	children[0]->show();
	onClick = [&]()
	{
		if (this->isListOpen)
		{
			this->close();
		}
		else
		{
			this->open();
		}
	};
	button = new Button(1);
	button->addListener(onClick);
	button->setValue("v");
	addControl(*button, width - 1, 0);
}



void Combox::open()
{
	height = size;
	set_layer(1);
	for(auto i=children.begin();i<children.end()-1;++i)
	{
		(*i)->show();
	}
	isListOpen = true;
}

void Combox::close()
{
	height = 1;
	set_layer(0);
	for (auto i = children.begin(); i<children.end() - 1; ++i)
	{
		(*i)->hide();
	}
	isListOpen = false;
}




Combox::~Combox()
{
	delete (button);
}

	
void Combox::keyDown(WORD code, CHAR chr)
{
	if (!isListOpen && (code==VK_UP  || code == VK_DOWN))
	{
		open();
		return;
	}
	switch (code)
	{
	case VK_UP:
	{
		if (selection == 0)
		{
			selection = size - 1;
		}
		else
		{
			--selection;
		}
		break;
	}
	case VK_DOWN:
	{
		if (selection < size - 1)
		{
			selection++;
		}
		else
		{
			selection = 0;
		}
		break;
	}
	case VK_RETURN:
	{
		isListOpen = false;
		close();
		break;
	}
	}
}



void Combox::getAllControls(vector<Control*>* vector)
{
//	vector->push_back(this);
}

bool Combox::canGetFocus()
{
	return true;
}
