#pragma once
class Graphics;

class BorderDrawer
{
public:
	BorderDrawer();
	~BorderDrawer();
	virtual void draw(Graphics& graphics,int left, int top);
};

