#include "../h/ActionTree.h"

ActionTree::ActionTree(Lexer &lexer, std::ofstream &outputStream, bool pauseEnabled, bool debugEnabled)
	: m_lexer{ lexer }, m_outputStream{ outputStream }, m_pauseEnabled{ pauseEnabled }, m_debugEnabled{ debugEnabled }
{
	if (!(m_outputStream.is_open()))
	{
		std::cerr << "(!) INTERNAL ERROR: ActionTree output stream coulde not initialize\n";
		exit(2);
	}

	if (m_debugEnabled)
		std::cout << "(i) ActionTree output stream initialized successfully\n";
}

void ActionTree::writeActions()
{
	if (!(m_outputStream.is_open()))
	{
		std::cerr << "(!) INTERNAL ERROR: Failed to open ActionTree output stream\n";
		exit(2);
	}

	for (const BrainfuckCommand &c : m_lexer.vector())
	{
		switch (c)
		{
		case INCREMENT_PTR:
			m_outputStream << "++ptr;\n";
			break;
		case DECREMENT_PTR:
			m_outputStream << "--ptr;\n";
			break;
		case INCREMENT_BYTE:
			m_outputStream << "++*ptr;\n";
			break;
		case DECREMENT_BYTE:
			m_outputStream << "--*ptr;\n";
			break;
		case OUTPUT_BYTE:
			m_outputStream << "putchar(*ptr);\n";
			break;
		case INPUT_BYTE:
			m_outputStream << "*ptr = getchar();\n";
			break;
		case LOOP_START:
			m_outputStream << "while (*ptr) {\n";
			break;
		case LOOP_END:
			m_outputStream << "}\n";
			break;
		}
	}

	if (m_pauseEnabled)
	{
		m_outputStream << "std::cin.ignore();\nstd::cin.get();\n";
		if (m_debugEnabled)
			std::cout << "(i) Console pausing written\n";
	}

	m_outputStream << "}\n";
}