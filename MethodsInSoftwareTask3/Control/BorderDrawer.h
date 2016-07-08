#pragma once
#include "Graphics.h"

// Borders class
// implemented with Strategy design pattern
class BorderDrawer{
public:
	virtual ~BorderDrawer() {}
	void setAssets(char[]);
	virtual void draw(const Graphics&, const int, const int, const int, const int) const = 0 ;
private:
	char _assets[6];
	BorderDrawer* border;
};

class SingleBorder : public BorderDrawer{
public:
	SingleBorder();
	~SingleBorder() { }
	void draw(const Graphics&, const int , const int , const int , const int ) const override;
};

class DoubleBorder : public BorderDrawer{
public:
	DoubleBorder();
	~DoubleBorder() { }
	void draw(const Graphics& , const int , const int , const int , const int ) const override;
};

class NoneBorder : public BorderDrawer{
public:
	NoneBorder() { }
	~NoneBorder() { }
	void fillBackground(const Graphics& , const int , const int , const int , const int ) const;
	void draw(const Graphics& , const int , const int , const int , const int ) const override;
};