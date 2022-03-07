#pragma once
#include "shapes.h"

class sphere final : public shapes
{
private:
	float R;
public:
	sphere();
	virtual void set_data() override final;
	virtual void display_data() override final;
	virtual void volume() override final;
	virtual void diskIn() override final;
	virtual void diskOut() override final;
};
