#pragma once
class DArray
{
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

	void display();						
	
	int lookUpIndex(int index);			
	int lookUpValue(int value);			

	DArray(int size);
	~DArray();
};

