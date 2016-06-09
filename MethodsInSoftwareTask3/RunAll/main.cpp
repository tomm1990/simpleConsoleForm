#include "../CheckList/CheckList.h"
#include "../Textbox/TextBox.h"
#include "../Control/EventEngine.h"
#include "../Label/Label.h"

int main()
{
	//TextBox tName(10);
	//tName.SetText("Hello");
	//tName.SetBorder( BorderType::Single );
	//tName.SetForeground( Color::Blue );
	
	
	Label A(20, "Hello");
	A.SetBorder(BorderType::Single);
	A.SetForeground(Color::Green);
	A.SetBackground(Color::Blue);



	EventEngine engine;
	engine.run(A);

	return system("pause");
}
