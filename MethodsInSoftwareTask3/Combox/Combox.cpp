#include "Combox.h"
#include "../Button/Button.h"


Combox::Combox(int width, const vector<string>& options): Scrollable(width,options),isListOpen(false)
{
	height = 1;
	auto e = [&](Control* c)
	{
		if (!c->isVisible())
		{
			open();
		}

		else
		{
			auto b2 = dynamic_cast<Button*>(c);
			auto b1 = dynamic_cast<Button*>(children[0]);
			string temp = b1->getValue();
			b1->setValue(b2->getValue());
			b2->setValue(temp);
			close();
		}
		setFocus(*children[0]);
	};
	for(auto i=0;i<list.size();i++)
	{
		auto *b = new Button(width-2);
		b->SetText(list[i]);
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



void Combox::open()
{
	height = list.size();
	//set_layer(1);
	for(auto i=children.begin()+1;i<children.end();++i)
	{
		(*i)->show();
	}
	isListOpen = true;
}

void Combox::close()
{
	height = 1;
	//set_layer(0);
	for (auto i = children.begin()+1; i<children.end()-1; ++i)
	{
		(*i)->hide();
	}
	isListOpen = false;
}

void Combox::update()
{
	auto b1 = dynamic_cast<TextBox*>(children[0]);
	auto b2 = dynamic_cast<TextBox*>(children[index]);
	auto temp = b1->getValue();
	b1->setValue(b2->getValue());
	b2->setValue(temp);
}






