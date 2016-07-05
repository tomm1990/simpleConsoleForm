#pragma once
#include "../Button/Button.h"
#include "../Panel/Panel.h"


class Combox:
	public Panel
{
private:
	Button* button;
	bool isListOpen;
	vector<string> list;
public:
	Combox(int width, vector<string> options);

	void open();
	void close();
	bool canGetFocus() override { return false; };
	~Combox() override;

};

