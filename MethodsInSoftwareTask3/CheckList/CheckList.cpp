#include "CheckList.h"
#include "../Button/Button.h"

CheckList::CheckList(int width, const vector<string>& list): Panel(list.size(), width)
{
	auto e = [](Control*c)
	{
		auto btn = static_cast<Button*>(c);
		auto word = btn->getValue().substr(3);
		if (!btn->getValue().compare("[ ]"+word))
			btn->setValue("[x]" + word);
		else
			btn->setValue("[ ]" + word);
	};
	for(auto i=0;i<list.size();++i)
	{
		auto b = new Button(width);
		b->setValue("[ ]"+ list[i]);
		b->addListener(e, b);
		addControl(*b, 0, i);

	}
}



