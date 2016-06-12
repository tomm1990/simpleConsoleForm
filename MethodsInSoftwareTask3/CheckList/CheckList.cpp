#include "CheckList.h"
int flag = 0;
int Cflag = 0;

CheckList::CheckList(int height, int width, vector<string> options): Control(width) {
	Graphics C;
	C.setForeground(Color::Blue);
	int arrayFlugs[4] = {};
	DWORD fontColor = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
	for (int counter = 0; counter < options.size(); ++counter) {
		COORD position = { 3, counter+1 };
		arrayFlugs[counter] = 0;
		C.moveTo(3, counter + 2);	
		cout << options[counter]<<endl;	
	}
	POINT p;
	if (GetCursorPos(&p))
	{
		if (p.y > 0 && p.y < 580) {
			if (arrayFlugs[0] == 0) {
				C.setForeground(Color::Red);
				options[0] = "[X] Tommy";
				cout << options[0] << endl;
				//CheckList test1(3, 1, 0, FOREGROUND_RED | FOREGROUND_INTENSITY, "[ ] Hello", 1);;
			}
			if (arrayFlugs[0] == 1) {
				//CheckList test1(3, 1, 0, FOREGROUND_RED | FOREGROUND_INTENSITY, "[X] Hello", 1);;
			}
			//if ((mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) && (arrayFlugs[0] == 0))
			//{
				//arrayFlugs[0] = 1;
				//CheckList test1(3, 1, 0, FOREGROUND_RED | FOREGROUND_INTENSITY, "[X] Hello", 1);;
			//}
			//else if ((mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) && (arrayFlugs[0] == 1))
			//{
				//arrayFlugs[0] = 0;
				//CheckList test1(3, 1, 0, FOREGROUND_RED | FOREGROUND_INTENSITY, "[ ] Hello", 1);;
			//}
		}
		else {
			if (arrayFlugs[0] == 0) {
				//CheckList test1(3, 1, 0, FOREGROUND_BLUE | FOREGROUND_INTENSITY, "[ ] Hello", 1);;
			}
			if (arrayFlugs[0] == 1) {
				//CheckList test1(3, 1, 0, FOREGROUND_BLUE | FOREGROUND_INTENSITY, "[X] Hello", 1);;
			}
		}

		if (p.y > 80 && p.y < 100) {
			if (arrayFlugs[1] == 0) {
				//CheckList test1(3, 2, 0, FOREGROUND_RED | FOREGROUND_INTENSITY, "[ ] Beautiful", 1);;
			}
			if (arrayFlugs[1] == 1) {
				//CheckList test1(3, 2, 0, FOREGROUND_RED | FOREGROUND_INTENSITY, "[X] Beautiful", 1);;
			}
			//if ((mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) && (arrayFlugs[1] == 0))
			//{
				//arrayFlugs[1] = 1;
				//CheckList test1(3, 2, 0, FOREGROUND_RED | FOREGROUND_INTENSITY, "[X] Beautiful", 1);;
			//}
			//else if ((mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) && (arrayFlugs[1] == 1))
			//{
				//arrayFlugs[1] = 0;
				//CheckList test1(3, 2, 0, FOREGROUND_RED | FOREGROUND_INTENSITY, "[ ] Beautiful", 1);;
			//}
		}
		else {
			if (arrayFlugs[1] == 0) {
				//CheckList test1(3, 2, 0, FOREGROUND_BLUE | FOREGROUND_INTENSITY, "[ ] Beautiful", 1);;
			}
			if (arrayFlugs[1] == 1) {
				//CheckList test1(3, 2, 0, FOREGROUND_BLUE | FOREGROUND_INTENSITY, "[X] Beautiful", 1);;
			}
		}

		if (p.y > 100 && p.y < 150) {
			//if (arrayFlugs[2] == 0) {
			//	CheckList test1(3, 3, 0, FOREGROUND_RED | FOREGROUND_INTENSITY, "[ ] World", 1);;
			//}
			//if (arrayFlugs[2] == 1) {
			//	CheckList test1(3, 3, 0, FOREGROUND_RED | FOREGROUND_INTENSITY, "[X] World", 1);;
			//}
			//if ((mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) && (arrayFlugs[2] == 0))
			//{
			//	arrayFlugs[2] = 1;
			//	CheckList test1(3, 3, 0, FOREGROUND_RED | FOREGROUND_INTENSITY, "[X] World", 1);;
			//}
			//else if ((mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) && (arrayFlugs[2] == 1))
			//{
			//	arrayFlugs[2] = 0;
			//	//CheckList test1(3, 3, 0, FOREGROUND_RED | FOREGROUND_INTENSITY, "[ ] World", 1);;
			//}
		}
		else {
			if (arrayFlugs[2] == 0) {
				//CheckList test1(3, 3, 0, FOREGROUND_BLUE | FOREGROUND_INTENSITY, "[ ] World", 1);;
			}
			if (arrayFlugs[2] == 1) {
				//CheckList test1(3, 3, 0, FOREGROUND_BLUE | FOREGROUND_INTENSITY, "[X] World", 1);;
			}
		}
		//printf("%d", p.x);
		//printf("%d", p.y);
		//cursor position now in p.x and p.y
	}
	//int y, x;
	//getCursorXY(y, x);
	//cout << x << "," << y << endl;
	std::cin.get();
}

void CheckList::MouseEventProc(MOUSE_EVENT_RECORD)
{
}

void CheckList::KeyEventProc(KEY_EVENT_RECORD)
{
}


void CheckList::setForeground(Color color)
{
	
}

void CheckList::setBackground(Color color)
{
}

void CheckList::SetBorder(BorderType border)
{
}

CheckList::~CheckList()
{
}

void CheckList::draw(Graphics& graphics, int left, int top, size_t p)
{
}

void CheckList::keyDown(WORD code, CHAR chr)
{
}

void CheckList::mousePressed(int x, int y, bool isLeft)
{
}

void CheckList::getAllControls(vector<Control*>* vector)
{
}

bool CheckList::canGetFocus()
{
	return true;
}
