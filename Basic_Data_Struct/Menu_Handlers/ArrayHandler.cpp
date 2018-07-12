#include "stdafx.h"
#include "ArrayHandler.h"
#include <iostream>

void ArrayHandler::initConsole()
{
	int arraySize = 9;
	std::string namesArr[9] = { "Push Back", "Push Front" , "Push At" , "Pop Back", "Pop Front", "Pop At", "Find value", "Display", "Return" };
	
	while (true)
	{
		system("CLS");
		drawMenu(namesArr, arraySize, "Array");

		int choice = 0;
		std::cout << std::endl << " Your choice >> ";
		std::cin >> choice;

		switch (choice)
		{
		case 1:	// Push Back
		{
			int value;
			std::cout << "\n Input value to push >> ";
			std::cin >> value;
			myArray->pushBack(value);
			break;
		}
		case 2:	// Push Front
		{
			int value;
			std::cout << "\n Input value to push >> ";
			std::cin >> value;
			myArray->pushFront(value);
			break;
		}
		case 3: // Push At
		{
			int value, index;
			std::cout << "\n Input value to push >> ";
			std::cin >> value;
			std::cout << "\n Input index to push at >>";
			std::cin >> index;

			try
			{
				myArray->pushAt(value, index);
			}
			catch (...)
			{
				gotoXY(5, arraySize + 5);
				std::cout << "\n Invalid input index.";
				getchar();
			}
			break;
		}
		case 4: // Pop Back
		{
			try { myArray->popBack(); }
			catch (...) { std::cout << "\n The array is empty."; getchar(); }
			break;
		}
		case 5: // Pop Front
		{
			gotoXY(5, arraySize + 3);

			try { myArray->popFront(); }
			catch (...) { std::cout << "\n The array is empty."; getchar(); }
			break;
		}
		case 6:
		{
			int index;
			std::cout << "\n Input index to pop from >> ";
			std::cin >> index;

			try { myArray->popAt(index); }
			catch (...) { "\n Invalid input index."; getchar(); }

			break;
		}
		case 8:
		{
			std::cout << "\n Your array >> \n " << myArray->toString() << std::endl;
			system("pause");
			break;
		}
		case 9: {return; }
		}
	}
}

ArrayHandler::ArrayHandler()
{
	this->myArray = new Array();
	initConsole();
}

ArrayHandler::~ArrayHandler()
{
	delete myArray;
}
