#include "Combox.h"

int main(void)
{
	int width = 10;
	vector<string> list;
	list.push_back("apple");
	list.push_back("banana");
	list.push_back("orange");
	Combox combox(width, list);

	combox.Show();
}
