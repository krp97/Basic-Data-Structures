#pragma once
#include "R_BNode.h"
#include <string>

class R_BTree
{
private:

	R_BNode* sentinel;
	R_BNode* root;
	int nodeCount;

public:

	R_BTree();

	void rotLeft(R_BNode* ptr);			// Rotacja w prawo
	void rotRight(R_BNode* ptr);		// Rotacja w lewo
	
	void pushValue(int value);			// Dodanie wartosci
	void removeRoot(R_BNode * ptr);		// Usuniecie wezla

	R_BNode* findMin(R_BNode* input);	// Wyszukanie min
	R_BNode* findMax(R_BNode* input);	// Wyszukanie max
	R_BNode* findSucc(R_BNode* input);

	void fixEntryCase1(R_BNode* ptr);	// fixEntryCase - 3 przypadki nie wymagajace naprawy struktury drzewa			
	void fixEntryCase2(R_BNode* ptr);
	void fixEntryCase3(R_BNode* ptr);

	void fixDeleteRBT(R_BNode* ptrToFix);	// korekcja drzewa po usunieciu wezla

	R_BNode * find(int value);				// Wyszukanie wartosci

	void display(std::string sp, std::string sn, R_BNode * p);	// Wyswietlenie

	R_BNode* getRoot();

	~R_BTree();
};

