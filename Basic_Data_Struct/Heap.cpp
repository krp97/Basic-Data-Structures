#include "stdafx.h"
/*#include "Heap.h"
#include <Math.h>
#include <iostream>


void Heap::pushValue(int value) 
{
	this->arrPtr->pushBack(value);		// dodanie elementu jako ostatni 
	this->nodeCount++;

	if (nodeCount > 1)
		fixUp(this->nodeCount - 1);			// naprawienie kopca w gore od ostatniego liscia
}

void Heap::popRoot()
 {
	*(this->arrPtr->arrPtr) = *(this->arrPtr->arrPtr + nodeCount-1);
	this->arrPtr->popBack();
	nodeCount--;
	if (nodeCount > 1)
		fixDown(0);							// naprawa kopca w dol od poczatku
}

void Heap::swap(int* parent, int* child)
{
	int tempValue = 0;
	tempValue = *parent;		// zachowanie wartosci rodzica w zmiennej pomocniczej
	*parent = *child;			// przypisanie wartosci dziecka, do wartosci rodzica
	*child = tempValue;			// przypisanie wartosci rodzica, do wartosci dziecka
}
int* Heap::heapCond(int index)	// sprawdzenie, czy spelniony jest warunek kopca dla zadanego wezla
{
	int *p = this->arrPtr->arrPtr + index;	
	int *pRightChild = getRightChild(index);
	int *pLeftChild = getLeftChild(index); 

	std::ptrdiff_t rightChildIndex = pRightChild - this->arrPtr->arrPtr;
	std::ptrdiff_t leftChildIndex = pLeftChild - this->arrPtr->arrPtr;

	if (*p >= *pRightChild && *p >= *pLeftChild)	// jesli wartosci obu synow sa mniejsze od rodzica
		return nullptr;

	if (rightChildIndex >= nodeCount && leftChildIndex >= nodeCount)	// jesli indeksy obu synow wykraczaja poza tablice
		return nullptr;

	if (leftChildIndex < nodeCount && rightChildIndex >= nodeCount)	// jesli indeks tylko lewego wykracza poza tablice
		return pLeftChild;

	return getBiggestChild(index);
}
void Heap::fixDown(int index)
{
	int *p = this->arrPtr->arrPtr + index;
	int *childToSwap = nullptr;		

	int levelCounter = index;							
	int heapLevels = floor(log2(nodeCount)) + 1;

	std::ptrdiff_t tempIndex = 0;
	
	while (levelCounter < heapLevels - 1)
	{
		childToSwap = heapCond(index);

		if (childToSwap != nullptr)
		{
			tempIndex = childToSwap - (this->arrPtr->arrPtr);	// index syna z ktorym zamieniana jest pozycja
			swap(p, childToSwap);	
			index = tempIndex;
			p = childToSwap;	// wskaznik na pozycje z ktora zamieniono wartosci
		} 
		levelCounter++;
	}
}
void Heap::fixUp(int index)
{
	int * p = this->arrPtr->arrPtr + index; // wskaznik pomocniczy na aktualny wezel/lisc

	while (*p > *(this->arrPtr->arrPtr + getParent(index)) && getParent(index) >= 0) // porownanie wartosci tego wezla z wartoscia rodzica
	{
		swap(this->arrPtr->arrPtr + getParent(index), p);	// zamiana miejscami
		index = getParent(index);								// ustawienie indexu na aktualna pozycje 
		p = this->arrPtr->arrPtr + index;					// przestawienie wskaznika pomocnicznego
	}
}

int Heap::getParent(int index) // zwroc indeks rodzica
{
	return floor((index-1)/2);
}

int* Heap::getRightChild(int index)	// zwroc wskaznik na prawego syna
{
	return this->arrPtr->arrPtr+2*index + 2;
}

int* Heap::getLeftChild(int index)	// zwroc wskaznik na lewego syna
{
	return this->arrPtr->arrPtr + 2*index + 1;
}

int* Heap::getBiggestChild(int index)	// zwroc wskaznik na syna o najwiekszej wartosci
{
	int* rightChild = this->getRightChild(index);
	int* leftChild = this->getLeftChild(index);
	int * returnChild = (*rightChild > *leftChild) ? rightChild : leftChild;
	
	return returnChild; // this shit alright?
}

int Heap::findValue(int value)
{
	for (int counter = 0; counter < nodeCount; counter++)
	{
		if (*(this->arrPtr->arrPtr + counter) == value)
			return counter;
	}
	return -1;
}

void Heap::display(std::string sp, std::string sn, int v)	
{
	//algorytm zaczerpniety z http://eduinf.waw.pl/inf/alg/001_search/0113.php

	std::string s;
	std::string cr, cl, cp;
	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;

	if (v < nodeCount)
	{
		s = sp;
		if (sn == cr) s[s.length() - 2] = ' ';
		display(s + cp, cr, 2 * v + 2);

		s = s.substr(0, sp.length() - 2);

		std::cout << s << sn << *(this->arrPtr->arrPtr + v) << std::endl;

		s = sp;
		if (sn == cl) s[s.length() - 2] = ' ';
		display(s + cp, cl, 2 * v + 1);
	}
}

Heap::Heap()
{
	this->nodeCount = 0;
	this->arrPtr = new arrPtr(nodeCount);
}

Heap::~Heap()
{
}
*/