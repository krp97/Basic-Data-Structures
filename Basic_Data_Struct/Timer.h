#pragma once
// Class wrapper for the Query Perfomance Counter.
// More here : https://msdn.microsoft.com/en-us/library/windows/desktop/ms644904(v=vs.85).aspx

#include <windows.h>
class Timer
{
	LARGE_INTEGER start, end, PCFreq;

public:

	Timer();

	LARGE_INTEGER startTimer();
	LARGE_INTEGER endTimer();

	~Timer();
};

