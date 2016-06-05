#include "TextBox.h"
#include <iostream>>
using namespace std;


int main() {
	TextBox tName(20);
	tName.SetText("Sherlock Holmes");
	tName.SetBorder( BorderType::Single );




	system("pause");
	return 0;
}