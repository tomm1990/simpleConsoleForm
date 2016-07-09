#pragma once
#include "../Control/Control.h"

// Panel abstract class
// implemented in composite design pattern
class Panel : public Control{
public:
	Panel(const int, const int);
	virtual void keyDown(const WORD, const CHAR) override;
	virtual void mousePressed(const int, const int, const bool) override;
	void draw(Graphics& graphics, const int, const int, const size_t) override;
	virtual void getAllControls(vector<Control*>*) override;
	virtual bool canGetFocus() override { return false; }
	virtual void addControl(Control&, const int, const int);
	static void restartFocus();
	virtual void set_layer(const size_t) override;
	virtual ~Panel() { }
	vector<Control*>& getChildrens() { return children; }
	vector<Control*>& getFocusVec() { return focusVec; }

private:
	vector < Control* > children;				// childrens of panel
	static vector < Control* > focusVec;		// focusable controls
};