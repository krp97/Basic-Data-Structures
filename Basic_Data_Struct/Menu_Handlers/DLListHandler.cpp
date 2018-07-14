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
	int arraySize = 12;
	std::string namesArr[12] = { "Push Back", "Push Front" , "Push At" , "Pop Back", "Pop Front", "Pop At", 
		"Load From File","Save To File", "Forward Traversal", "Backward Traversal", "Display", "Return" };

	while (true)
	{
		system("CLS");
		drawMenu(namesArr, arraySize, "Doubly Linked List");

		int choice = 0;
		std::cout << std::endl << " Your choice >> ";
		if (std::cin >> choice)
		{

			switch (choice)
			{
			case 1:	// Push Back
			{
				int value;
				std::cout << "\n Input value to push >> ";
				if(std::cin >> value)
					myDLList->pushBack(value);
				else 
					clearUserInput(); 

				break;
			}
			case 2:	// Push Front
			{
				int value;
				std::cout << "\n Input value to push >> ";
				if (std::cin >> value)
					myDLList->pushFront(value);
				else
					clearUserInput();
				break;
			}
			case 3: // Push At
			{
				int value, index;
				std::cout << "\n Input value to push >> ";
				if (std::cin >> value)
				{
					std::cout << "\n Input index to push at >>";
					if (std::cin >> index)
					{
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
					}
					else
						clearUserInput();
				}
				else
					clearUserInput();
				break;
			}
			case 4: // Pop Back
			{
				try { myDLList->popBack(); }
				catch (std::out_of_range) { std::cout << "\n The list is empty.\n"; system("pause");
				}
				break;
			}
			case 5: // Pop Front
			{
				gotoXY(5, arraySize + 3);

				try { myDLList->popFront(); }
				catch (std::out_of_range) { std::cout << "\n The list is empty.\n"; system("pause");
				}
				break;
			}
			case 6:	// Pop At
			{
				int index;
				std::cout << "\n Input index to pop from >> ";
				if (std::cin >> index)
				{
					try { myDLList->popAt(index); }
					catch (std::out_of_range) { std::cout << "\n Invalid input index.\n"; system("pause"); }
				}
				else
					clearUserInput();

				break;
			}
			case 7:
			{
				handleLoadFromFile(myDLList);
				break;
			}
			case 8:
			{
				handleSaveToFile(myDLList);
				break;
			}
			case 9: // Forward traversal
			{
				std::cout << "\n Forward traversal output >>\n";
				std::cout << myDLList->forwardTravers() << std::endl;
				system("pause");
				break;
			}
			case 10: // Backward traversal
			{
				std::cout << "\n Backward traversal output >>\n";
				std::cout << myDLList->backwardTravers() << std::endl;
				system("pause");
				break;
			}
			case 11: // Display
			{
				std::cout << "\nYour list >> \n " << myDLList->toString() << std::endl;
				system("pause");
				break;
			}
			case 12: { return; }
			}
		}
		else
			clearUserInput();
	}
}

DLListHandler::~DLListHandler()
{
}
