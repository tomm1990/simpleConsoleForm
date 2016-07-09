#pragma once
#include "../Control/Scrollable.h"

class RadioList : public Scrollable {
public:
	RadioList(const int, const int, const vector<string>);
	virtual ~RadioList() { }
	void update() override;
private:
	map <Button*, bool> valsMap;		// map for button select
};