#pragma once
#include <string>
class DArray
{
	friend class Heap;
private:
	int* dArray;
	int size;
public:

	void pushFront(int value);			
	void pushBack(int value);			
	void pushAt(int value, int index);	

	void popFront();					
	void popBack();						
	void popAt(int index);				

	std::string toString();						
	
	int lookUpIndex(int index);			
	int lookUpValue(int value);			

	void loadFromFile(std::string fileName);
	void saveToFile(std::string fileName);

	DArray(int size);
	~DArray();
};

