#include "../h/Common.h"
#include "../h/Lexer.h"
#include "../h/BrainfuckCommand.h"

class ActionTree
{
	Lexer &m_lexer;
	std::ofstream &m_outputStream;

	bool m_pauseEnabled;
	bool m_debugEnabled;

public:

	ActionTree(Lexer &lexer, std::ofstream &outputStream, bool pauseEnabled = false, bool debugEnabled = false);
	void writeActions();
};