#include "../Combox/Combox.h"
#include "../Form/Form.h"
#include "../Control/Root.h"
#include "../Textbox/TextBox.h"
#include "../RadioList/RadioList.h"
#include "../Label/Label.h"
#include "../Checklist/CheckList.h"


int main(void)
{
	int width = 10;
	int widthhhhhh = 400;

	//Combox example
	vector<string> list;
	list.push_back("apple");
	list.push_back("banana");
	list.push_back("orange");
	Combox combox(width, list);
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
}
