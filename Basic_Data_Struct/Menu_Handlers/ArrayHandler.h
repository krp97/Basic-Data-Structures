#pragma once
#include "Handler.h"
#include "../Data_Structures/Array_base/Array.h"

class ArrayHandler : private Handler
{
	Array * myArray;
public:

	virtual void initConsole();

	ArrayHandler();
	~ArrayHandler();
};

