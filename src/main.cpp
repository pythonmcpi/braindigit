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

	SETCOL_LIGHT_GRN
	std::cout << "Transpiled successfully";
	RESET_COL

	std::cout << "\n";

	if (flags->compile())
	{
		std::string compileCommand{ "g++ " + outputName + " -Wl,--subsystem,native -o " + outputName.substr(0, outputName.find('.')) + "\n" };
		system(compileCommand.c_str());
	}

	return 0;
}