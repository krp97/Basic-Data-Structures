#include "stdafx.h"
#include "StackHandler.h"
#include <iostream>

StackHandler::StackHandler()
{
	this->myStack = new Stack();
	initConsole();
}

StackHandler::~StackHandler()
{
	delete myStack;
}

void StackHandler::initConsole()
{
	int arraySize = 6;
	std::string namesArr[6] = { "Push", "Pop" , "Peek" , "Clear all", "Display", "Return" };

	while (true)
	{
		system("CLS");
		drawMenu(namesArr, arraySize, "Stack");

		int choice = 0;
		std::cout << std::endl << " Your choice >> ";
		std::cin >> choice;

		switch (choice)
		{
		case 1:	// Push 
		{
			int value;
			std::cout << "\n Input value to push >> ";
			std::cin >> value;
			myStack->push(value);
			break;
		}
		case 2:	// Pop
		{
			try { myStack->pop(); }
			catch (...) { std::cout << "\n Stack underflow error."; }
			break;
		}
		case 3: // Peek
		{
			std::cout << "\n Stack top >> " << myStack->peek();
			break;
		}
		case 4: // Clear all
		{
			try { myStack->clear(); }
			catch (...) { std::cout << "\n Stack underglow error."; }
			break;
		}
		case 5: // Display
		{
			myStack->toString();
		}
		case 6: { return; }
		}
	}
}
