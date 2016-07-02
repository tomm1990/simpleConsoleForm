#pragma once
#include "../Button/Button.h"
#include "../Control/Scrollable.h"


class Combox:
	public Panel
{
private:
	vector<string> list;
	bool isListOpen;
	size_t size;
	int selection;
	Button* button=nullptr;
	Label* label;

public:
	Combox(int width, vector<string> options);
	void open();
	void close();
	void setSelectedIndex(int index) { selection = index - 1; };
	~Combox() override;
	void getAllControls(vector<Control*>* vector) override;
	bool canGetFocus() override;


};

