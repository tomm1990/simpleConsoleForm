#pragma once
#include "../Button/Button.h"
#include "../Control/Scrollable.h"


class Combox:
	public Scrollable
{
private:
	Button* button;
	bool isListOpen;

public:
	Combox(int width, const vector<string>& options);
	void open();
	void close();
	void update(size_t index) override;
};

