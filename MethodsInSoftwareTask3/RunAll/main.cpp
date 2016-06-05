#include "../Combox/Combox.h"
#include "../Form/Form.h"
#include "../Control/Root.h"
#include "../Textbox/TextBox.h"
#include "../RadioList/RadioList.h"
#include "../Label/Label.h"
#include "../Checklist/CheckList.h"
#include "../Control/EventEngine.h"
#include "../Panel/Panel.h"


int main(void)
{
/*	int width = 10;
	int widthhhhhh = 67676;

	//Combox example

	combox.Show();
	combox.listen();

	//TextBox example
	TextBox textBox(width);

	//RadioList example
	RadioList radioList(width);

	//Label example
	Label label(width);

	//Checklist example
	CheckList checklist(width);
*/
	EventEngine e;
	vector<string> list;
	list.push_back("apple");
	list.push_back("banana");
	list.push_back("orange");
	Combox combox(10, list);
	e.run(combox);
	Graphics g;
	g.write("asdsadasdasd");
	g.clearScreen();
	

}



