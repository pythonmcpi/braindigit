#include "../h/Common.h"

#include "../h/Flags.h"
#include "../h/Functions.h"
#include "../h/ActionTree.h"

int main(int argc, char* argv[])
{
	Flags *flags = new Flags{ argc, argv };
	flags->handle();

	std::ifstream inputFile{ flags->fileName() };
	std::cout << flags->fileName();

	Lexer *lexer = new Lexer{ inputFile };

	lexer->analyseFile();

	std::string outputName{ (flags->fileName().substr(0, flags->fileName().find('.')) + ".cpp") };

	std::ofstream outputFile{ outputName };
	writeBoilerplateCode(outputFile);

	ActionTree *actionTree = new ActionTree{ *lexer, outputFile, flags->pause() };
	actionTree->writeActions();

	std::cout << " -> " << outputName << ": ";

	TextColour::set(DARK_GREEN);
	std::cout << "Transpiled successfully";
	TextColour::reset();

	std::cout << "\n";

	if (flags->compile())
	{
		#ifndef _WIN32 // If not on Windows, just compile normally.
		std::string compileCommand{ "g++ " + outputName + " -o " + outputName.substr(0, outputName.find('.')) };
		system(compileCommand.c_str());

		#else // Otherwise, issue an error and instructions on how to compile properly
		std::string compileCommand{ "@echo off\ncall \"\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\VC\\Auxiliary\\Build\\vcvars64.bat\ncl /EHsc " + outputName };
		
		std::ofstream compileScript{ "compile.bat" };
		
		compileScript << compileCommand;

		TextColour::set(LIGHT_RED);
		std::cerr << "\n(i) PLEASE READ\n";
		TextColour::reset();

		std::cerr << "It looks like you're on Windows. Unfortunately, the Windows environment causes issues when "
			<< "compiling C++ files from within Braindigit.\n";

		TextColour::set(LIGHT_YELLOW);
		std::cerr << "\n(i) WORKAROUND\n";
		TextColour::reset();

		std::cerr << "To work around this issue you can simply ";

		TextColour::set(LIGHT_YELLOW);
		std::cerr << "run the command 'compile' ";
		TextColour::reset();

		std::cerr << "after you run Braindigit to finish compiling your Brainfuck program.\n";
		#endif
	}

	return 0;
}