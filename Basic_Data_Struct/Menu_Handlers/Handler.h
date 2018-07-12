#pragma once
#include <string>
#include <windows.h>
class Handler
{
protected:
	virtual void initConsole();
	HANDLE consoleLine;
public:

	void gotoXY(int x, int y);
	void drawMenu(std::string namesArr[], int size, std::string title);

	Handler(HANDLE console = 0);

	~Handler();
};

