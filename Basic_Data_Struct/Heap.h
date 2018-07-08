/*#pragma once
#include "Array.h"
#include "NodeDL.h"
#include <iostream>
#include <string>
class Heap
{
private:

	Array * heapArray;
	int nodeCount;

public:

	void pushValue(int value);				// Dodanie wartosci
	void popRoot();							// Usuniecie korzenia

	void fixUp(int index);					// Naprawa w gore
	void fixDown(int index);				// Naprawa w dol

	void swap(int* index1, int* index2);	// Zamiana miejscami w tablicy

	int* heapCond(int index);				// Sprawdzenie warunku kopca

	int getParent(int index);				// Zwrocenie ojca
	int* getRightChild(int index);			// Zwrocenie prawego syna
	int* getLeftChild(int index);			// Zwrocenie lewego syna
	int* getBiggestChild(int index);		// Zwrocenie syna o najwiekszej wartosci
	
	int findValue(int value);				// Wyszukiwanie wartosci

	void display(std::string sp, std::string sn, int value);	// Wyswietlanie

	Heap();
	~Heap();
};
*/
