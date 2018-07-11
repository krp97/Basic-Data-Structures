#pragma once
#include <string>
#include "DataStructure.h"
class Array : public DataStructure
{
	friend class Heap;

	void pushAt(int value, int index);		// These methods shouldn't be available for the Heap.
	void popAt(int index);
	
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

	struct EmptyArrException : public std::exception {
		const char * description() const throw () {
			return "Empty array exception.";
		}
	};

	struct NotFoundException : public std::exception {
		const char * description() const throw () {
			return "Value not found.";
		}
	};

	int operator[](int index)
	{
		return *(this->arrPtr + index);
	};

	void pushFront(int value);			
	void pushBack(int value);			
		
	void popFront();					
	void popBack();						
	
	void swap(int first_index, int second_index);

	std::string toString();						
		
	int lookUpValue(int value);			

	void loadFromFile(std::string fileName);
	void saveToFile(std::string fileName);

	Array();
	explicit Array(int statArr [], int size);

	~Array();
};

