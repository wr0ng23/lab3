#pragma once
#include "shapes.h"

class pyramid final : public shapes
{
private:
	float S;
	float h;
public:
	pyramid();
	~pyramid();
	virtual void set_data() override final;
	virtual void display_data() const override final;
	virtual void volume() const override final;
	virtual void diskIn() override final;
	virtual void diskOut() const override final;
};