#include "CheckList.h"
#include "../Button/Button.h"

CheckList::CheckList(int height,int width, const vector<string>& options): Panel(height,width),list(options)
{
	auto e = [&](Control*c)
	{
		auto btn = dynamic_cast<Button*>(c);
		auto word = btn->getValue().substr(3);
		if (!btn->getValue().compare("[ ]"+word))
		{
			btn->setValue("[x]" + word);
		}
		else
		{
			btn->setValue("[ ]" + word);
		}
		valsMap[word] = !valsMap[word];
			
	};
	for(auto i=0;i<options.size();++i)
	{
		auto b = new Button(width);
		b->setValue("[ ]"+ options[i]);
		valsMap[options[i]] = false;
		b->addListener(e, b);
		addControl(*b, 0, i);

	}
}


void CheckList::deselctIndex(size_t index)
{
	valsMap[list[index]] = false;

}

void CheckList::selectIndex(size_t index)
{
	valsMap[list[index]] = true;
}


