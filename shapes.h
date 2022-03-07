#pragma once
#include "safe_input.h"
#include <fstream>

class shapes
{
protected:
	int id;
	shapes() : id(0)
	{}
public:
	static size_t count;
	virtual void volume() = 0;
	virtual void set_data() = 0;
	virtual void display_data() = 0;
	virtual void diskIn() = 0;
	virtual void diskOut() = 0;
};
