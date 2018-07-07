#include "stdafx.h"
#include "R_BNode.h"


R_BNode::R_BNode(R_BNode * up, R_BNode * left, R_BNode * right, int value, char color)
{
	this->up = up;
	this->left = left;
	this->right = right;
	this->value = value;
	this->color = color;
}


R_BNode::~R_BNode()
{
}
