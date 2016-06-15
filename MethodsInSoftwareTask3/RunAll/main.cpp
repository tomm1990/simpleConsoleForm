#include "../CheckList/CheckList.h"
#include "../Textbox/TextBox.h"
#include "../Control/EventEngine.h"
#include "../Label/Label.h"
#include "../Combox/Combox.h"
#include "../Panel/Panel.h"
#include "../Button/Button.h"
#include "../RadioList/RadioList.h"
#include "../NumericBox/NumericBox.h"

class NumericBox;

class MyListener :public MouseListener
{
public:
	MyListener(Control& root) :MouseListener(root) {}
	void mousePressed(Button& b, int x, int y, bool isLeft) override
	{
		get_root()->setForeground(Color::Blue);
		get_root()->setBackground(Color::Orange);
	};
};

int main()
{
	Panel panel(17,60);
	SingleBorder single;
	DoubleBorder Double;
	NoneBorder none;;
	panel.setBorderDrawer(BorderType::Double);
	Label nameLabel(10,"Name:");
	nameLabel.setBorderDrawer(BorderType::Double);
	Label addressLabel(10, "Address:");
	addressLabel.setBorderDrawer(BorderType::Double);
	TextBox nameTextBox(15);
	nameTextBox.setBorderDrawer(BorderType::Single);
	TextBox addressTextBox(15);
	addressTextBox.setBorderDrawer(BorderType::Single);
	Label cityLabel(10,"City:");
	cityLabel.setBorderDrawer(BorderType::Double);
	Combox cityCombox(15,{"Tel Aviv","Ramat Gan","Givataim","Hertzliya"});
	cityCombox.setBorderDrawer(BorderType::Single);
	Label gendarLabel(10, "Gender:");
	gendarLabel.setBorderDrawer(BorderType::Double);
	RadioList genderRadioList(10, { "Male","Female" });
	genderRadioList.setBorderDrawer(BorderType::Single);
	Label hobbiesLabel(10, "Hobbies:");
	hobbiesLabel.setBorderDrawer(BorderType::Double);
	CheckList hobbiesChecklList(10,{"Music", "Sport", "Movies"});
	hobbiesChecklList.setBorderDrawer(BorderType::Single);
	
	Label ageLabel(10, "Age :");
	ageLabel.setBorderDrawer(BorderType::Double);
	
	NumericBox ageNumericBox(6, 18, 120);
	ageNumericBox.setBorderDrawer(BorderType::Single);
	ageNumericBox.setValue(30);

	Button button(8);
	button.SetText("Submit");
	button.setBorderDrawer(BorderType::Double);
	button.setForeground(Color::Blue);
	button.setBackground(Color::Green);
	
	panel.addControl(nameLabel, 3, 3);
	panel.addControl(nameTextBox, 15,3);
	panel.addControl(gendarLabel, 35, 3);
	panel.addControl(hobbiesLabel, 48, 3);
	panel.addControl(addressLabel, 3, 6);
	panel.addControl(addressTextBox, 15, 6);
	panel.addControl(genderRadioList, 35, 6);
	panel.addControl(hobbiesChecklList, 48, 6);
	panel.addControl(cityLabel, 3, 9);
	panel.addControl(cityCombox, 15, 9);
	panel.addControl(ageLabel, 35, 11);
	panel.addControl(ageNumericBox, 48, 11);
	panel.addControl(button, 23, 15);
	MyListener my(panel);
	button.addListener(my);
	EventEngine events;
	events.run(panel);

	return system("pause");
}