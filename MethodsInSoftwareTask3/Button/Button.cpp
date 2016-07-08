#include "Button.h"
#include "../Control/EventEngine.h"

Button::Button(const int width):Label(width,"[X]"){}

void Button::keyDown(const WORD code, const CHAR chr){
	if (code == VK_SPACE || code == VK_RETURN) action(c);
}