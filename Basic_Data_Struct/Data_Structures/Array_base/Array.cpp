#include "stdafx.h"
#include "Array.h"
#include <string>
#include <exception>
#include <fstream>
#include <iostream>

Array::Array()
{
	this->size = 0;			// Current amount of values in the array
	this->arrPtr = nullptr;
	this->maxSize = 1;		// Current size of the array -
							// (how many elements can you add before memcpy is needed).
}

Array::Array(int statArr [], int size)
	: Array()
{
	for (int statArrIt = 0; statArrIt < size; ++statArrIt)
		this->pushBack(statArr[statArrIt]);
}

void Array::pushFront(int value)
{
	size++;

	if (arrPtr == nullptr)
		arrPtr = new int[size];
	if (size > maxSize)
	{
		// Double up the size of the array for future accesses.
		maxSize *= 2;
		int *tempArray = new int[maxSize];
		*tempArray = value;

		if(size > 1) // Otherwise there's no need to copy data.
			memcpy(tempArray + 1, arrPtr, (size - 1) * sizeof(int));
		
		if (arrPtr != nullptr)
			delete[] arrPtr;
		arrPtr = tempArray;
	}
	else
	{
		// Shift all elements 1 position further, and assign the "value" to first element.
		for (int arrIt = size - 1; arrIt - 1 >= 0; --arrIt)
			arrPtr[arrIt] = arrPtr[arrIt - 1];

		arrPtr[0] = value;
	}
}

void Array::pushBack(int value)
{
	size++;

	// Logic quite similar as above, with a small difference:
	// - Since the value is pushed at the back, there's no element shifting.
	if (arrPtr == nullptr)
		arrPtr = new int[size];
	if (size > maxSize)
	{
		maxSize *= 2;
		int *temparrPtr = new int[maxSize];
		
		if(size > 1)
			memcpy(temparrPtr, arrPtr, (size - 1) * sizeof(int));
		
		if (arrPtr != nullptr)
			delete[] arrPtr;
		arrPtr = temparrPtr;

		arrPtr[size - 1] = value;
	}
	else
		arrPtr[size - 1] = value;
}

void Array::pushAt(int value, int index)
{
	if (arrPtr == nullptr && index != 0)
		throw std::out_of_range("Empty array error.");
	if (index <= size && index >= 0)					
	{
		if (index == 0)			// Reusing existing methods for boundary cases.
			pushFront(value);
		else if (index == size)
			pushBack(value);
		else
		{
			size++;

			if (size > maxSize)
			{
				// Copy the old array elements in two parts, 
				// in order to leave the element at "index" for assignment.

				maxSize *= 2;
				int *temparrPtr = new int[maxSize];

				*(temparrPtr + index) = value;
				memcpy(temparrPtr, arrPtr, index * sizeof(int));
				memcpy(temparrPtr + index + 1, &arrPtr[index], (size - index) * sizeof(int));

				delete[] arrPtr;
				arrPtr = temparrPtr;
			}
			else
			{
				// Shifting elements, past index, 1 position further. 
				for (int arrIt = size; arrIt > index; --arrIt)
					arrPtr[arrIt] = arrPtr[arrIt - 1];

				arrPtr[index] = value;
			}
		}
	}
}

void Array::popFront()
{
	if (size > 0)
	{
		size--;

		if (size < maxSize / 2 && size > 0)	// Note that the size changed.
		{									// If size == 0 at this point, delete the element and return.
											// Shrink the array two times if there's enough free space.
			maxSize /= 2;
			int *temparrPtr = new int[maxSize];
			memcpy(temparrPtr, &arrPtr[1], size * sizeof(int));

			delete[] arrPtr;
			arrPtr = temparrPtr;
		}
		else if (size > 0)					// Same as above, without shrinking.
		{
			for (int arrIt = 0; arrIt < size - 1; ++arrIt)
				arrPtr[arrIt] = arrPtr[arrIt + 1];
		}
		else	// Size of the array is now 0, so discard any data inside.
		{
			delete[] arrPtr;
			arrPtr = nullptr;
			maxSize = 1;
		}
	}
	else
		throw std::out_of_range("Empty array error.");
}

void Array::popBack()
{
	if (size > 0)
	{
		size--;

		// In the case when there isn't enough space for reallocation 
		// only the size changes, so the element is not taken into consideration further on.
		if (size < maxSize / 2 && size > 0)
		{
			maxSize /= 2;
			int *temparrPtr = new int[maxSize];

			memcpy(temparrPtr, arrPtr, size * sizeof(int));

			delete[] arrPtr;
			arrPtr = temparrPtr;
		}
		else if (size == 0)
		{
			delete[] arrPtr;
			arrPtr = nullptr;
			maxSize = 1;
		}
	}
	else
		throw std::out_of_range("Empty array error.");
}

void Array::popAt(int index)
{
	if (arrPtr == nullptr)
		throw std::out_of_range("Empty array error.");
	if (index == 0)					// Reusing existing methods for boundary cases.
		popFront();
	else if (index == size - 1)
		popBack();
	else if (index < size && index > 0)
	{
		size--;
		if (size <= maxSize / 2)
		{
			// Important bit: second memcpy contains (size - index + 1) to compensate for size shrinking.
			// Without it the last element of the arrPtr is left out.

			maxSize /= 2;
			int *temparrPtr = new int[maxSize];
			memcpy(temparrPtr, arrPtr, index * sizeof(int));
			memcpy(temparrPtr + index + 1, arrPtr, (size - index + 1) * sizeof(int));

			delete[] arrPtr;
			arrPtr = temparrPtr;
		}
		else
		{
			for (int arrIt = index; arrIt < size; ++arrIt)
				arrPtr[arrIt] = arrPtr[arrIt + 1];
		}
	}
}

void Array::swap(int first_index, int second_index)
{
	if (first_index <= size && first_index >= 0 && second_index <= size && second_index >= 0)
	{
		int tmp_value = arrPtr[first_index];
		arrPtr[first_index] = arrPtr[second_index];
		arrPtr[second_index] = tmp_value;
	}
	else
		throw std::invalid_argument("Wrong input index.");
}

std::string Array::toString()
{
	std::string output = "|"; // First character

	if (size > 0)
		for (int arrIt = 0; arrIt < size; ++arrIt)
			output += std::to_string(arrPtr[arrIt]) + '|';
	else
		return std::string();

	return output;
}

void Array::loadFromFile(std::string fileName)
{
	std::ifstream fileToRead;
	std::string line;
	int value = 0;
	
	// All exceptions are rethrown for the caller to handle, or call apropriate handlers.
	// In case of any error the input data is unusable, so there is no point in continuing.

	try {

		fileToRead.open(fileName);

		while (fileToRead.good())
		{
			fileToRead >> line;
			try
			{
				value = stoi(line);
			}
			catch (std::invalid_argument& e)
			{
				fileToRead.close();
				throw;
			}
			this->pushBack(value);
		}
	}
	catch (std::ios_base::failure &fail)
	{
		throw;
	}

	fileToRead.close();
}

void Array::saveToFile(std::string fileName)
{
	std::ofstream fileToWrite;
	try
	{
		fileToWrite.open(fileName);

		for (int arrIt = 0; arrIt < this->size; ++arrIt)
			fileToWrite << arrPtr[arrIt] << std::endl;
	}
	catch (std::ios_base::failure &fail)
	{
		throw;
	}
	fileToWrite.close();
}

Array::~Array()
{
	if(this->arrPtr != nullptr)
		delete [] this->arrPtr;
}
