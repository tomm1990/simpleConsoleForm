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

class MyListener :public MouseListener
{
public:
	MyListener(Control& root) :MouseListener(root) {}
	void mousePressed(Button& b, int x, int y, bool isLeft) override
	{
		get_root()->hide();
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
	RadioList genderRadioList(3,10, { "Male","Female" });
	genderRadioList.setBorderDrawer(BorderType::Single);
	Label hobbiesLabel(10, "Hobbies:");
	hobbiesLabel.setBorderDrawer(BorderType::Double);
	CheckList hobbiesChecklList(3,10,{"Music", "Sport", "Movies"});

	hobbiesChecklList.setBorderDrawer(BorderType::Single);
	
	Label ageLabel(10, "Age :");
	ageLabel.setBorderDrawer(BorderType::Double);
	
	Label myLabel(10, "myLabel");
	myLabel.setBorderDrawer(BorderType::Double);
	
	NumericBox ageNumericBox(6, 18, 120);
	ageNumericBox.setBorderDrawer(BorderType::Single);
	ageNumericBox.setValue("30");

	Button button(8);
	button.SetText("Submit");
	button.setBorderDrawer(BorderType::Double);
	button.setForeground(Color::Blue);
	button.setBackground(Color::Green);
	
#pragma region default
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
	panel.addControl(myLabel,15, 12);
	panel.addControl(ageLabel, 35, 11);
	panel.addControl(ageNumericBox, 48, 11);
#pragma endregion default

	panel.addControl(button, 25, 16);
	
//#pragma region Messagebox
//	Label messageBoxTitle(11, "  Welcome");
//	messageBoxTitle.setBorderDrawer(BorderType::Double);
//	Label messageBoxText(35, "  Methods In Software Engineering");
//	messageBoxText.setBorderDrawer(BorderType::Single);
//	Button buttonOkay(8);
//	buttonOkay.SetText("   OK");
//	buttonOkay.setBorderDrawer(BorderType::Double);
//	buttonOkay.setBackground(Color::Green);
//	buttonOkay.setForeground(Color::Purple);
//	Button buttonCancel(8);
//	buttonCancel.SetText(" Cancel");
//	buttonCancel.setForeground(Color::Cyan);
//	buttonCancel.setBackground(Color::White);
//	Messagebox messageBox(9, 39);
//	messageBox.setBorderDrawer(BorderType::Double);
//
//	panel.addControl(messageBox, 10, 5);
//	messageBox.addControl(messageBoxTitle, 13, 1);
//	messageBox.addControl(messageBoxText, 2, 4);
//	messageBox.addControl(buttonOkay, 8, 7);
//	messageBox.addControl(buttonCancel, 25, 7);
//#pragma endregion Messagebox
	
	
	MyListener my(panel);
	button.addListener(my);
	EventEngine events;
	events.run(panel);

	return system("pause");
}