#include "../h/System.h"

void error(string errorType, string errorMessage, int exitCode)
{
	TextColour::set(LIGHT_RED);
	cerr << "(!) " << errorType << ": ";
	TextColour::reset();
	cerr << errorMessage;

	exit(exitCode);
}

void warning(string warningType, string warningMessage)
{
	TextColour::set(LIGHT_YELLOW);
	cerr << "(i) " << warningType << ": ";
	TextColour::reset();
	cerr << warningMessage;
}

/*
void notify()
{

}

void conditionalNotify()
{

}
*/
	