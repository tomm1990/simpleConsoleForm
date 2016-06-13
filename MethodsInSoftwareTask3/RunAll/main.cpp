#include "../CheckList/CheckList.h"
#include "../Textbox/TextBox.h"
#include "../Control/EventEngine.h"
#include "../Label/Label.h"
#include "../Combox/Combox.h"
#include "../Panel/Panel.h"

int main()
{
	Panel panel(50, 50);
	TextBox text_box(10);
	text_box.set_value("Fuck!");
	text_box.setBackground(Color::Red);
	text_box.setForeground(Color::Blue);
	Combox combox(20, { "one","two","three" });
	panel.addControl(text_box, 3, 2);
	panel.addControl(combox, 10, 4);
	EventEngine events;
	events.run(panel);

	return system("pause");
}
