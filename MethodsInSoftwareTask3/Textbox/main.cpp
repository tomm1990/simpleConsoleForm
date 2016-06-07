#include "TextBox.h"

#include <stdio.h>
#include <iostream>>
using namespace std;


int main(int argv , char* argc[]) {
	TextBox tName(20);
	tName.SetBorder( BorderType::Single );
	tName.SetForeground( Color::Red );
	Graphics A;
	tName.draw(A , 25, 2 , 0 );






	
	return system("pause");
}