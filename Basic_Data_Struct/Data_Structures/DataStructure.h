#pragma once
#include <string>

class DataStructure{

protected:
	int size;

public:

	virtual std::string toString() = 0;

	virtual ~DataStructure() {};
};