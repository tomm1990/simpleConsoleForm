#include "BorderDrawer.h"


void BorderDrawer::draw(Graphics& graphics, int left, int top, int width, int height) const
{
	int i , j;
	graphics.moveTo(left, top);
	graphics.write(string(1, _assets[0]));
	for ( i = 0; i < width; i++) graphics.write(string(1, _assets[1]));
	graphics.write(string(1, _assets[2]));
	
	for( j = 0 ; j < height ; j++){
		graphics.moveTo(left, top + j + 1);
		graphics.write(string(1, _assets[3]));
		for (i = 0; i < width; i++) graphics.write(" ");
		graphics.write(string(1, _assets[3]));
	}
	
	graphics.moveTo(left, top + j +1);
	graphics.write(string(1, _assets[4]));
	for (i = 0; i < width ; i++) graphics.write(string(1, _assets[1]));
	graphics.write(string(1, _assets[5]));
}

SingleBorder::SingleBorder()
{
	char assets[] = { '\xda'  , '\xc4' ,'\xbf' ,'\xb3' ,'\xc0' ,'\xd9' };
	BorderDrawer::setAssets(assets);
}

void BorderDrawer::setAssets(char assets[])
{
	for (int i = 0; i < 6; i++) _assets[i] = assets[i];
}



SingleBorder::~SingleBorder(){}

void SingleBorder::draw(Graphics& graphics, int left, int top, int width, int height) const
{
	if ((left > 0) && (top > 0))
	{
		BorderDrawer::draw(graphics, left - 1, top - 1, width, height);
	}
	else
	{
		BorderDrawer::draw(graphics, left, top, width, height);
	}
}

DoubleBorder::DoubleBorder()
{
	char assets[] = { '\xc9'  ,'\xcd'  ,'\xbb'  ,'\xba'  ,'\xc8'  ,'\xbc' };
	BorderDrawer::setAssets(assets);
}



DoubleBorder::~DoubleBorder()
{
}

void DoubleBorder::draw(Graphics& graphics, int left, int top, int width, int height) const
{
	BorderDrawer::draw(graphics, left - 1, top - 1, width, height);
}

NoneBorder::NoneBorder()
{
	char assets[] = { ' '  ,' '  ,' '  ,' '  ,' '  ,' ' };
	BorderDrawer::setAssets(assets);
}


NoneBorder::~NoneBorder()
{
}