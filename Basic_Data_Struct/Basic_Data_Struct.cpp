// SDIZO - projekt 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <vld.h>

#include "Menu_Handlers\Handler.h"


using namespace std;

HANDLE consoleLine = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
	Handler mainMenu = Handler();
	mainMenu.initConsole();

	system("PAUSE");
	return 0;
}