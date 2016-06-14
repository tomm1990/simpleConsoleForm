#include "../CheckList/CheckList.h"
#include "../Textbox/TextBox.h"
#include "../Control/EventEngine.h"
#include "../Label/Label.h"
#include "../Combox/Combox.h"
#include "../Panel/Panel.h"

int main()
{
	Panel panel(20, 60);
	SingleBorder panelBorder;
	panel.setBorderDrawer(panelBorder);
	
	Label label(30, "Label");
	DoubleBorder n;
	label.setBorderDrawer(n);

	TextBox text_box(10);
	SingleBorder d;
	text_box.setBorderDrawer(d);
	
	text_box.set_value("TextBox");
	text_box.setBackground(Color::Red);
	text_box.setForeground(Color::Blue);
	
	panel.addControl(label, 20, 2);
	panel.addControl(text_box, 3, 2);
	EventEngine events;
	events.run(panel);

	return system("pause");
}