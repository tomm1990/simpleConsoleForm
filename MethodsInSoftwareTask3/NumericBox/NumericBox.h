#pragma once
#include "../Panel/Panel.h"
#include "../Label/Label.h"
#include "../Button/Button.h"

class ValueListener :public MouseListener
{
public:
	ValueListener(Label& root) : MouseListener(root) {}
	void mousePressed(Button& b, int x, int y, bool isLeft) override
	{
		auto a = dynamic_cast<Label*>(get_root());
		if (a) a->SetText("12");
	};
};
class NumericBox : public Panel
{
public:
	NumericBox(int width, int min, int max);
	~NumericBox();

	void draw(Graphics& graphics, int left, int top, size_t p);
	void keyDown(WORD code, CHAR chr) override;
	//void mousePressed(int x, int y, bool isLeft) override;


	string getValue() const;
	void setValue(const string& value);
	bool canGetFocus() override;
	Label* getLabel() const { return val; }

	
	void SetText(Label& l, string newText)
	{
		val->setValue(newText);
	}

private:
	int min, max , number = 20;
	Label *val;
	Button *bUP, *bDOWN;
	ValueListener* valueListener;
};

//inline void SetText(Label& l, string newText)
//{
//	l.setValue(newText);
//}




