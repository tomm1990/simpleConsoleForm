#include "TextBox.h"

TextBox::TextBox(int width): Control(width)
{
	if (position.X < 0 || position.Y < 0) return;
	dim = { (SHORT)width , 3 };
	_SavedColors = GetConsoleTextAttribute(hOut);
	_CursorPosition.X = position.X;
	_CursorPosition.Y = position.Y + 1;
	_textLength = counter = 0;
	//_componentfdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	SetConsoleCursorPosition(hOut, _CursorPosition);
	GetConsoleScreenBufferInfo(hOut, &_textBoxBufferInfo);
	setConsole_CursorPos_TextAttr(hOut, _CursorPosition, 0); //test
	_ComponentCursor = { (unsigned long)width , TRUE };
	SetConsoleCursorInfo(hOut, &_ComponentCursor);
	//_SavedColors = GetConsoleTextAttribute(hOut);
}

TextBox::~TextBox()
{
}



//void TextBox::setForeground(Color color){
//	graphics.setForeground(color);
//	graphics.updateConsoleAttributes();
//}

//void TextBox::setBackground(Color color){
//	graphics.setBackground(color);
//	graphics.updateConsoleAttributes();
//}

void TextBox::setForeground(Color color)
{
	Control::setForeground(color);
	_CustomColor = GetConsoleTextAttribute(hOut);
	resetOutput();

}

void TextBox::setBackground(Color color = Color::Black)
{
	_CustomColor = GetConsoleTextAttribute(hOut);
	resetOutput();

}

void TextBox::SetBorder(BorderType border)
{
	this->border = border;
}

void TextBox::SetText(string value)
{
	if (!_value.empty()) _value.erase(_value.begin(), _value.end());
	copy(value.begin(), value.end(), back_inserter(_value));
}

void TextBox::SetSavedColors(const int color){
	_SavedColors = color;
}

string TextBox::getValuse()
{
	string tempValue;
	for (int i = 0; i < _value.size(); i++) tempValue += _value[i];
	return tempValue;
}

void TextBox::draw(Graphics& graphics, int i, int i1, size_t p)
{
	Control::draw(graphics, i, i1, 0);
	//setcursor(true, 10);
	// i = left
	// i1  =  top
	_CursorPosition.X = (SHORT)i + 1;
	_CursorPosition.Y = (SHORT)i1 + 1;
	this->position = { (SHORT)i ,(SHORT)i1 };
	if (border == BorderType::Single) {
		//SetConsoleCursorPosition(hOut, { position.X , position.Y });
		writeBorder(_textBoxBorder.top_left);
		//s << _textBoxBorder.horizontal_line;
		for ( i = 0; i < width; i ++) 	writeBorder(_textBoxBorder.horizontal_line);
		writeBorder(_textBoxBorder.top_right);
		graphics.write(s.str() + "\n");
		SetConsoleCursorPosition(hOut, { position.X, position.Y+1  });
		
		writeBorder( _textBoxBorder.vertical_line);
		//for ( j = 0; j < 1; j++) {
		//graphics.write(s.str());
		for ( i = 0; i <  width; i++) graphics.write(" ");
		writeBorder(_textBoxBorder.vertical_line);
		graphics.write(s.str()+"\n");
		SetConsoleCursorPosition(hOut, { position.X, position.Y + 2 });
		//}

		writeBorder(_textBoxBorder.buttom_left);
		//graphics.write(s.str());
		//writeBorder( _textBoxBorder.horizontal_line);
		for ( i = 0; i <  width; i++) writeBorder(_textBoxBorder.horizontal_line);
		writeBorder( _textBoxBorder.buttom_right);	
	}
	else if (border == BorderType::Double) {
		
	}
	else {

	}
	//setConsole_CursorPos_TextAttr(hOut, { _CursorPosition.X, _CursorPosition.Y }, _SavedColors); //test
	_ComponentCursor.bVisible = true;
	resetOutput();
}

void TextBox::writeBorder(char outPut)
{
	s << outPut;
	graphics.write(s.str());
	s.str("");
}

void TextBox::resetOutput() 
{
	_value.shrink_to_fit();
	setConsole_CursorPos_TextAttr(hOut, { position.X+1, position.Y+1 }, _SavedColors); //test
	for (i = 0; i < _value.size() + 1 ; i++) graphics.write(" ");
	setConsole_CursorPos_TextAttr(hOut, { position.X + 1, position.Y + 1 }, _SavedColors); //test
	for ( i = 0; i < _value.size(); i++) writeBorder( _value[i] );
}

void TextBox::keyDown(WORD code, CHAR chr)
{
	counter = _value.size();
	if ((chr >= 64 &&
		chr <= 91) ||
		(chr >= 96 &&
			chr <= 123) ||
			(chr >= 47 &&
				chr <= 58) ||
		chr == 32) {
		if (counter < width-1) {
			counter++;
			getCursorXY(_CursorPosition.X, _CursorPosition.Y);
			if (_CursorPosition.X >= position.X + _value.size() + 1 ) {
				writeBorder(chr);
				_value.push_back(chr);
				_CursorPosition.X++;
				resetOutput();
			}
			else{
				_value.insert((_value.begin() + _CursorPosition.X - position.X -1), chr);
				_CursorPosition.X++;
				resetOutput();
				setConsole_CursorPos_TextAttr(hOut, { _CursorPosition.X , position.Y + 1 }, _SavedColors); //test

			}
			
		}
		
	}
	else if (chr == 8) { // if backspace was clicked
		counter--;
		if (counter == -1) counter = 0;
		getCursorXY(_CursorPosition.X, _CursorPosition.Y);
		if(_CursorPosition.X   >=  position.X + _value.size() + 1 && _value.size()!=0 )  {
				//endOfString = _value.back();
				try { _value.pop_back(); }
				catch(EXCEPINFO){}
				resetOutput();
		}
		else if(_CursorPosition.X > position.X+1){
			_value.erase(_value.begin() + _CursorPosition.X - position.X -1);
			resetOutput();
			setConsole_CursorPos_TextAttr(hOut, { --_CursorPosition.X , position.Y + 1 }, _SavedColors); //test

		}
			

			//if (_CursorPosition.X == _CursorPosition.X + _value.size() + 2) {
				//SetConsoleCursorPosition(hOut, { (SHORT)(_CursorPosition.X + counter + 2), (SHORT)(_CursorPosition.Y + 2) });
				//cout << " ";
				//SetConsoleCursorPosition(hOut, { (SHORT)(_CursorPosition.X + counter + 2), (SHORT)(_CursorPosition.Y + 2) });
				//_CursorPosition.X--;
			//}
			//else if (_CursorPosition.X < position.X + _value.size() + 2) {
				//SetConsoleCursorPosition(hOut, { (SHORT)(_CursorPosition.X), (SHORT)(_CursorPosition.Y + 2) });
				//cout << " ";
				//SetConsoleCursorPosition(hOut, { (SHORT)(--_CursorPosition.X),(SHORT)(_CursorPosition.Y + 2) });
				//getCursorXY(_CursorPosition.X, _CursorPosition.Y);
				//_value.erase(_CursorPosition.X - position.X, 1);
				//setConsole_CursorPos_TextAttr(hOut, { position.X + 1, position.Y + 1 }, _SavedColors);
				//for (int i = 0; i < width; i++) cout << " ";
				//setConsole_CursorPos_TextAttr(hOut, { position.X + 1, position.Y + 1 }, _SavedColors);
				//_value += endOfString;
				//cout << _value.c_str();
			//}
			
	} 
	else if(code == 39) {// right key pressed
		MoveToRight();
		
	}
	else if (code == 37) { // left key pressed
		MoveToLeft();

	}

	
}

void TextBox::mousePressed(int i, int y, bool b)
{
	if(b && i>getLeft() && i<getLeft()+width && y>getTop() && y<getTop()+2){
		setConsole_CursorPos_TextAttr(hOut,{(SHORT)i,(SHORT)y} , _SavedColors);
	}
}

void TextBox::getAllControls(vector<Control*>* vector)
{
	//vector->push_back(this);
}

bool TextBox::canGetFocus()
{
	return true;
}

WORD TextBox::GetConsoleTextAttribute(HANDLE hCon)
{
	CONSOLE_SCREEN_BUFFER_INFO con_info;
	GetConsoleScreenBufferInfo(hCon, &con_info);
	return con_info.wAttributes;
}

//void TextBox::draw(const Graphics& graphics, int width, int height) {
//	
//	//Control::SetBorder(graphics.)
//	//cout << SetBorder( ;
//	//for (int i = 0; i < _widthTextBox; i++) cout << _textBoxBorder.horizontal_line;
//	//cout << _textBoxBorder.top_right << endl;
//	//SetConsoleCursorPosition(hOut, { ++position.X, ++position.Y + 1 });
//	//for (int j = 0; j < 1; j++) {
//	//	cout << _textBoxBorder.vertical_line;
//	//	for (int i = 0; i < _widthTextBox; i++) cout << ' ';
//	//	cout << _textBoxBorder.vertical_line << endl;
//	//	SetConsoleCursorPosition(hOut, { position.X, position.Y + 2 });
//	//}
//	//cout << _textBoxBorder.buttom_left;
//	//for (int i = 0; i < _widthTextBox; i++) cout << _textBoxBorder.horizontal_line;
//	//cout << _textBoxBorder.buttom_right << endl;
//}

void TextBox::setcursor(bool visible, DWORD size) // set bool visible = 0 - invisible, bool visible = 1 - visible
{
	if (size == 0)
	{
		size = 20;	// default cursor size Changing to numbers from 1 to 20, decreases cursor width
	}
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(hOut , &lpCursor);
}

void TextBox::MoveToRight() {
	getCursorXY(_CursorPosition.X, _CursorPosition.Y);
	if (_CursorPosition.X < _value.size()+1 ) {
		setConsole_CursorPos_TextAttr(hOut, { ++_CursorPosition.X, _CursorPosition.Y }, _SavedColors);
	}
}

void TextBox::MoveToLeft() {
	getCursorXY(_CursorPosition.X, _CursorPosition.Y);
	if (_CursorPosition.X > position.X + 1) {
		setConsole_CursorPos_TextAttr(hOut, { --_CursorPosition.X, _CursorPosition.Y }, _SavedColors);
	}
}