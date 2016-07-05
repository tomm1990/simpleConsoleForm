#pragma once
#include "../Panel/Panel.h"
#include "../Button/Button.h"

class Scrollable :
	public Panel
{
private:
	int cursor;
	int selection;
	int size;
	vector<string>list;
public:
	Scrollable (int width, vector<string> list);
	virtual void mark()=0;
	virtual void keyDown(WORD code, CHAR chr) override;
	~Scrollable(){};
	void getAllControls(vector<Control*>* vector) override;
	bool canGetFocus() override{return true;};
	int get_cursor() const;
	void set_cursor(int cursor);
	int get_selection() const;
	void set_selection(int selection);
	int get_size() const;
	void setSelectedIndex(int index) { set_cursor(index - 1); };
	void set_size(int size);
	vector<string> get_list() const;
};

