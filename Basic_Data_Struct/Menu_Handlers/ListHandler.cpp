#include "stdafx.h"
#include "ListHandler.h"

ListHandler::ListHandler()
{
	this->myList = new List();
	initConsole();
}

void ListHandler::initConsole()
{
	int arraySize = 10;
	std::string namesArr[10] = { "Push Back", "Push Front" , "Push At" , "Pop Back", "Pop Front", "Pop At", 
		"Load From File","Save To File", "Forward Traversal", "Return" };

	while (true)
	{
		system("CLS");
		drawMenu(namesArr, arraySize, "List");

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
				if (std::cin >> value)
					myList->pushBack(value);
				else
					clearUserInput();
				break;
			}
			case 2:	// Push Front
			{
				int value;
				std::cout << "\n Input value to push >> ";
				if (std::cin >> value)
					myList->pushFront(value);
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
							myList->pushAt(value, index);
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
				try { myList->popBack(); }
				catch (...) { std::cout << "\n The array is empty.\n"; system("pause");
				}
				break;
			}
			case 5: // Pop Front
			{
				gotoXY(5, arraySize + 3);

				try { myList->popFront(); }
				catch (...) { std::cout << "\n The array is empty.\n"; system("pause");
				}
				break;
			}
			case 6:
			{
				int index;
				std::cout << "\n Input index to pop from >> ";
				if (std::cin >> index)
				{
					try { myList->popAt(index); }
					catch (...) { "\n Invalid input index.\n"; system("pause");
					}
				}
				else
					clearUserInput();
				break;
			}
			case 7:
			{
				handleLoadFromFile(myList);
				break;
			}
			case 8:
			{
				handleSaveToFile(myList);
				break;
			}
			case 9:
			{
				std::cout << "\n Your array >> \n " << myList->toString() << std::endl;
				system("pause");
				break;
			}
			case 10: {return; }
			}
		}
		else
			clearUserInput();
	}
}

ListHandler::~ListHandler()
{
	delete myList;
}
