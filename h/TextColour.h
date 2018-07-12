#ifndef COMMON_H
#define COMMON_H
#include "Common.h"
#endif

#ifdef _WIN32

#ifndef WINDOWS_H
#define WINDOWS_H
#include <windows.h>
#endif

#ifndef WINBASE_H
#define WINBASE_H
#include <WinBase.h>
#endif

#endif

enum Colour
{
	DARK_GREEN,
	DARK_BLUE,
	DARK_RED,
	LIGHT_GREEN,
	LIGHT_BLUE,
	LIGHT_RED,
	LIGHT_YELLOW,
};

#ifdef _WIN32

namespace TextColour
{
	const HANDLE hConsole{ GetStdHandle(STD_OUTPUT_HANDLE) };

	inline void reset() { SetConsoleTextAttribute(hConsole, 7); }

	inline void set(Colour colour)
	{
		switch (colour)
		{
		case DARK_GREEN:
			SetConsoleTextAttribute(hConsole, 2);
			break;
		case DARK_BLUE:
			SetConsoleTextAttribute(hConsole, 3);
			break;
		case DARK_RED:
			SetConsoleTextAttribute(hConsole, 4);
			break;
		case LIGHT_GREEN:
			SetConsoleTextAttribute(hConsole, 10);
			break;
		case LIGHT_BLUE:
			SetConsoleTextAttribute(hConsole, 11);
			break;
		case LIGHT_RED:
			SetConsoleTextAttribute(hConsole, 12);
			break;
		case LIGHT_YELLOW:
			SetConsoleTextAttribute(hConsole, 14);
			break;
		default:
			SetConsoleTextAttribute(hConsole, 7);
		}
	}
}

#else

namespace TextColour
{
	const HANDLE hConsole{ GetStdHandle(STD_OUTPUT_HANDLE) };

	inline void reset() { std::cout << "\033[39m"; }

	inline void set(Colour colour)
	{
		switch (colour)
		{
		case DARK_GREEN:
			std::cout << "\033[32m";
			break;
		case DARK_BLUE:
			std::cout << "\033[34m";
			break;
		case DARK_RED:
			std::cout << "\033[31m";
			break;
		case LIGHT_GREEN:
			std::cout << "\033[92m";
			break;
		case LIGHT_BLUE:
			std::cout << "\033[94m";
			break;
		case LIGHT_RED:
			std::cout << "\033[91m";
			break;
		case LIGHT_YELLOW:
			std::cout << "\033[93m";
		default:
			std::cout << "\033[39m";
		}
	}
}

#endif