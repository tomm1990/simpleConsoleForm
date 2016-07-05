#include "Button.h"

Button::Button(int width):Label(width,"[X]")
{
}

void Button::keyDown(WORD code, CHAR chr)
{
	if(code==VK_SPACE || code==VK_RETURN)
		action(c);

}

