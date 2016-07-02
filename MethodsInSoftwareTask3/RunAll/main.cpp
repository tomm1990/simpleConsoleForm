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
	cityCombox.setBorderDrawer(BorderType::Single);
	panel.addControl(cityCombox,5,5);
	EventEngine events;
	events.run(panel);
	return system("pause");
}