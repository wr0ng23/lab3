#pragma once
#include "shapes.h"

class parallelepiped final : public shapes
{
private:
	float S;
	float h;
public:
	parallelepiped();
	virtual void set_data() override final;
	virtual void display_data() override final;
	virtual void volume() override final;
	virtual void diskIn() override final;
	virtual void diskOut() override final;
};