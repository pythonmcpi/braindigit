#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <string>

#include "TextColour.h"

using std::string;
using std::cerr;

void error(string errorType, string errorMessage, int exitCode = -1);
void warning(string warningType, string warningMessage);
void success(string action, string message);

void showHelp();

void showVersion();

#endif