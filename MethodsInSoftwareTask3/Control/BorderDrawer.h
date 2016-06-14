#pragma once
#include "Graphics.h"

//	char top_left = '\xDA';
//	char horizontal_line = '\xC4';
//	char top_right = '\xBF';
//	char vertical_line = '\xB3';
//	char buttom_left = '\xC0';
//	char buttom_right = '\xD9';

class BorderDrawer{
	char _assets[6];
	BorderDrawer* border;
public:
	explicit BorderDrawer();
	BorderDrawer(BorderDrawer& border);
	virtual ~BorderDrawer() {};
	void setAssets(char assets[]);
	virtual void draw(Graphics& graphics, int left, int top, int width, int height) const = 0 ;
};

class SingleBorder : public BorderDrawer{
public:
	SingleBorder();
	SingleBorder(BorderDrawer& border);
	~SingleBorder() ;
	virtual void draw(Graphics& graphics, int left, int top, int width, int height) const override{
		if ((left > 0) && (top > 0)){
			BorderDrawer::draw(graphics, left - 1, top - 1, width, height);
		}else {
			BorderDrawer::draw(graphics, left, top, width, height);
		}
	}
};

class DoubleBorder : public BorderDrawer{
public:
	DoubleBorder();
	DoubleBorder(BorderDrawer& border);
	~DoubleBorder() ;
	void draw(Graphics& graphics, int left, int top, int width, int height) const override{
		BorderDrawer::draw(graphics, left - 1, top - 1, width, height);
	}
};

class NoneBorder : public BorderDrawer{
public:
	NoneBorder();
	NoneBorder(BorderDrawer& border);
	~NoneBorder() ;
	 void draw(Graphics& graphics, int left, int top, int width, int height) const override{ }
};