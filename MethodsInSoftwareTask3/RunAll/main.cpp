#include "../CheckList/CheckList.h"
#include "../Textbox/TextBox.h"
#include "../Control/EventEngine.h"
#include "../Label/Label.h"
#include "../Combox/Combox.h"
#include "../Panel/Panel.h"
#include "../Button/Button.h"
#include "../RadioList/RadioList.h"
#include "../NumericBox/NumericBox.h"
#include "../MessageBox/Messagebox.h"


int main()
{
	Panel panel(17,60);
	panel.setBackground(Color::Blue);
	panel.setBorderDrawer(BorderType::Single);
	Combox combox(10,{"tel-aviv","ramat-gan","Gadera"});
	combox.setBackground(Color::Green);
	combox.setBorderDrawer(BorderType::Single);
	combox.setForeground(Color::Red);
	panel.addControl(combox, 5, 5);
	Button b(4);
	b.setBorderDrawer(BorderType::Single);
	b.setValue("hide");
	auto event = [&]() {panel.hide(); };
	b.addListener(event);
	panel.addControl(b, 2, 2);
	EventEngine events;
	events.run(panel);

	return system("pause");
}