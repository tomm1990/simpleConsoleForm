#pragma once
#include "../Panel/Panel.h"
#include "../Button/Button.h"


class Combox:
	public Panel
{
private:
	vector<string> list;
	bool isListOpen;
	size_t size;
	int selection;
	Button* button=nullptr;
	std::function<void()> onClick;
public:
	Combox(int width, vector<string> options);
	void open();
	void close();
	void setSelectedIndex(int index) { selection = index - 1; };

	~Combox() override;
	void keyDown(WORD code, CHAR chr) override;
	void getAllControls(vector<Control*>* vector) override;
	bool canGetFocus() override;


};

