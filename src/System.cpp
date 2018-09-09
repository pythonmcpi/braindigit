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

void showHelp()
{
	std::cout << "Braindigit: the universal Brainfuck compiler, transpiler and interpreter\nUsage: braindigit [input file] [options]\n\nOptions:\n  -c\n    Transpiles the inputted Brainfuck file to C\n  -c++\n    Transpiles the inputted Brainfuck file to C++\n  -cpp\n    Equivalent to -c++\n  -d\n    Enables verbose mode, displays debug info before running the program\n  -debug\n    Equivalent to -d\n  -h\n    Displays this help message\n  -help\n    Equivalent to -h\n  -o\n    Specify the name of the output file, e.g braindigit input.b -o name.b\n  -py\n    Transpiles the inputted Brainfuck file to Python\n  -python\n    Equivalent to -py\n  -rb\n    Transpiles the inputted Brainfuck file to Ruby\n  -ruby\n    Equivalent to -rb\n  -v\n    Displays the version number of Braindigit you have installed\n  -verbose\n    Equivalent to -d and -debug\n  -version\n    Equivalent to -v\n";
	exit(0);
}

void showVersion()
{
	std::cout << "Braindigit: the universal Brainfuck compiler, transpiler and interpreter\nVersion 0.1.0 (compiled with " << getCompilerVersion() << ")\n\nhttps://github.com/Dandigit/braindigit/\nCopyright (c) 2018 Daniel Boulton and contributors\n";
	exit(0);
}

string getCompilerVersion()
{
	#ifdef __CC_ARM
	return "ARM C++";
	#else
	#ifdef __clang__
	return "clang++";
	#else
	#ifdef __GNUC__
	return "g++";
	#else
	#ifdef __HP_aCC
	return "HP C++";
	#else
	#ifdef __IBMCPP__
	return "IBM Z/OS C++";
	#else
	#ifdef __INTEL_COMPILER
	return "intel";
	#else
	#ifdef _MSC_VER
	return "msvc++";
	#else
	#ifdef __OPEN64__
	return "open64";
	#else
	#ifdef __SUNPRO_C
	return "Solaris Studio";
	#else
	return "unknown compiler";
	#endif
	#endif
	#endif
	#endif
	#endif
	#endif
	#endif
	#endif
	#endif
}
	