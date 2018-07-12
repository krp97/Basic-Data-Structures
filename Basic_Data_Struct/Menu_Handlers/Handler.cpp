#include "stdafx.h"
#include "Handler.h"
#include <windows.h>
#include <iostream>
#include "ArrayHandler.h"

void Handler::initConsole()
{
	int arraySize = 6;
	std::string test[6] = { "Array", "Heap", "Stack", "List", "Doubly Linked List", "Exit" };
	drawMenu(test, arraySize, "Structures");

	int initPosition = 1;
	gotoXY(6, 1);
	std::cout << ">>";

	bool runFlag = true;
	bool longPress = false;

	while (runFlag)
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
			case 1:
			{
				ArrayHandler();
				break;
			}
			case 2:
			{
				//heapMenu();
				break;
			}
			case 3:
			{
				//stackMenu();
				break;
			}
			case 4:
			{
				//listMenu();
				break;
			}
			case 5:
			{
				//dllistMenu();
				break;
			}
			}
		}
		Sleep(50);

		if (!GetAsyncKeyState(VK_UP) && !GetAsyncKeyState(VK_DOWN))
			longPress = false;
	}
	return;
}

void Handler::gotoXY(int x, int y)
{
	COORD cursorPosition;
	cursorPosition.X = x;
	cursorPosition.Y = y;
	SetConsoleCursorPosition(consoleLine, cursorPosition);
}

void Handler::drawMenu(std::string namesArr[], int size, std::string title)
{
	// -------------------- Values needed for padding -------------------
	int spacesInside;
	int longestName = 0;

	for (int it = 0; it < size; it++)
	{
		if (namesArr[it].length() > longestName)
			longestName = namesArr[it].length();
	}
	spacesInside = longestName + 8; // 2 vertical lines, "1)", 2 chars for "->", 1 empty space before and after the word

	int leftTitleSpace = floor(spacesInside / 2 - title.length() / 2);
	int rightTitleSpace = spacesInside - leftTitleSpace - title.length();

	// ----------------------- Printing ---------------------------------
	gotoXY(5, 0);
	std::cout << std::string(leftTitleSpace, '-') << title << std::string(rightTitleSpace, '-');

	// Each line has a form of : "|  1) title |".
	// All lines are adjusted towards the longest subtitles.

	for (int drawIt = 1; drawIt <= size; ++drawIt)
	{
		gotoXY(5, drawIt);
		int spaces = longestName - namesArr[drawIt - 1].length();
		std::cout << "|  " << drawIt << ") " << namesArr[drawIt - 1] << std::string(spaces, ' ') << " |\n";
	}

	gotoXY(5, size + 1);
	std::cout << std::string(spacesInside, '-') << std::endl;
}

Handler::Handler(HANDLE console)
{
	this->consoleLine = console;
	initConsole();
}


Handler::~Handler()
{
}
