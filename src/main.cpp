#include "../h/Common.h"

#include "../h/Flags.h"
#include "../h/Interpreter.h"
#include "../h/CPPTranspiler.h"
#include "../h/CTranspiler.h"

using std::cout;
using std::cin;
using std::cerr;
using std::getline;
using std::ofstream;
using std::ifstream;
using std::vector;
using std::string;

string readFileToString(ifstream &file)
{
	string currentLine;
	string allLines;

	while (getline(file, currentLine))
	{
		allLines += currentLine;
	}

	return allLines;
}

int main(int argc, char *argv[])
{
	Flags flags{ argc, argv };

	ifstream inputFile{ flags.inputFilename() };

	if (!(inputFile.is_open()))
	{
		cerr << "Could not open input file: " << flags.inputFilename();
		exit(-1);
	}

	string fileContents{ readFileToString(inputFile) };

	if (flags.cppTranspile())
	{
		ofstream outputFile{ flags.outputFilename() };

		CPPTranspiler cppTranspiler{ fileContents.c_str(), outputFile };
		cppTranspiler.evaluateProgram();

	}
	else if (flags.cTranspile())
	{
		ofstream outputFile{ flags.outputFilename() };

		CTranspiler cTranspiler{ fileContents.c_str(), outputFile };
		cTranspiler.evaluateProgram();
	}
	else
	{
		Interpreter interpreter{ fileContents.c_str() };
		interpreter.evaluateProgram();
	}

	return 0;
}