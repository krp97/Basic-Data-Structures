#pragma once
#include <string>
class DataStructure{

protected:
	int size;

public:

	virtual std::string toString() = 0;
	virtual void loadFromFile(std::string fileName) = 0;
	virtual void saveToFile(std::string fileName) = 0;

	virtual ~DataStructure() {};
};