#include "../h/Common.h"

#include "../h/Flags.h"
#include "../h/Functions.h"
#include "../h/ActionTree.h"

#include <stdlib.h>

int main(int argc, char *argv[])
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

	std::cout << "->" << outputName << ": Transpiled successfully";

	if (flags->compile())
	{
		std::string compileCommand{ "g++ " + outputName + " -o " + outputName.substr(0, outputName.find('.')) + "\n" };
		std::ofstream compileScript{ "compile.bat" };
		compileScript << compileCommand;
		std::cout << "(i) Run the command 'compile' to finish compilation.\n";
	}

	return 0;
}