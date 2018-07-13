#include "stdafx.h"
#include "DLListHandler.h"
#include <iostream>
DLListHandler::DLListHandler()
{
	this->myDLList = new DoublyLinkedList();
	initConsole();
}

void DLListHandler::initConsole()
{
	int arraySize = 11;
	std::string namesArr[11] = { "Push Back", "Push Front" , "Push At" , "Pop Back", "Pop Front", "Pop At", "Find value",
		"Forward Traversal", "Backward Traversal", "Display", "Return" };

	while (true)
	{
		system("CLS");
		drawMenu(namesArr, arraySize, "Doubly Linked List");

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
			myDLList->pushBack(value);
			break;
		}
		case 2:	// Push Front
		{
			int value;
			std::cout << "\n Input value to push >> ";
			std::cin >> value;
			myDLList->pushFront(value);
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
				myDLList->pushAt(value, index);
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
			try { myDLList->popBack(); }
			catch (...) { std::cout << "\n The array is empty."; getchar(); }
			break;
		}
		case 5: // Pop Front
		{
			gotoXY(5, arraySize + 3);

			try { myDLList->popFront(); }
			catch (...) { std::cout << "\n The array is empty."; getchar(); }
			break;
		}
		case 6:	// Pop At
		{
			int index;
			std::cout << "\n Input index to pop from >> ";
			std::cin >> index;

			try { myDLList->popAt(index); }
			catch (...) { "\n Invalid input index."; getchar(); }

			break;
		}
		case 8: // Forward traversal
		{
			std::cout << "\n Your array >> \n " << myDLList->toString() << std::endl;
			system("pause");
			break;
		}
		case 9: // Backward traversal
		{

		}
		case 10: // Display
		{

		}
		case 11: // Exit
		{
			return;
		}
		}
	}
}

DLListHandler::~DLListHandler()
{
}
