#include "Combox.h"
#include "../Button/Button.h"


Combox::Combox(int width, vector<string> options) :Scrollable(width, options), isListOpen(false)
{
	height = 1;
	auto e = [&](Control* c)
	{
		if (!c->isVisible())
		{
			c->show();
		}

		else
		{
			auto b2 = static_cast<Button*>(c);
			auto b1 = static_cast<Button*>(children[0]);
			string temp = b1->getValue();
			b1->setValue(b2->getValue());
			b2->setValue(temp);
			set_cursor(b1->getTop());
			close();
			setFocus(*this);
		}
	};
	for(auto i=0;i<get_size();i++)
	{
		auto *b = new Button(width-2);
		b->SetText(get_list()[i]);
		b->hide();
		b->addListener(e,b);
		addControl(*b, 0 , i);

	}
	auto onClick = [&](Control* c)
	{
		if (isListOpen)
		{
			close();
		}
		else
		{
			open();
		}
	};
	button = new Button(1);
	button->addListener(onClick,this);
	button->setValue("v");
	children[0]->show();
	addControl(*button, width - 1, 0);
}

void Combox::mark()
{
	auto b1 = static_cast<Button*>(children[0]);
	auto b2 = static_cast<Button*>(getFocus());
	swap(b1->getValue(), b2->getValue());
}

void Combox::draw(Graphics& graphics, int left, int top, size_t p)
{
	for(auto it=children.begin();it!=children.end()-1;++it)
	{
		if((*it)==getFocus())
		{
			open();
		}
	}
	Scrollable::draw(graphics, left, top, p);
}


void Combox::open()
{
	height = get_size();
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
	isListOpen = false;
}



Combox::~Combox()
{
	delete (button);
}

	





