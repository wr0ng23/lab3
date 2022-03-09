#pragma once
#include "safe_input.h"
#include <fstream>

class shapes
{
public:
	virtual ~shapes()
	{}
	static size_t count;
	virtual void volume() const = 0;
	virtual void set_data() = 0;
	virtual void display_data() const = 0;
	virtual void diskIn() = 0;
	virtual void diskOut() const = 0;
};