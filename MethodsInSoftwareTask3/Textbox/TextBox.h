#pragma once
#include <iterator>
#include <sstream>
#include "../Control/Control.h"

class TextBox :
	public Control
{
private:
	stringstream s;
	string out;
	vector<char> _value;
	int _textLength, counter, _SavedColors , i , j;
	COORD _CursorPosition;
	//DWORD _componentfdwMode;
	CONSOLE_SCREEN_BUFFER_INFO _textBoxBufferInfo;
	CONSOLE_CURSOR_INFO _ComponentCursor;			// keeps info about current cursor

	struct textBoxBorder {
		char top_left = '\xDA';
		char horizontal_line = '\xC4';
		char top_right = '\xBF';
		char vertical_line = '\xB3';
		char buttom_left = '\xC0';
		char buttom_right = '\xD9';
	} _textBoxBorder;

public:
	//Defualt Constructor
	TextBox(int width);
	virtual ~TextBox();
	
	void setForeground(Color color) override;
	void setBackground(Color color) override;
	void SetBorder(BorderType border) override;
	void SetText(string value);
	void SetSavedColors(const int);
	int getSavedColors() const { return _SavedColors; }
	string getValuse();
	void draw(Graphics& graphics, int i, int i1, size_t size_t);
	void writeBorder(char);
	//void draw(const Graphics& graphics, int left, int top){};
	//virtual void draw(const Graphics& graphics, int i, int i1);
	
	void resetOutput() ;
	void keyDown(WORD code, CHAR chr) override;
	void mousePressed(int x, int y, bool isLeft) override;
	void getAllControls(vector<Control*>* vector) override;
	bool canGetFocus() override;
	WORD GetConsoleTextAttribute(HANDLE hCon);
	void setcursor(bool visible, DWORD size);
	void MoveToRight();
	void MoveToLeft();

	
};
