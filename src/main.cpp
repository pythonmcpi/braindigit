#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "../h/Flags.h"
#include "../h/Interpreter.h"
#include "../h/CPPTranspiler.h"
#include "../h/CTranspiler.h"
#include "../h/PythonTranspiler.h"
#include "../h/RubyTranspiler.h"

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

	if (!(inputFile.is_open())) error("Fatal error", "Could not open input file: " + flags.inputFilename());

	string fileContents{ readFileToString(inputFile) };

	if (flags.cppTranspile())
	{
		ofstream outputFile{ flags.outputFilename() };

		CPPTranspiler cppTranspiler{ fileContents.c_str(), outputFile };
		cppTranspiler.evaluateProgram();

		success(flags.inputFilename() + " -> " + flags.outputFilename(), "Transpiled successfuly");

	}
	else if (flags.cTranspile())
	{
		ofstream outputFile{ flags.outputFilename() };

		CTranspiler cTranspiler{ fileContents.c_str(), outputFile };
		cTranspiler.evaluateProgram();

		success(flags.inputFilename() + " -> " + flags.outputFilename(), "Transpiled successfuly");
	}
	else if (flags.pythonTranspile())
	{
		ofstream outputFile{ flags.outputFilename() };

		PythonTranspiler pythonTranspiler{ fileContents.c_str(), outputFile };
		pythonTranspiler.evaluateProgram();

		success(flags.inputFilename() + " -> " + flags.outputFilename(), "Transpiled successfuly");
	}
	else if (flags.rubyTranspile())
	{
		ofstream outputFile{ flags.outputFilename() };

		RubyTranspiler rubyTranspiler{ fileContents.c_str(), outputFile };
		rubyTranspiler.evaluateProgram();

		success(flags.inputFilename() + " -> " + flags.outputFilename(), "Transpiled successfuly");
	}
	else
	{
		Interpreter interpreter{ fileContents.c_str() };
		interpreter.evaluateProgram();
	}

	return 0;
}