#include "Combox.h"

Combox::Combox(int width, vector<string> options): Control(width), list(options), isListOpen(false), currentWord(options[0]), cursorCurrent(1), size(static_cast<SHORT>(options.size()))
{
}

void Combox::SetForeground(Color color)
{
}

void Combox::SetBackground(Color color)
{
}

void Combox::SetBorder(BorderType border)
{
}
/*
void Show()
{
	SetConsoleCursorPosition(hOut, position);
	cout << currentWord;
	SetConsoleCursorPosition(hOut, position);
}

void Hide()
{
	SetConsoleCursorPosition(hOut, position);
	for (auto i = 0; i < size + 1; i++ , SetConsoleCursorPosition(hOut, {position.X,position.Y + static_cast<SHORT>(i)}))
	{
		for (auto j = 0; j < width; j++)
		{
			cout << " ";
		}
	}
}
*/
void Combox::open()
{
	for (size_t i = 0; i < size; i++)
	{
		SetConsoleCursorPosition(hOut, {position.X, position.Y + static_cast<SHORT>(i) + 1});
		cout << list[i];
	}
	SetConsoleCursorPosition(hOut, {position.X,position.Y + 1});
	cursorCurrent = 1;
	isListOpen = true;
}

void Combox::KeyEventProc(KEY_EVENT_RECORD mer)
{
	SHORT x, y;
	getCursorXY(x, y);
	if (mer.bKeyDown)
	{
		if (!isListOpen)
		{
			open();
			return;
		}
		switch (mer.wVirtualKeyCode)
		{
		case VK_UP:
			{
				if (cursorCurrent == 1)
				{
					SetConsoleCursorPosition(hOut, {position.X,position.Y + static_cast<SHORT>(size)});
					cursorCurrent = size;
				}
				else
				{
					SetConsoleCursorPosition(hOut, {position.X,static_cast<SHORT>(y) - 1});
					cursorCurrent--;
				}
				break;
			}
		case VK_DOWN:
			{
				if (cursorCurrent < size)
				{
					SetConsoleCursorPosition(hOut, {position.X,static_cast<SHORT>(y) + 1});
					cursorCurrent++;
				}
				else
				{
					cursorCurrent = 1;
					SetConsoleCursorPosition(hOut, {position.X,position.Y + 1});
				}
				break;
			}
		case VK_RETURN:
			{
				currentWord = list[cursorCurrent - 1];
				SetConsoleCursorPosition(hOut, position);
				cout << currentWord;
				Hide();
				Show();
				isListOpen = false;
				break;
			}
		}
	}
}

void Combox::MouseEventProc(MOUSE_EVENT_RECORD mer)
{
	if (mer.dwButtonState != FROM_LEFT_1ST_BUTTON_PRESSED)
	{
		return;
	}
	if (mer.dwMousePosition.X <= (position.X + width) &&
		mer.dwMousePosition.X >= position.X)
	{
		if (!isListOpen)
		{
			open();
			return;
		}
		if (mer.dwMousePosition.Y >= position.Y + 1 &&
			mer.dwMousePosition.Y <= position.Y + size)
		{
			SetConsoleCursorPosition(hOut, mer.dwMousePosition);
			cursorCurrent = mer.dwMousePosition.Y - position.Y - 1;
			currentWord = list[cursorCurrent];
		}
		cout << currentWord;
		Hide();
		Show();
		isListOpen = false;
	}
}

void Combox::draw(const Graphics& graphics, int left, int top)
{
}

void Combox::keyDown(WORD code, CHAR chr)
{
}

void Combox::mousePressed(int x, int y, bool isLeft)
{
}

void Combox::getAllControls(vector<Control*>* vector)
{
}

bool Combox::canGetFocus()
{
	return true;
}
