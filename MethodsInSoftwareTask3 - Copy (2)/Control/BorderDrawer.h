#pragma once
#include "Graphics.h"

class BorderDrawer{
	char _assets[6];
	BorderDrawer* border;
public:
	virtual ~BorderDrawer() {};
	void setAssets(char assets[]);
	virtual void draw(Graphics& graphics, int left, int top, int width, int height) const = 0 ;
};

class SingleBorder : public BorderDrawer{
public:
	SingleBorder();
	~SingleBorder() ;
	virtual void draw(Graphics& graphics, int left, int top, int width, int height) const override;
};

class DoubleBorder : public BorderDrawer{
public:
	DoubleBorder();
	~DoubleBorder() ;
	void draw(Graphics& graphics, int left, int top, int width, int height) const override;
};

class NoneBorder : public BorderDrawer{
public:
	NoneBorder();
	~NoneBorder() ;
	void draw(Graphics& graphics, int left, int top, int width, int height) const override;
};