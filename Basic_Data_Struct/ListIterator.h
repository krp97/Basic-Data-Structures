#pragma once
#pragma once
#include <iostream>
#include <iterator>

#include "List.h"
#include "Node.h"

class ListIterator
{
	friend class List;
private:
	Node* node;

public:
	using value_type = Node;
	using difference_type = std::ptrdiff_t;
	using pointer = Node * ;
	using reference = Node & ;
	using iterator_category = std::forward_iterator_tag;

	ListIterator() = default;
	explicit ListIterator(Node* node) {this->node = node;};

	reference operator*() const { return *node; };

	// pre/post incrementation
	ListIterator& operator++() { node = node->next; return *this; };
	ListIterator operator++(int dummy) { ListIterator tmp = *this; ++tmp; return tmp; };

	// Equality/ inequality
	bool operator==(const ListIterator& listIt) { return (node == listIt.node); };
	bool operator!=(const ListIterator& listIt) { return (node != listIt.node); };


};