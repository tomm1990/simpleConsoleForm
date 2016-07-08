#include "RadioList.h"

RadioList::RadioList(int height,int width, vector<string> options) : Scrollable(width,options){
	this->height = height;
	auto e = [&](Control*c)
	{
		auto btn = dynamic_cast<Button*>(c);
		auto word = btn->getValue().substr(3);
		if (1)
		{
			btn->setValue("(*)" + word);
		}
		else
		{
			btn->setValue("( )" + word);
		}
		valsMap[word] = !valsMap[word];

	};
	for (auto i = 0; i<options.size(); ++i)
	{
		auto b = new Button(width);
		b->setValue("( )" + options[i]);
		b->addListener(e, b);
		addControl(*b, 0, i);

	}

}

void RadioList::update(size_t index)
{
}
