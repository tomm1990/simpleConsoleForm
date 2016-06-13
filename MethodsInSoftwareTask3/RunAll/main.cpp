#include "../CheckList/CheckList.h"
#include "../Textbox/TextBox.h"
#include "../Control/EventEngine.h"
#include "../Label/Label.h"
#include "../Combox/Combox.h"
#include "../Panel/Panel.h"

int main()
{
	Panel panel(50, 50);

	//TextBox tName(10);
	//tName.SetText("hello");
	//tName.SetBorder( BorderType::Single );
	//tName.setForeground( Color::Red );

	//tName.setBackground( Color::Green );

	TextBox tAdrress(16);
	/*tAdrress.SetBorder(BorderType::Single);
	tAdrress.setForeground( Color::Blue );*/
	
	//tAdrress.SetBorder(BorderType::Single);
	Label A(20, "Hello");
	//A.SetBorder(BorderType::Single);
	//A.setForeground(Color::Green);
	//A.setBackground(Color::Blue);

	
	Combox combox(20, { "apple","banana","orange" });
	Combox combox2(20, { "dani","doni","dina" });
	//combox2.setBackground(Color::White);
	//combox2.setForeground(Color::Blue);
	//combox.setBackground(Color::White);
	//combox.setForeground(Color::Red);


	EventEngine events;
	//panel.addControl(A, 14, 2);

	panel.addControl(combox, 6, 10);
	//panel.addControl(tAdrress, 30, 2);
	//panel.addControl(combox, 14, 6);
	panel.addControl(combox2, 36, 6);
	panel.addControl(tAdrress, 23, 14);

	events.run(panel);

	return system("pause");
}
