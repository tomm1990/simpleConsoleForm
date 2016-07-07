#include "CheckList.h"
#include "../Button/Button.h"

CheckList::CheckList(int height,int width, const vector<string>& options): Panel(height, width),options(options)
{
	auto e = [&](Control*c)
	{
		auto btn = static_cast<Button*>(c);
		auto word = btn->getValue().substr(3);
		if (!btn->getValue().compare("[ ]"+word))
		{
			btn->setValue("[x]" + word);
		}
		else
		{
			btn->setValue("[ ]" + word);
		}
		list[word].isCheck = !list[word].isCheck;
			
	};
	for(auto i=0;i<options.size();++i)
	{
		auto b = new Button(width);
		list[options[i]].isCheck = false;
		b->setValue("[ ]"+ options[i]);
		b->addListener(e, b);
		addControl(*b, 0, i);

	}
}

void CheckList::deselctIndex(size_t index)
{
	list[options[index]].isCheck = false;

}

void CheckList::selectIndex(size_t index)
{
	list[options[index]].isCheck = true;
}


