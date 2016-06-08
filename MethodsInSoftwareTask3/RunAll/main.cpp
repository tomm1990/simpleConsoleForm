#include "../CheckList/CheckList.h"
#include "../Textbox/TextBox.h"
#include "../Control/EventEngine.h"


int main()
{
	//vector<string> options = { "[ ] Tommyyyy", "[ ] Goldennnn", "[ ] Ladyyyy", "[ ] Boyyy" };
	//CheckList(10, 20, options );
	TextBox tName(10);
	//tName.SetText("Hello");
	tName.SetBorder(BorderType::Single);
	tName.SetForeground(Color::Blue);
	Graphics A;
	tName.draw(A, 10, 10, 0);

	EventEngine engine;
	engine.run(tName);

	return system("pause");
}
