#pragma once
#include <string>
#include "..\DataStructure.h"
class Array : public DataStructure
{
	friend class Heap;

	bool operator==(const Array& arr)
	{
		for (int arr_it = 0; arr_it < size; ++arr_it)
			if (arrPtr[arr_it] != *(arr.arrPtr + arr_it))
				return false;
		return true;
	}

protected:

	int* arrPtr;
	int maxSize;

public:

	int operator[](int index)
	{
		return *(this->arrPtr + index);
	};

	void pushFront(int value);			
	void pushBack(int value);			
	void pushAt(int value, int index);
	
	void popFront();					
	void popBack();						
	void popAt(int index);

	void swap(int first_index, int second_index);

	virtual std::string toString();						
		
	virtual void loadFromFile(std::string fileName);
	virtual void saveToFile(std::string fileName);

	Array();
	explicit Array(int statArr [], int size);

	~Array();
};

