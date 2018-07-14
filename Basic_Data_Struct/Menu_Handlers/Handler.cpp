#include "stdafx.h"
#include "Handler.h"
#include <windows.h>
#include <iostream>

#include "ArrayHandler.h"
#include "StackHandler.h"
#include "HeapHandler.h"
#include "ListHandler.h"
#include "DLListHandler.h"

#undef max // Clearing std::cin of wrong user input.

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
			ListHandler();
			break;
		}
		case 5:
		{
			DLListHandler();
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
	if (size / 10 == 1)
		longestName++;
	for (int drawIt = 1; drawIt <= size; ++drawIt)
	{
		int spaces = longestName - namesArr[drawIt - 1].length() - drawIt/10;
		std::cout << "|  " << drawIt << ") " << namesArr[drawIt - 1] << std::string(spaces, ' ') << " |\n";
	}
	std::cout << std::string(spacesInside, '-') << std::endl;
}

void Handler::clearUserInput()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "\n Invalid input.\n";
	system("pause");
}

void Handler::handleSaveToFile(DataStructure * dataStruct)
{
	std::string fileName;
	std::cout << "Please input your file's name >> ";
	std::cin >> fileName;

	try { dataStruct->saveToFile(fileName); }
	catch (std::ios_base::failure) {
		std::cout << "Please check your file's location and name.\n";
		system("pause");
	}
}

void Handler::handleLoadFromFile(DataStructure * dataStruct)
{
	std::string fileName;
	std::cout << "Please input your file's name >> ";
	std::cin >> fileName;

	try { dataStruct->loadFromFile(fileName); }
	catch (std::invalid_argument) {
		std::cout << "Please check your file's contents.\n";
		system("pause");
	}
	catch (std::ios_base::failure) {
		std::cout << "Please check your file's location and name.\n";
		system("pause");
	}
}

Handler::Handler()
{
}

Handler::~Handler()
{
}
