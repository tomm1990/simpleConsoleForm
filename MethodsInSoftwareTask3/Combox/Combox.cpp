#include "Combox.h"
#include "../Button/Button.h"


Combox::Combox(int width, vector<string> options) :Panel(options.size(), width),list(options),isListOpen(false), size(options.size()), selection(0)
{
	height = 1;
	label = new Label(width-2, list[0]);
	addControl(*label, 0,0);
	auto e = [&](Control* c)
	{
		if (!c->isVisible())
		{
			c->show();
		}

		else
		{
			auto l = static_cast<Button*>(c);
			//label->setValue(l->getValue());
			selection = l->getTop();
			close();
		}

	};
	for(auto i=0;i<size;i++)
	{
		auto *b = new Button(width-2);
		b->SetText(list[i]);
		b->hide();
		b->addListener(e,b);
		addControl(*b, 0 , 1 + i);

	}
	auto onClick = [&](Control* c)
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
	button->addListener(onClick,this);
	button->setValue("v");
	addControl(*button, width - 1, 0);
	
}



void Combox::open()
{
	height = size+1;
	set_layer(1);
	for(auto i=children.begin();i<children.end();++i)
	{
		(*i)->show();
	}
	isListOpen = true;
}

void Combox::close()
{
	height = 1;
	set_layer(0);
	for (auto i = children.begin()+1; i<children.end()-1; ++i)
	{
		(*i)->hide();
	}
	selection = 0;
	isListOpen = false;
}




Combox::~Combox()
{
	delete (button);
}

	



void Combox::getAllControls(vector<Control*>* vector)
{

}

bool Combox::canGetFocus()
{
	return true;
}
