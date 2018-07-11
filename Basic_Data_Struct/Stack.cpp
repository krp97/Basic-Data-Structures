#include "stdafx.h"
#include "Stack.h"


void Stack::pop()
{
	try { popFront(); }
	catch (EmptyArrException) { throw; }
}

int Stack::extract()
{
	int tempValue = arrPtr[0];

	try { pop(); }
	catch (EmptyArrException) { throw; }

	return 0;
}

void Stack::clear()
{
	for (int stack_it = 0; stack_it < size; ++stack_it)
	{
		try { popFront(); }
		catch (EmptyArrException) { throw; }
	}
}

std::string Stack::toString()
{
	return Array::toString();
}

Stack::Stack()
{
}


Stack::~Stack()
{
}
