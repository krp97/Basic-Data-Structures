#include "stdafx.h"
#include "ArrayHandler.h"
#include <iostream>

void ArrayHandler::initConsole()
{
	system("CLS");
	int arraySize = 8;
	std::string namesArr[8] = { "Push Back", "Push Front" , "Push At" , "Pop Back", "Pop Front", "Pop At", "Find value", "Display" };
	drawMenu(namesArr, arraySize, "Array");

	int initPosition = 1;
	gotoXY(6, 1);
	std::cout << ">>";

	bool runFlag = true;
	bool longPress = false;

	while (runFlag)
	{
		if (!longPress)
		{
			if (GetAsyncKeyState(VK_DOWN))
			{
				if (!longPress && initPosition < arraySize)
				{
					gotoXY(6, initPosition);
					std::cout << "  ";
					initPosition++;
					gotoXY(6, initPosition);
					std::cout << ">>";
					longPress = true;
				}
			}
			if (GetAsyncKeyState(VK_UP))
			{
				if (!longPress && initPosition > 1)
				{
					gotoXY(6, initPosition);
					std::cout << "  ";
					initPosition--;
					gotoXY(6, initPosition);
					std::cout << ">>";
					longPress = true;
				}
			}
			if (GetAsyncKeyState(VK_RETURN))
			{
				switch (initPosition)
				{
				case 1:	// Push Back
				{
					int value;
					gotoXY(5, arraySize + 3);
					std::cout << "Input value to push >> ";
					std::cin >> value;
					myArray->pushBack(value);
					break;
				}
				case 2:	// Push Front
				{
					int value;
					gotoXY(5, arraySize + 3);
					std::cout << "Input value to push >> ";
					std::cin >> value;
					myArray->pushFront(value);
					break;
				}
				case 3: // Push At
				{
					int value, index;
					gotoXY(5, arraySize + 3);
					std::cout << "Input value to push >> ";
					std::cin >> value;
					gotoXY(5, arraySize + 4);
					std::cout << "Input index to push at >>";
					std::cin >> index;

					try
					{
						myArray->pushAt(value, index);
					}
					catch (...)
					{
						gotoXY(5, arraySize + 5);
						std::cout << "Invalid input index.";
						getchar();
					}

					break;
				}
				case 4: // Pop Back
				{
					gotoXY(5, arraySize + 3);

					try { myArray->popBack(); }
					catch (...) { std::cout << "The array is empty."; getchar(); }
					break;
				}
				case 5: // Pop Front
				{
					gotoXY(5, arraySize + 3);

					try { myArray->popFront(); }
					catch (...) { std::cout << "The array is empty."; getchar(); }
					break;
				}
				case 6:
				{
					int index;
					gotoXY(5, arraySize + 3);
					std::cout << "Input index to pop from >> ";
					std::cin >> index;
					gotoXY(5, arraySize + 4);

					try { myArray->popAt(index); }
					catch (...) { "Invalid input index."; getchar(); }

					break;
				}
				case 7: {return; }
				}
			}
		}
		Sleep(50);

		if (!GetAsyncKeyState(VK_UP) && !GetAsyncKeyState(VK_DOWN) && !GetAsyncKeyState(VK_RETURN))
			longPress = false;
	}
}

ArrayHandler::ArrayHandler() : Handler(consoleLine)
{
	this->myArray = new Array();
}


ArrayHandler::~ArrayHandler()
{
}
