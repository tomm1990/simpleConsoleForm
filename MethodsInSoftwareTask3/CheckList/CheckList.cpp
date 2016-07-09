#include "CheckList.h"
#include "../Button/Button.h"

CheckList::CheckList(const int height, const int width, const vector<string>& options) : Panel(height, width), list(options){
	auto e = [&](Control*c){
		auto btn = dynamic_cast<Button*>(c);
		auto word = btn->getValue().substr(3);
		if (!btn->getValue().compare("[ ]"+word)) btn->setValue("[x]" + word);
		else btn->setValue("[ ]" + word);
		valsMap[word] = !valsMap[word];
	};
	for(int i = 0 ; i < options.size() ; ++i ){
		auto b = new Button(width);
		b->setValue("[ ]"+ options[i]);
		valsMap[options[i]] = false;
		b->addListener(e, b);
		addControl(*b, 0, i);
	}	
}

CheckList::~CheckList(){
	for ( int i = 0 ; i < getChildrens().size() ; i++)
		if (getChildrens()[i]) delete getChildrens()[i]; 
}

void CheckList::selectIndex(const size_t i)
{
	if(!valsMap[list[i]])
	{
		valsMap[list[i]] = true;
		getChildrens()[i]->mousePressed(NULL, NULL, NULL);
	}
	
}

vector<size_t> CheckList::getSelectedIndices()
{
	vector<size_t> v;
	for(auto it:valsMap)
	{
		if (it.second == true)
			v.push_back(valsMap.at(it.first));
	}
	return v;
}
