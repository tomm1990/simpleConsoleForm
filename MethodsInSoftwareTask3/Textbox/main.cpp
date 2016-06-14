#include "TextBox.h"


int main(int argv , char* argc[]) {
	TextBox tName(20);
	//tName.SetText("Hello");
	//tName.setBorderDrawer( SingleBorder );
	tName.setForeground( Color::Blue );
	
	Graphics A;
	tName.draw(A, 5, 5, 0);





	string n;
	cin >> n;


	
	return system("pause");
}