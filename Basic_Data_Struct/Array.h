#pragma once
#include <string>
#include "DataStructure.h"
class Array : public DataStructure
{
	friend class Heap;

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
	void pushAt(int value, int index);	

	void popFront();					
	void popBack();						
	void popAt(int index);

	void swap(int first_index, int second_index);

	std::string toString();						
		
	int lookUpValue(int value);			

	void loadFromFile(std::string fileName);
	void saveToFile(std::string fileName);

	Array();
	Array(int statArr [], int size);

	~Array();
};

