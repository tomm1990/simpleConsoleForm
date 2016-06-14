#include "../CheckList/CheckList.h"
#include "../Textbox/TextBox.h"
#include "../Control/EventEngine.h"
#include "../Label/Label.h"
#include "../Combox/Combox.h"
#include "../Panel/Panel.h"
#include "../Button/Button.h"


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
	Panel panel(17,40);
	SingleBorder single;
	DoubleBorder Double;
	panel.setBorderDrawer(single);
	Label nameLabel(10,"Name:");
	nameLabel.setBorderDrawer(Double);
	Label addressLabel(10, "Address:");
	addressLabel.setBorderDrawer(Double);
	TextBox nameTextBox(15);
	nameTextBox.setBorderDrawer(single);
	TextBox addressTextBox(15);
	addressTextBox.setBorderDrawer(single);
	Label ageLabel(10,"Age:");
	ageLabel.setBorderDrawer(Double);
	Combox ageCombox(15,{"20","21","22","23"});
	ageCombox.setBorderDrawer(single);
	Button button(8);
	button.SetText("Submit");
	button.setBorderDrawer(Double);
	button.setForeground(Color::Blue);
	button.setBackground(Color::Green);
	panel.addControl(nameLabel, 3, 3);
	panel.addControl(nameTextBox, 15,3);
	panel.addControl(addressLabel, 3, 6);
	panel.addControl(addressTextBox, 15, 6);
	panel.addControl(ageLabel, 3, 9);
	panel.addControl(ageCombox, 15, 9);
	panel.addControl(button, 10, 14);
	MyListener my(panel);
	button.addListener(my);
	EventEngine events;
	events.run(panel);

	return system("pause");

}