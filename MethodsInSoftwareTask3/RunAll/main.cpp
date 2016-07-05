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

	Combox cityCombox(15,{"Tel Aviv","Ramat Gan","Givataim","Hertzliya"});
	cityCombox.setBackground(Color::Green);
	cityCombox.setForeground(Color::Red);
	cityCombox.setBorderDrawer(BorderType::Single);
	panel.addControl(cityCombox,20,13);
	/*CheckList checklist(10,{"alo","moshe","ma-kore"});
	checklist.setBorderDrawer(BorderType::Single);
	checklist.setBackground(Color::Cyan);
	checklist.setForeground(Color::Red);*/
	//panel.addControl(checklist, 10, 10);

#pragma region original
	auto e = [](Control*c)
	{
		c->show();
	};
	Button b(10);
	b.setBorderDrawer(BorderType::Single);
	b.setValue("showMsgBox");
	panel.addControl(b, 30, 7);
	Label nameLabel(5, "Name : ");
	nameLabel.setBorderDrawer(BorderType::Single);

	TextBox nameTextBox(15);
	nameTextBox.setBorderDrawer(BorderType::Double);
	
	Label hobbiesLabel(10, "Hobbies");
	hobbiesLabel.setBorderDrawer(BorderType::Single);

	CheckList hobbiesCheckList(10,{"Movies", "Sports", "Cars"});
	hobbiesCheckList.setBorderDrawer(BorderType::Double);

	Label ageLabel(5, "Age :");
	ageLabel.setBorderDrawer(BorderType::Single);

	NumericBox ageNumericBox(11, 18, 120);
	ageNumericBox.setBorderDrawer(BorderType::Double);

	panel.addControl(nameLabel, 3, 2);
	panel.addControl(nameTextBox, 11, 2);
	panel.addControl(hobbiesLabel, 30, 2);
	panel.addControl(hobbiesCheckList, 43, 2);
	panel.addControl(ageLabel, 3, 5);
	panel.addControl(ageNumericBox, 11, 5);
#pragma endregion

#pragma region Messagebox
	Messagebox alert(9,40);
	alert.setBorderDrawer(BorderType::Single);
	alert.setTitle("Hello");
	alert.setText("Methods in Software Engineering");
	b.addListener(e, &alert);
#pragma endregion 
	panel.addControl(alert, 10, 3);
	Control::setFocus(nameTextBox);
	EventEngine events;
	events.run(panel);
	return system("pause");
}