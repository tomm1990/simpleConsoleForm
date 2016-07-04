#include "CheckList.h"

CheckList::CheckList(int width, const vector<string>& list): Scrollable(width, list)
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
	for(auto i=0;i<get_size();++i)
	{
		auto b = new Button(width);
		b->setValue("[ ]"+ list[i]);
		b->addListener(e, b);
		addControl(*b, 0, i);

	}
}



