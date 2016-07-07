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
	Label lName(20);
	lName.setValue("Name: ");
	Label lAddress(20);
	lAddress.setValue("Address:");
	Label lCountry(20);
	lCountry.setValue("Counrty:");
	Label lSex(20);
	lSex.setValue("Sex:");
	Label lInterests(20);
	lInterests.setValue("Interests:");
	Label lAge(20);
	lAge.setValue("Age:");
	TextBox tName(20);
	tName.setValue("Sherlock Holmes");
	tName.setBorder(BorderType::Single);
	TextBox tAddress(25);
	tAddress.setValue("221B Baker Street, London");
	tAddress.setBorder(BorderType::Single);
	Combox cCountry(20, { "Israel", "Great Britain", "United States" });
//	cCountry.setSelectedIndex(1);
	cCountry.setBorder(BorderType::Single);
//	Radiolist rSex(2, 15, { "Male", "Female" });
//	rSex.setBorder(BorderType::Single);
	CheckList clInterests(3, 15, { "Sports", "Books", "Movies" });
	clInterests.setBackground(Color::Orange);
	clInterests.selectIndex(1);
//	clInterests.setBorder(BorderType::Single);
	NumericBox nAge(15, 18, 120);
	nAge.setValue(23);
	nAge.setBorder(BorderType::Single);
//	MyListener listener(tAddress);
	Button bSubmit(10);
//	bSubmit.setText("Submit");
//	bSubmit.addListener(listener);
	bSubmit.setBorder(BorderType::Double);
	Panel main(25,50);
	//main.setBorder(BorderType::Single);
	main.setBackground(Color::Green);
	main.setForeground(Color::Red);
//	main.addControl(lName, 1, 2);
//	main.addControl(lAddress, 1, 5);
//	main.addControl(lCountry, 1, 8);
//	main.addControl(lSex, 1, 11);
//	main.addControl(lInterests, 1, 15);
//	main.addControl(lAge, 1, 20);
//	main.addControl(tName, 25, 2);
//	main.addControl(tAddress, 25, 5);
//	main.addControl(cCountry, 25, 8);
//	main.addControl(rSex, 25, 11);
	main.addControl(clInterests, 25, 15);
//	main.addControl(nAge, 25, 20);

	main.addControl(bSubmit, 1, 22);
	Control::setFocus(clInterests);
	EventEngine engine;
	engine.run(main);
	return 0;

}