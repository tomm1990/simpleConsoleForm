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

auto e = [](Control* c)
{
	auto msg = dynamic_cast<Messagebox*>(c);
	msg->show();
};

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
	TextBox tAddress(30);
	tAddress.setValue("221B Baker Street, London");
	tAddress.setBorder(BorderType::Single);
	Combox cCountry(20, { "Israel", "Great Britain", "United States" });
	cCountry.setSelectedIndex(1);
	cCountry.setBorder(BorderType::Single);
	RadioList rSex(2, 15, { "Male", "Female" });
	rSex.setBorder(BorderType::Single);
	CheckList clInterests(3, 15, { "Sports", "Books", "Movies" });
	cCountry.getSelectedIndex();
	clInterests.selectIndex(1);
	clInterests.setBorder(BorderType::Single);
	NumericBox nAge(15, 18, 120);
	nAge.setValue(23);
	nAge.setBorder(BorderType::Single);
	Button bSubmit(10);
	bSubmit.setValue("Submit");
	bSubmit.setBorder(BorderType::Single);
	Button bExit(10);
	bExit.setValue("Exit");
	bExit.setBorder(BorderType::Single);
	Messagebox msg(10, 25);
	msg.setTitle("Registration succeeded!");
	msg.setText("Bye!");
	Panel main(28,55);
	main.setBackground(Color::Green);
	main.setForeground(Color::Red);
	main.setBorder(BorderType::Double);
	main.addControl(lName, 1, 2);
	main.addControl(lAddress, 1, 5);
	main.addControl(lCountry, 1, 8);
	main.addControl(lSex, 1, 11);
	main.addControl(lInterests, 1, 15);
	main.addControl(lAge, 1, 20);
	main.addControl(tName, 25, 2);
	main.addControl(tAddress, 25, 5);
	main.addControl(cCountry, 25, 8);
	main.addControl(rSex, 25, 11);
	main.addControl(clInterests, 25, 15);
	main.addControl(nAge, 25, 22);
	main.addControl(bSubmit, 2, 23);
	main.addControl(bExit, 10, 23);
	main.addControl(msg, 10, 10);
	bSubmit.addListener(e, &msg);
	Control::setFocus(tName);
	auto engine = EventEngine::getEngine();
	auto eStop = [&](Control* c) {engine.stop(); };
	bExit.addListener(eStop, nullptr);
	engine.run(main);
	return 0;
}