#include "stdafx.h"
#include "ArrayHandler.h"
#include <iostream>

#undef max	// For clearing std::cin of wrong user input.

void ArrayHandler::initConsole()
{
	int arraySize = 10;
	std::string namesArr[10] = { "Push Back", "Push Front" , "Push At" , "Pop Back", "Pop Front", "Pop At", 
		"Display", "Load From File","Save To File", "Return" };
	
	while (true)
	{
		system("CLS");
		drawMenu(namesArr, arraySize, "Array");

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
					myArray->pushBack(value);
				else
					clearUserInput();
				break;
			}
			case 2:	// Push Front
			{
				int value;
				std::cout << "\n Input value to push >> ";
				
				if (std::cin >> value)
					myArray->pushFront(value);
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
							myArray->pushAt(value, index);
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
				try { myArray->popBack(); }
				catch (std::out_of_range & fail) 
				{ std::cout << fail.what() << "\n"; system("pause"); }

				break;
			}
			case 5: // Pop Front
			{
				gotoXY(5, arraySize + 3);

				try { myArray->popFront(); }
				catch (std::out_of_range & fail) 
				{ std::cout << fail.what() << "\n"; system("pause"); }

				break;
			}
			case 6: // Pop At
			{
				int index;
				std::cout << "\n Input index to pop from >> ";
				if (std::cin >> index)
				{
					try { myArray->popAt(index); }
					catch (std::out_of_range & fail) 
					{ std::cout << fail.what() << "\n"; system("pause");}
				}
				else
					clearUserInput();
				break;
			}
			case 7:
			{
				std::cout << "\n Your array >> \n " << myArray->toString() << std::endl;
				system("pause");
				break;
			}
			case 8:
			{
				handleLoadFromFile(myArray);
				break;
			}
			case 9:
			{
				handleSaveToFile(myArray);
				break;
			}
			case 10: {return; }
			}
		}
		else{ clearUserInput();}
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
