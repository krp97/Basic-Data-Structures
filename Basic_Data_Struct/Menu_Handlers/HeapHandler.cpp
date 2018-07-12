#include "stdafx.h"
#include "HeapHandler.h"

HeapHandler::HeapHandler()
{
	this->myHeap = new Heap();
	initConsole();
}

void HeapHandler::initConsole()
{
	int arraySize = 6;
	std::string namesArr[6] = { "Insert", "Remove" , "Peek Root" , "Pop Root", "Display", "Return" };

	while (true)
	{
		system("CLS");
		drawMenu(namesArr, arraySize, "Heap");

		int choice = 0;
		std::cout << std::endl << " Your choice >> ";
		std::cin >> choice;

		switch (choice)
		{
		case 1:	// Insert
		{
			int value;
			std::cout << "\n Input value to push >> ";
			std::cin >> value;
			myHeap->insert(value);
			break;
		}
		case 2:	// Remove
		{
			int value;
			std::cout << "\n Input value to remove (First occurence will be removed) >> ";
			std::cin >> value;
			myHeap->remove(value);
			break;
		}
		case 3: // Peek Root
		{
			std::cout << "The root value >> " << myHeap->peekRoot();
			break;
		}
		case 4: // Pop Root
		{
			try { myHeap->popRoot(); }
			catch (...) { std::cout << "\n The heap is empty."; getchar(); }
			break;
		}
		case 5: // Display
		{
			std::cout << "\nYour Heap : \n" << myHeap->toString() << std::endl;
			break;
		}
		case 6: { return; }
		}
	}
}

HeapHandler::~HeapHandler()
{
	delete myHeap;
}
