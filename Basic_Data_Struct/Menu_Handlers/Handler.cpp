#include "stdafx.h"
#include "Handler.h"
#include <windows.h>
#include <iostream>

#include "ArrayHandler.h"
#include "StackHandler.h"
#include "HeapHandler.h"

void Handler::initConsole()
{
	int arraySize = 6;
	std::string test[6] = { "Array", "Heap", "Stack", "List", "Doubly Linked List", "Exit" };
	
	while (true)
	{
		system("CLS");
		drawMenu(test, arraySize, "Structures");
		std::cout << std::endl;
		
		std::cout << "Your choice >> ";
		int choice;
		std::cin >> choice;

		switch (choice)
		{
		case 1:
		{
			ArrayHandler();
			break;
		}
		case 2:
		{
			HeapHandler();
			break;
		}
		case 3:
		{
			StackHandler();
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
		case 6:
		{
			return;
		}
		}
	}
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
	std::cout << std::string(leftTitleSpace, '-') << title << std::string(rightTitleSpace, '-');
	std::cout << std::endl;
	// Each line has a form of : "|  1) title |".
	// All lines are adjusted towards the longest subtitles.

	for (int drawIt = 1; drawIt <= size; ++drawIt)
	{
		int spaces = longestName - namesArr[drawIt - 1].length();
		std::cout << "|  " << drawIt << ") " << namesArr[drawIt - 1] << std::string(spaces, ' ') << " |\n";
	}
	std::cout << std::string(spacesInside, '-') << std::endl;
}

Handler::Handler()
{

}


Handler::~Handler()
{
}
