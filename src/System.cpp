#include "../h/System.h"

void error(string errorType, string errorMessage, int exitCode)
{
	TextColour::set(LIGHT_RED);
	cerr << "(!) " << errorType << ": ";
	TextColour::reset();
	cerr << errorMessage << "\n";

	exit(exitCode);
}

void warning(string warningType, string warningMessage)
{
	TextColour::set(LIGHT_YELLOW);
	cerr << "(i) " << warningType << ": ";
	TextColour::reset();
	cerr << warningMessage << "\n";
}

void success(string action, string message)
{
	cerr << action << ": ";
	TextColour::set(LIGHT_GREEN);
	cerr << message << "\n";
	TextColour::reset();
}

/*
void notify()
{

}

void conditionalNotify()
{

}
*/
	