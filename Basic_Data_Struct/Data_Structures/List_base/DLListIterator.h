#pragma once
#include <iterator>
#include "NodeDL.h"
class DLListIterator
{
	friend class DoublyLinkedList;
	

	NodeDL * node;
public:

	using value_type = NodeDL;
	using difference_type = std::ptrdiff_t;
	using pointer = NodeDL * ;
	using reference = NodeDL & ;
	using iterator_category = std::bidirectional_iterator_tag;

	DLListIterator() = default;
	explicit DLListIterator(NodeDL * node) { this->node = node; };

	reference operator*() const { return *node; };

	DLListIterator& operator++() { node = node->next; return *this; };
	DLListIterator operator++(int dummy) { DLListIterator tmp = *this; ++tmp; return tmp; };

	DLListIterator& operator--() { node = node->prev; return *this; }
	DLListIterator operator--(int dummy) { DLListIterator tmp = *this; --tmp; return tmp; };

	bool operator==(const DLListIterator& listIt) { return (node == listIt.node); };
	bool operator!=(const DLListIterator& listIt) { return (node != listIt.node); };
};