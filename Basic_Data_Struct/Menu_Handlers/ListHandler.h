#pragma once
#include "..\Data_Structures\List_base\List.h"
#include "Handler.h"

class ListHandler : private Handler {

	List * myList;
public:
	ListHandler();
	void initConsole();
	~ListHandler();
};