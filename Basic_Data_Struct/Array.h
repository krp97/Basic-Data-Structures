#pragma once
#include <string>
#include "DataStructure.h"
class Array : public DataStructure
{
	friend class Heap;
private:
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
		if (index > 0 || index < this->size)
			return *(this->arrPtr + index);
		else
			throw std::invalid_argument("Invalid index.");
	};

	void pushFront(int value);			
	void pushBack(int value);			
	void pushAt(int value, int index);	

	void popFront();					
	void popBack();						
	void popAt(int index);				

	std::string toString();						
		
	int lookUpValue(int value);			

	void loadFromFile(std::string fileName);
	void saveToFile(std::string fileName);

	Array();
	Array(int statArr [], int size);

	~Array();
};

