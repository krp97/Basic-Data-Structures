#pragma once
#include "..\Data_Structures\Array_base\Heap.h"
#include "..\Menu_Handlers\Handler.h"

class HeapHandler : private Handler {
	
	Heap * myHeap;

public:
	HeapHandler();
	void initConsole();
	~HeapHandler();
};
