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
	int arraySize = 8;
	std::string namesArr[8] = { "Push", "Pop" , "Peek" , "Clear all", "Display","Load From File","Save To File", "Return" };

	while (true)
	{
		system("CLS");
		drawMenu(namesArr, arraySize, "Stack");

		int choice = 0;
		std::cout << std::endl << " Your choice >> ";
		
		if (std::cin >> choice)
		{

			switch (choice)
			{
			case 1:	// Push 
			{
				int value;
				std::cout << "\n Input value to push >> ";
				if (std::cin >> value)
					myStack->push(value);
				else
					clearUserInput();
				break;
			}
			case 2:	// Pop
			{
				try { myStack->pop(); }
				catch (std::out_of_range) { std::cout << "\n Stack underflow error."; }
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
				catch (std::out_of_range) { std::cout << "\n Stack underflow error."; }
				break;
			}
			case 5: // Display
			{
				std::cout << "Your Stack >> \n";
				std::cout << myStack->toString();
				system("pause");
				break;
			}
			case 6:
			{
				handleLoadFromFile(myStack);
				break;
			}
			case 7:
			{
				handleSaveToFile(myStack);
				break;
			}
			case 8: { return; }
			}
		}
		else
			clearUserInput();
	}
}
