#pragma once
#include "../Button/Button.h"
#include "../Control/Scrollable.h"

class Combox : public Scrollable {
public:
	Combox(const int, const vector<string>&);
	~Combox() { }
	void open();
	void close();
	void update() override;
private:
	Button* button;
	bool isListOpen;
};