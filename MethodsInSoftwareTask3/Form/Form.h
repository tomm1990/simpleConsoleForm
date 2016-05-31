#pragma once
#include "../Control/Container.h"

class Form :
	public Container
{
public:
	virtual ~Form();
	void Show() override;
	void Hide() override;
};
