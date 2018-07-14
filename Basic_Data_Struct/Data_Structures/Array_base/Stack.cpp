#include "stdafx.h"
#include "Stack.h"
#include <fstream>

void Stack::pop()
{
	try { popFront(); }
	catch (std::out_of_range) { throw; }
}

int Stack::extract()
{
	int tempValue = arrPtr[0];

	try { pop(); }
	catch (std::out_of_range) { throw; }

	return 0;
}

void Stack::clear()
{
	for (int stack_it = 0; stack_it < size; ++stack_it)
	{
		try { popFront(); }
		catch (std::out_of_range) { throw; }
	}
}

std::string Stack::toString()
{
	std::string output;
	if (size > 0)
	{
		for (int stackIt = 0; stackIt < size; ++stackIt)
			output += "|" + std::to_string(arrPtr[stackIt]) + "|\n";
	}
	else
		return std::string();
	return output;
}

void Stack::loadFromFile(std::string fileName)
{
	std::ifstream fileToRead;
	std::string line;
	int value = 0;

	try {

		fileToRead.open(fileName);

		while (fileToRead.good())
		{
			fileToRead >> line;
			try
			{
				value = stoi(line);
			}
			catch (std::invalid_argument& e)
			{
				fileToRead.close();
				throw;
			}
			this->pushFront(value);
		}
	}
	catch (std::ios_base::failure &fail) { throw; }

	fileToRead.close();
}

Stack::Stack()
{
}


Stack::~Stack()
{
}
