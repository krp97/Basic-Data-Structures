#pragma once
class R_BNode
{
	friend class R_BTree;

private:

	R_BNode * up;		// ojciec
	R_BNode * left;		// lewy syn
	R_BNode * right;	// prawy syn
	int value;			// wartosc
	char color;			// kolor wezla

public:

	R_BNode(R_BNode * up, R_BNode * left, R_BNode * right, int value, char color);
	~R_BNode();
};

