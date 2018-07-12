#pragma once
#include "Handler.h"
#include "..\Data_Structures\Array_base\Stack.h"

class StackHandler : private Handler{
	
	Stack * myStack;
protected:

	void initConsole();

public:
	StackHandler();

	~StackHandler();
};