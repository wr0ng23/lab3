#pragma once
#include "shapes.h"

class tetrahedron final : public shapes
{
private:
	float a;
public:
	tetrahedron();
	virtual void set_data() override final;
	virtual void display_data() override final;
	virtual void volume() override final;
	virtual void diskIn() override final;
	virtual void diskOut() override final;
};
