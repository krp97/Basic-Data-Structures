#include "stdafx.h"
#include "R_BTree.h"
#include <iostream>


R_BTree::R_BTree()
{
	this->sentinel = new R_BNode(sentinel, sentinel, sentinel, 0, 'B ');
	this->root = sentinel;
	this->nodeCount = 0;
}

void R_BTree::rotLeft(R_BNode* relativePtr)
{
	// Oznaczenia do komentarzy:
	// X - wezel wedlug ktorego nastepuje rotacja (synowie - XL i XR)
	// Y - prawy syn wezla X (synowie - YL i YR)
	// P - rodzic X (synowie PL i PR)									

	R_BNode * rightSon = relativePtr->right;
	R_BNode* parent = relativePtr->up;

	if (rightSon != sentinel) 
	{
		relativePtr->right = rightSon->left;		// przypisanie YL do XR

		if (relativePtr->right != sentinel)			// jesli nowy XR istnieje to:
			relativePtr->right->up = relativePtr;	// przypisanie do rodzica XR, wezla X

		rightSon->left = relativePtr;				// przypisanie X do YL
		rightSon->up = parent;						// przypisanie ojca X do ojca Y
		relativePtr->up = rightSon;					// przypisanie do ojca X, wezla Y

		if (parent != sentinel && parent != nullptr)						// jesli rodzic istnieje, to:
		{
			if (parent->left == relativePtr)		// przypisanie Y do PL lub PR w miejsce gdzie znajdowal sie X przed rotacja
				parent->left = rightSon;			 
			else
				parent->right = rightSon;
		}
		else 
			root = rightSon;
	}
}

void R_BTree::rotRight(R_BNode* relativePtr)
{
	R_BNode * leftSon = relativePtr;
	R_BNode *parent = relativePtr->up;

	// Oznaczenia do komentarzy:
	// X - wezel wedlug ktorego nastepuje rotacja (synowie - XL i XR)
	// Y - lewy syn wezla X (synowie - YL i YR)
	// P - rodzic X (synowie PL i PR)									

	leftSon= relativePtr->left;
	if (leftSon != sentinel)
	{
		relativePtr->left = leftSon->right;			// przypisanie YR do XL

		if (relativePtr->left != sentinel)			// jesli nowy XL istnieje to:
			relativePtr->left->up = relativePtr;	// przypisanie do rodzica XL, wezla X

		leftSon->right = relativePtr;				// przypisanie X do YR
		leftSon->up = parent;						// przypisanie ojca X do ojca Y
		relativePtr->up = leftSon;					// przypisanie do ojca X, wezla Y

		if (parent != sentinel && parent != nullptr)						// jesli rodzic istnieje, to:
		{
			if (parent->left == relativePtr)		// przypisanie Y do PL lub PR w miejsce gdzie znajdowal sie X przed rotacja
				parent->left = leftSon;
			else 
				parent->right = leftSon;
		}
		else 
			root = leftSon;
	}
}

void R_BTree::pushValue(int value)
{
	if (nodeCount == 0)		// pierwszy wezel
	{
		root = new R_BNode(nullptr, sentinel, sentinel, value, 'B');
		nodeCount++;
	}
	else
	{
		R_BNode* ptr = root;
		R_BNode* tempPtr = ptr;

		while (ptr != sentinel)		// uzyskanie adresu odpowiedniego ostatniego elementu
		{
			tempPtr = ptr;			// wskaznik pomocniczy (wskazuje na przedostatni element iteratora)

			ptr = ptr->right;
			if (tempPtr->value > value)	// zejscie w dol drzewa zgodnie z zasadami drzewa bst
				ptr = tempPtr->left;
		}
		ptr = tempPtr; // przypisanie ostatniej uzyskanej wartosci w petli

		if (ptr == root)
		{			
			nodeCount++;

			if (ptr->value > value)	// warunek poprawnosci drzewa bst			
			{
				ptr->left = new R_BNode(ptr, sentinel, sentinel, value, 'R');
			}
			else
			{
				ptr->right = new R_BNode(ptr, sentinel, sentinel, value, 'R');
			}
			return;
		}

		R_BNode* ptrToFix;		// wskaznik na dodany element wedlug ktorego nastapi korekcja	
		R_BNode* parent;		// ojciec ptrToFix
		R_BNode* gparent;		// dziadek ptrToFix
		R_BNode* uncle;			// wujek ptrToFix

		nodeCount++;

		if (ptr->value > value)			// dodanie nowego elementu zgodnie z warunkami drzewa BST
		{
			ptr->left = new R_BNode(ptr, sentinel, sentinel, value, 'R');
			ptrToFix = ptr->left;
		}
		else
		{
			ptr->right = new R_BNode(ptr, sentinel, sentinel, value, 'R');
			ptrToFix = ptr->right;
		}

		while (ptrToFix != root && ptrToFix->up->color == 'R')
		{
			parent = ptrToFix->up;
			gparent = parent->up;

			// rozdzielenie petli na dwa lustrzane przypadki:

			if (ptrToFix->up == ptrToFix->up->up->left)	// jesli ojciec nowego elementu jest lewym synem dziadka	
			{
				uncle = gparent->right;		

				if (uncle->color == 'R')					//	przypadek 1 - jesli wujek jest koloru czerwonego
				{
					parent->color = 'B';					// zamiana kolorow: wujka i dziadka oraz ustawienie koloru ojca na czarny
					uncle->color = 'B';
					gparent->color = 'R';
					ptrToFix = gparent;						// nowym wezlem do naprawy jest teraz dziadek, dopoki nie bedzie on korzeniem
				}
				else
				{
					if (ptrToFix == parent->right)			// przypadek 2 - element do naprawy jest lewym synem 
					{
						rotLeft(parent);
						ptrToFix = parent;					// aktualizacja wskaznikow po rotacji
						parent = ptrToFix->up;
					}

					rotRight(gparent);
					char tempColor = parent->color;
					parent->color = gparent->color;			// przypadek 3 - zamiana kolorow ojca i dziadka po rotacji							
					gparent->color = tempColor;
					ptrToFix = parent;
				}
			}
			else										// lustrzany przypadek - jesli ojciec nowego elementu jest prawym synem dziadka
			{
				uncle = gparent->left;
				
				if (uncle->color == 'R')				//	przypadek 1 - jesli wujek jest koloru czerwonego
				{
					parent->color = 'B';				// zamiana kolorow: wujka i dziadka oraz ustawienie koloru ojca na czarny
					uncle->color = 'B';
					gparent->color = 'R';
					ptrToFix = gparent;					// nowym wezlem do naprawy jest teraz dziadek, dopoki nie bedzie on korzeniem
				}
				else
				{
					if (ptrToFix == parent->left)		// przypadek 2 - element do naprawy jest lewym synem 
					{
						rotRight(ptrToFix);
						ptrToFix = parent;				// aktualizacja wskaznikow po rotacji
						parent = ptrToFix->up;		
					}

					rotLeft(gparent);
					char tempColor = parent->color;
					parent->color = gparent->color;		// przypadek 3 - zamiana kolorow ojca i dziadka po rotacji							
					gparent->color = tempColor;
				}
			}
		}
		root->color = 'B'; // wynika z warunku drzewa czerwono-czarnego
	}
}

void R_BTree::removeRoot(R_BNode * ptr)
{
	ptr = root->left->right->right;
	R_BNode* ptrToFix = ptr;

	if (ptr == nullptr)
		return;

	//********************** Przypadki bez korekty**********************//
	if (ptr->right == sentinel && ptr->left == sentinel)	// 1 - brak synow
	{
		fixEntryCase1(ptr);
		return;
	}
	if (ptr->left == sentinel)	// 2 - wezel usuwany ma tylko prawego syna
	{
		fixEntryCase2(ptr);
		return;
	}
	if (ptr->right == sentinel)	// 3 - wezel usuwany ma tylko lewego syna
	{
		fixEntryCase3(ptr);
		return;
	}
	//******************************************************************//

	if ((ptr->right != sentinel) && (ptr->left != sentinel))
	{
		if (findSucc(ptr) == ptr->right)	// jego prawy syn jest nastepnikiem
		{
			//************************ Wymagana korekta ****************//
			R_BNode* succ = findSucc(ptr);	// znalezienie nastepnika
			char tempColor = succ->color;

			if (ptr->up->right == ptr)		// przypisanie wskaznika od gory na nowy wezel
				ptr->up->right = succ;
			else
				ptr->up->left = succ;

			succ->up = ptr->up;				// przepisanie wartosci z ptr do nastepnika
			succ->left = ptr->left;
			succ->color = ptr->color;

			if (tempColor = 'B' && succ->right != sentinel)		// jesli nastepnik byl czarny i ma prawego syna to wymagana bedzie korekta
			{

				if (succ->right->color == 'B')
					succ->right->color = 'D';	// D - oznacza kolor podwojnie czarny (Double black)
				else
					succ->right->color = 'M';	// M - oznacza kolor czerwono czarny (Mixed)

				ptrToFix = succ->right;	// wskaznik, ktory posiada nadmiar koloru czarnego (D lub M)
			}
			//**********************************************************//
			else
			{
				delete ptr;
				return;
			}	
		}
		else	// przypadek lustrzany do powyzszego( prawy syn wezla nie jest jego nastepnikiem)	
		{
			R_BNode* succ = findSucc(ptr);
			R_BNode* tempSuc = succ;				// dodatkowy wskaznik na nastepnika
			char tempColorSuc = tempSuc->color;		// zachowanie koloru nastepnika 

			if (tempColorSuc == 'B' && tempSuc->right!=sentinel)
			{
				//****************************** Wymagana korekta *******************************//
				tempSuc->right->up = tempSuc->up;	// przypisanie prawemu synowi nowego ojca 

				if (tempSuc->up->right == tempSuc)	// przypisanie ojcu nowego syna
					tempSuc->up->right = tempSuc->right;
				else
					tempSuc->up->left = tempSuc->right;

				if (tempSuc->right->color == 'B')	// wstawienie dodatkowego koloru czarnego
				{
					tempSuc->right->color = 'D';	// D - podwojny czarny
					ptrToFix = tempSuc->right;
				}
				else if (tempSuc->right->color == 'R')
				{
					tempSuc->right->color = 'M';	// M - czerwono czarny
					ptrToFix = tempSuc->right;
				}

				succ->up = ptr->up;					// przesuniecie nastepnika na pozycje usuwanego elementu
				succ->right = ptr->right;
				succ->left = ptr->left;
				succ->color = ptr->color;

				if (ptr->up->right == ptr)		// ustawienie wskaznika na nowego syna, ojca wezla usuwanego
					ptr->up->right = succ;
				else
					ptr->up->left = succ;
				//*****************************************************************************************//
			}
			else
			{
				if (succ->up->right == succ)		// ustawienie wskazanie ojca na straznika, poniewaz nastepnik jest przesuwany
					succ->up->right = sentinel;
				else
					succ->up->left = sentinel;

				succ->up = ptr->up;					// ustawienie nastepnika na pozycje wezla usuwanego
				succ->right = ptr->right;
				succ->left = ptr->left;
				succ->color = ptr->color;

				if (ptr->up->right == ptr)			// ustawienie wskazania na nowego syna
					ptr->up->right = succ;
				else
					ptr->up->left = succ;

				delete ptr;
				return;
			}
		}
	}
	
	fixDeleteRBT(ptrToFix);
	
	delete ptr;
}

R_BNode * R_BTree::findMin(R_BNode* input)
{
	R_BNode *ptr = input;
	R_BNode	*tempPtr = ptr;	// poprzednie wskazanie ptr

	while (ptr != sentinel)	// uzyskanie wezla w drzewie, ktory jest skrajnie lewy 
	{
		tempPtr = ptr;
		ptr = ptr->left;
	}

	return tempPtr;
}

R_BNode * R_BTree::findMax(R_BNode* input)
{
	R_BNode *ptr = input;
	R_BNode	*tempPtr = ptr;	// poprzednie wskazanie ptr

	while (ptr != sentinel) // uzyskanie wezla w drzewie, ktory jest skrajnie prawy
	{
		tempPtr = ptr;
		ptr = ptr->right;
	}

	return tempPtr;
}

R_BNode * R_BTree::findSucc(R_BNode* ptr)
{
	R_BNode * successor;

	if (ptr != sentinel)
	{
		if (ptr->right != sentinel)				// jesli prawy syn wezla nie jest straznikiem, to nastepnikiem jest skrajnie lewy wezel w tym poddrzewie
			return findMin(ptr->right);
		else									// w przeciwnym wypadku nalezy isc w gore drzewa do momentu pierwszego skretu w lewo(?)
		{
			successor = ptr->up;
			while ((successor != sentinel) && (ptr == successor->right))
			{
				ptr = successor;
				successor = successor->up;
			}
			return successor;
		}
	}
	return sentinel;
}

void R_BTree::fixEntryCase1(R_BNode * ptr)
{
	R_BNode* parent = ptr->up;
	if (parent->right == ptr)
		parent->right = sentinel;
	else
		parent->left = sentinel;
	delete ptr;
	return;
}

void R_BTree::fixEntryCase2(R_BNode * ptr)	// przypadek 2 - usuwany wezel ma tylko prawego syna
{
	R_BNode* parent = ptr->up;	// ojciec usuwanego wezla
	ptr->right->up = parent;	// zmieniamy adres ojca nowego wezla
	parent->left = ptr->right;	// zmieniamy adres prawego syna ojca

	if (parent->color == 'R' && parent->left->color == 'R')
		parent->left->color = 'B';
	delete ptr; // usuniecie wezla
	return;
}

void R_BTree::fixEntryCase3(R_BNode * ptr) // przypadek 3 - usuwany wezel ma tylko lewego syna
{
	R_BNode* parent = ptr->up;	// ojciec usuwanego wezla
	ptr->left->up = parent;		// zmieniamy adres ojca nowego wezla
	parent->left = ptr->left;	// zmieniamy adres lewego syna ojca

	if (ptr->color == 'B')
		ptr->left->color = 'B';

	delete ptr;	// usuniecie wezla
	return;
}

void R_BTree::fixDeleteRBT(R_BNode* ptrToFix)
{
	R_BNode* brother;
	R_BNode* parent;

	while ((ptrToFix->color == 'D' || ptrToFix->color == 'M') && ptrToFix != root)
	{
		parent = ptrToFix->up;

		if (ptrToFix->up->right == ptrToFix)
		{
			brother = ptrToFix->left;

			if (brother->color == 'R')			// Przypadek 1 - brat ma kolor czerwony
			{
				parent->color = 'R';			// Zamiana kolorow - brata i ojca
				brother->color = 'B';
				rotRight(ptrToFix->up);			// Rotacja w prawy wokol ojca
				R_BNode* tempParent = parent;
				parent = brother;				// Aktualizacja wskaznikow po rotacji
				brother = tempParent->left;
			}
			if (brother->right->color == 'B' && brother->left->color == 'B')	// Przypadek 2 - synowie brata maja kolor czarny
			{
				brother->color = 'R';			// Zamiana koloru brata na czerwony oraz wyciagniecie dodatkowego czarnego koloru

				if (ptrToFix->color == 'M')		// M - kolor czerwono-czarny (Mixed) 
					ptrToFix->color = 'R';		
				else
					ptrToFix->color = 'B';

				ptrToFix = parent;
				if (ptrToFix->up->color == 'B')
					ptrToFix->up->color = 'D';	// D - kolor podwojny czarny (Double Black)
				else
					ptrToFix->up->color = 'M';
				continue;
			}
			if (brother->left->color == 'R' && brother->right->color == 'B')	// Przypadek 3 - lewy syn brata ma kolor czerwony
			{
				rotLeft(brother);				// Rotacja w lewo
				brother->color = 'R';			// Zamiana kolorow brata i lewego syna
				brother->left->color = 'B';
				brother = parent->left;			// Aktualizacja wskaznikow
			}

			brother->color = parent->color;		// Przypadek 4
			parent->color = 'B';				// Przypisanie czarnego koloru do brata i jego lewego syna
			brother->left->color = 'B';

			if (ptrToFix->color == 'D')		// Wyciagniecie dodatkowego zbednego czarnego koloru
				ptrToFix->color = 'B';
			else
				ptrToFix->color = 'R';

			rotRight(parent);				// rotacja w prawo i wyjscie z petli
			ptrToFix = root;
		}
		else			// Przypadek lustrzany do powyzszego 
		{
			brother = ptrToFix->right;

			if (brother->color == 'R')			// Przypadek 1
			{
				parent->color = 'R';
				brother->color = 'B';
				rotLeft(ptrToFix->up);
				R_BNode* tempParent = parent;
				parent = brother;
				brother = tempParent->right;
			}
			if (brother->color == 'B' && brother->right->color == 'B' && brother->left->color == 'B')	// Przypadek 2
			{
				brother->color = 'R';

				if (ptrToFix->color == 'M')
					ptrToFix->color = 'R';
				else
					ptrToFix->color = 'B';

				ptrToFix = parent;
				if (ptrToFix->up->color == 'B')
					ptrToFix->up->color = 'D';
				else
					ptrToFix->up->color = 'M';
				continue;
			}
			if (brother->color == 'B' && brother->left->color == 'R' && brother->right->color == 'B')	// Przypadek 3
			{
				rotRight(brother);
				brother->color = 'R';
				brother->left->color = 'B';
				brother = parent->right;
			}

			brother->color = parent->color;		// Przypadek 4
			parent->color = 'B';
			brother->right->color = 'B';

			if (ptrToFix->color == 'D')
				ptrToFix->color = 'B';
			else
				ptrToFix->color = 'R';

			rotLeft(parent);
			ptrToFix = root;
		}
	}
}

R_BNode* R_BTree::getRoot()
{
	return this->root;
}

R_BNode * R_BTree::find(int value)
{
	R_BNode * p;

	p = root;
	while ((p != sentinel) && (p->value != value))
		if (value < p->value) 
			p = p->left;
		else          
			p = p->right;
		if (p == sentinel) 
			return NULL;
	return p;
}

void R_BTree::display(std::string sp, std::string sn, R_BNode * p)
{
	//algorytm zaczerpniety z http://eduinf.waw.pl/inf/alg/001_search/0113.php

	std::string t;
	std::string cr, cl, cp;
	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;

	if (p != sentinel)
	{
		t = sp;
		if (sn == cr) t[t.length() - 2] = ' ';
		display(t + cp, cr, p->right);

		t = t.substr(0, sp.length() - 2);
		std::cout << t << sn << p->color << ":" << p->value << std::endl;

		t = sp;
		if (sn == cl) t[t.length() - 2] = ' ';
		display(t + cp, cl, p->left);
	}
}

R_BTree::~R_BTree()
{
}
