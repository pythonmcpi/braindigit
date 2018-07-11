#include "../h/Lexer.h"

Lexer::Lexer(std::ifstream &readStream, bool debugEnabled)
	: m_commandVector{}, m_readStream{ readStream }, m_vectorLength{ 0 }, m_currentIndex{ 0 }, m_debugEnabled{ debugEnabled }
{
	m_commandVector.resize(++m_vectorLength);
}

void Lexer::analyseFile()
{
	if (m_readStream.is_open())
	{
		std::string currentLine;

		while (std::getline(m_readStream, currentLine))
		{
			analyseLine(currentLine);
		}
	}
	else
	{
		SETCOL_LIGHT_RED
		std::cerr << " <- could not open file\n";
		RESET_COL
		exit(2);
	}
}

void Lexer::analyseLine(std::string &line)
{
	for (char &c : line)
	{
		switch (c)
		{
		case '>':
			m_commandVector[m_currentIndex++] = INCREMENT_PTR;
			m_commandVector.resize(++m_vectorLength);
			break;
		case '<':
			m_commandVector[m_currentIndex++] = DECREMENT_PTR;
			m_commandVector.resize(++m_vectorLength);
			break;
		case '+':
			m_commandVector[m_currentIndex++] = INCREMENT_BYTE;
			m_commandVector.resize(++m_vectorLength);
			break;
		case '-':
			m_commandVector[m_currentIndex++] = DECREMENT_BYTE;
			m_commandVector.resize(++m_vectorLength);
			break;
		case '.':
			m_commandVector[m_currentIndex++] = OUTPUT_BYTE;
			m_commandVector.resize(++m_vectorLength);
			break;
		case ',':
			m_commandVector[m_currentIndex++] = INPUT_BYTE;
			m_commandVector.resize(++m_vectorLength);
			break;
		case '[':
			m_commandVector[m_currentIndex++] = LOOP_START;
			m_commandVector.resize(++m_vectorLength);
			break;
		case ']':
			m_commandVector[m_currentIndex++] = LOOP_END;
			m_commandVector.resize(++m_vectorLength);
			break;
		default:
			if (m_debugEnabled)
				std::cout << "(i) Ignored unrecognized character '" << c << "\n";
		}
	}
}
		
std::vector<BrainfuckCommand>& Lexer::vector()
{
	return m_commandVector;
}


int Lexer::vectorLength()
{
	return m_vectorLength;
}