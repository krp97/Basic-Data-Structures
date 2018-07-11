#include "stdafx.h"
#include "Timer.h"


Timer::Timer()
{
}

LARGE_INTEGER Timer::startTimer()
{
	QueryPerformanceFrequency(&PCFreq);
	LARGE_INTEGER start;
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&start);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
	return start;
}

LARGE_INTEGER Timer::endTimer()
{
	LARGE_INTEGER stop;
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&stop);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
	return stop;
}

Timer::~Timer()
{
	QueryPerformanceFrequency(&PCFreq);
}
