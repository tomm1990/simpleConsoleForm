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
	Combox(int width, vector<string> options);
	void mark() override;
	void draw(Graphics& graphics, int left, int top, size_t p) override;
	void open();
	void close();
	~Combox() override;
};

