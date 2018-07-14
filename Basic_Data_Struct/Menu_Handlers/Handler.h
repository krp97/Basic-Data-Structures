#pragma once
#include <string>
#include "../Data_Structures/DataStructure.h"
#include <windows.h>
class Handler
{
protected:
	
	HANDLE consoleLine;
public:

	virtual void initConsole();
	void gotoXY(int x, int y);
	void drawMenu(std::string namesArr[], int size, std::string title);
	void clearUserInput();

	// These two methods look exactly the same for each handler.
	void handleSaveToFile(DataStructure* dataStruct);
	void handleLoadFromFile(DataStructure* dataStruct);
	
	Handler();

	virtual ~Handler();
};

