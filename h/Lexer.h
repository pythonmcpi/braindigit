#include "../h/Common.h"
#include "../h/BrainfuckCommand.h"

class Lexer
{
	std::vector<BrainfuckCommand> m_commandVector;
	std::ifstream &m_readStream;
	int m_vectorLength;
	int m_currentIndex;

	bool m_debugEnabled;

public:

	Lexer(std::ifstream &readStream, bool debugEnabled = false);

	void analyseFile();

	void analyseLine(std::string &line);

	std::vector<BrainfuckCommand>& vector();
	int vectorLength();
};