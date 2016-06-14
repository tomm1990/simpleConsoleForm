#include "BorderDrawer.h"

BorderDrawer::BorderDrawer()
{
}

BorderDrawer::BorderDrawer(BorderDrawer& border)
{
	this->border = &border;
}

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

SingleBorder::SingleBorder(BorderDrawer& border) : BorderDrawer(border)
{
}

SingleBorder::~SingleBorder(){}

DoubleBorder::DoubleBorder()
{
	char assets[] = { '\xc9'  ,'\xcd'  ,'\xbb'  ,'\xba'  ,'\xc8'  ,'\xbc' };
	BorderDrawer::setAssets(assets);
}

DoubleBorder::DoubleBorder(BorderDrawer& border) : BorderDrawer(border)
{
}

DoubleBorder::~DoubleBorder()
{
}

NoneBorder::NoneBorder()
{
	char assets[] = { ' '  ,' '  ,' '  ,' '  ,' '  ,' ' };
	BorderDrawer::setAssets(assets);
}

NoneBorder::NoneBorder(BorderDrawer& border) : BorderDrawer(border)
{
}

NoneBorder::~NoneBorder()
{
}