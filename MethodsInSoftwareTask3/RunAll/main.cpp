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
	panel.setBorderDrawer(BorderType::Double);
	/*Combox cityCombox(15,{"Tel Aviv","Ramat Gan","Givataim","Hertzliya"});
	cityCombox.setBackground(Color::Green);
	cityCombox.setForeground(Color::Red);
	cityCombox.setBorderDrawer(BorderType::Single);
	panel.addControl(cityCombox,5,5);
	CheckList checklist(10,{"alo","moshe","ma-kore"});
	checklist.setBorderDrawer(BorderType::Single);
	checklist.setBackground(Color::Cyan);
	checklist.setForeground(Color::Red);*/
	//panel.addControl(checklist, 10, 10);
	NumericBox a(5,18,120);
	a.setValue("25");
	a.setBorderDrawer(BorderType::Single);
	panel.addControl(a,6,10);
	Control::setFocus(a);
	EventEngine events;
	events.run(panel);
	return system("pause");
}