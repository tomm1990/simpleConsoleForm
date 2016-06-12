#include "TextBox.h"

#include <stdio.h>
#include <iostream>>
using namespace std;


int main(int argv , char* argc[]) {
	TextBox tName(20);
	//tName.SetText("Hello");
	tName.SetBorder( BorderType::Single );
	tName.setForeground( Color::Blue );
	
	Graphics A;
	tName.draw(A, 5, 5, 0);





	string n;
	cin >> n;


	
	return system("pause");
}