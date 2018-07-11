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

#ifdef _WIN32

const HANDLE hConsole{ GetStdHandle(STD_OUTPUT_HANDLE) };
#define RESET_COL SetConsoleTextAttribute(hConsole, 7);
#define SETCOL_DARK_GRN SetConsoleTextAttribute(hConsole, 2);
#define SETCOL_DARK_BLU SetConsoleTextAttribute(hConsole, 3);
#define SETCOL_DARK_RED SetConsoleTextAttribute(hConsole, 4);
#define SETCOL_LIGHT_GRN SetConsoleTextAttribute(hConsole, 10);
#define SETCOL_LIGHT_BLU SetConsoleTextAttribute(hConsole, 11);
#define SETCOL_LIGHT_RED SetConsoleTextAttribute(hConsole, 12);

#elif __linux__

#define RESET_COL std::cout << "\033[39m";
#define SETCOL_DARK_GRN std::cout << "\033[32m";
#define SETCOL_DARK_BLU std::cout << "\033[34m";
#define SETCOL_DARK_RED std::cout << "\033[31m";
#define SETCOL_LIGHT_GRN std::cout << "\033[92m";
#define SETCOL_LIGHT_BLU std::cout << "\033[94m";
#define SETCOL_LIGHT_RED std::cout << "\033[91m";

#elif __unix__

#define RESET_COL std::cout << "\033[39m";
#define SETCOL_DARK_GRN std::cout << "\033[32m";
#define SETCOL_DARK_BLU std::cout << "\033[34m";
#define SETCOL_DARK_RED std::cout << "\033[31m";
#define SETCOL_LIGHT_GRN std::cout << "\033[92m";
#define SETCOL_LIGHT_BLU std::cout << "\033[94m";
#define SETCOL_LIGHT_RED std::cout << "\033[91m";

#endif