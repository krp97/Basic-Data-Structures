#pragma once
#include <string>
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

	Handler();

	virtual ~Handler();
};

