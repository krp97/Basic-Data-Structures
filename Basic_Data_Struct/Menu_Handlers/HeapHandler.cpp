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
		if (std::cin >> choice)
		{
			switch (choice)
			{
			case 1:	// Insert
			{
				int value;
				std::cout << "\n Input value to push >> ";

				if (std::cin >> value)
					myHeap->insert(value);
				else
					clearUserInput();

				break;
			}
			case 2:	// Remove
			{
				int value;
				std::cout << "\n Input value to remove (First occurence will be removed) >> ";

				if (std::cin >> value)
				{
					try {
						myHeap->remove(value);
					}
					catch (std::invalid_argument) { std::cout << "Invalid operation.\n"; system("pause"); }
				}
				else
					clearUserInput();

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
				catch (std::out_of_range) { std::cout << "\n The heap is empty.\n"; system("pause"); }
				break;
			}
			case 5: // Display
			{
				std::cout << "\nYour Heap : \n" << myHeap->toString() << std::endl;
				system("pause");
				break;
			}
			case 6: { return; }
			}
		}
		else
			clearUserInput();
	}
}

HeapHandler::~HeapHandler()
{
	delete myHeap;
}
