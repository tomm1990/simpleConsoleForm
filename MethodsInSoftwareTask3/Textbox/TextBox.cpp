#include "TextBox.h"

TextBox::TextBox(int width): Control(width)
{

}

TextBox::~TextBox()
{
}

void TextBox::MouseEventProc(MOUSE_EVENT_RECORD)
{
}

void TextBox::KeyEventProc(KEY_EVENT_RECORD)
{
}

void TextBox::SetForeground(Color color){
	graphics.setForeground(color);
}

void TextBox::SetBackground(Color color){
	graphics.setBackground(color);
}

void TextBox::SetBorder(BorderType border)
{
	this->border = border;
}

void TextBox::SetText(string value)
{
	cout << "Left is : " << getLeft();
	cout << "Top is : " << getTop();
	SetConsoleCursorPosition(hOut, { getLeft() , getTop() });
	_value = value;
	cout << value;
}

string TextBox::getValuse()
{
	return this->_value;
}

void TextBox::draw(const Graphics& graphics, int i, int i1, size_t size_t)
{
	// i = left
	// i1  =  top
	this->position = { (SHORT)i ,(SHORT)i1 };
	if (border == BorderType::Single) {
		SetConsoleCursorPosition(hOut, { position.X , position.Y });
		cout << _textBoxBorder.top_left;
		for (int i = 0; i < this->width ; i++) cout << _textBoxBorder.horizontal_line;
		cout << _textBoxBorder.top_right << endl;
		SetConsoleCursorPosition(hOut, { position.X, position.Y+1  });
		for (int j = 0; j < 1; j++) {
			cout << _textBoxBorder.vertical_line;
			for (int i = 0; i <  this->width; i++) cout << ' ';
			cout << _textBoxBorder.vertical_line << endl;
			SetConsoleCursorPosition(hOut, { position.X, position.Y + 2 });
		}
		cout << _textBoxBorder.buttom_left;
		for (int i = 0; i <  this->width; i++) cout << _textBoxBorder.horizontal_line;
		cout << _textBoxBorder.buttom_right << endl;
	}
	else if (border == BorderType::Double) {
		
	}
	else {

	}





}

void TextBox::keyDown(WORD code, CHAR chr)
{
}

void TextBox::mousePressed(int i, int y, bool b)
{
}

void TextBox::getAllControls(vector<Control*>* vector)
{
}

bool TextBox::canGetFocus()
{
	return true;
}

//void TextBox::draw(const Graphics& graphics, int width, int height) {
//	
//	//Control::SetBorder(graphics.)
//	//cout << SetBorder( ;
//	//for (int i = 0; i < _widthTextBox; i++) cout << _textBoxBorder.horizontal_line;
//	//cout << _textBoxBorder.top_right << endl;
//	//SetConsoleCursorPosition(_componentHandleOUT, { ++_ComponentPosition.X, ++_ComponentPosition.Y + 1 });
//	//for (int j = 0; j < 1; j++) {
//	//	cout << _textBoxBorder.vertical_line;
//	//	for (int i = 0; i < _widthTextBox; i++) cout << ' ';
//	//	cout << _textBoxBorder.vertical_line << endl;
//	//	SetConsoleCursorPosition(_componentHandleOUT, { _ComponentPosition.X, _ComponentPosition.Y + 2 });
//	//}
//	//cout << _textBoxBorder.buttom_left;
//	//for (int i = 0; i < _widthTextBox; i++) cout << _textBoxBorder.horizontal_line;
//	//cout << _textBoxBorder.buttom_right << endl;
//}
