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
	MyListener(Control& root):MouseListener(root){}
	void mousePressed(Button& b, int x, int y, bool isLeft) override
	{
		get_root()->setForeground(Color::Blue);
		get_root()->setBackground(Color::Orange);
	};
};


int main()
{
	Panel panel(50, 50);
	MyListener my(panel);
	TextBox text_box(10);
	text_box.set_value("Textbox");
	text_box.setBackground(Color::Red);
	text_box.setForeground(Color::Blue);
	text_box.SetBorder(BorderType::Single);
	Label label(10,"Labael");
	label.setBackground(Color::Orange);
	Combox combox(10,{"Combox","two","three","four"});
	combox.setForeground(Color::Red);
	panel.addControl(text_box, 20, 2);
	panel.addControl(label, 20,6);
	panel.addControl(combox, 20, 10);
	Button button(10);
	button.addListener(my);
	button.setBackground(Color::White);
	button.setForeground(Color::Green);
	panel.addControl(button,20,14);
	EventEngine events;
	events.run(panel);

	return system("pause");
}
