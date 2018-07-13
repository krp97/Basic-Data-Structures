#pragma once
#include "..\Data_Structures\List_base\DoublyLinkedList.h"
#include "Handler.h"
class DLListHandler : private Handler {

	DoublyLinkedList * myDLList;
public:
	DLListHandler();

	void initConsole();

	~DLListHandler();
};
