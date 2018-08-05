#include "../h/CTranspiler.h"

CTranspiler::CTranspiler(const char program[], ofstream &outputFile)
	: m_program{ program }, m_outputFile{ outputFile }
{
	if (!(m_outputFile.is_open()))
	{
		std::cerr << "Fatal error: Transpiler could not initialise output stream\n";
		exit(-1);
	}

	m_outputFile << "#include <stdio.h>\n\nint main()\n{\nchar cells[30000];\nchar *ptr = cells;\n";
}

void CTranspiler::incrementPtr()
{
	m_outputFile << "++ptr;\n";
}

void CTranspiler::decrementPtr()
{
	m_outputFile << "--ptr;\n";
}

void CTranspiler::incrementByte()
{
	m_outputFile << "++*ptr;\n";
}

void CTranspiler::decrementByte()
{
	m_outputFile << "--*ptr;\n";
}

void CTranspiler::outputByte()
{
	m_outputFile << "putchar(*ptr);\n";
}

void CTranspiler::inputByte()
{
	m_outputFile << "*ptr = getchar();\n";
}

void CTranspiler::startLoop()
{
	m_outputFile << "while (*ptr)\n{\n";
}

void CTranspiler::endLoop()
{
	m_outputFile << "}\n";
}

void CTranspiler::evaluate()
{
	while (*m_program)
	{
		switch (*m_program)
		{
		case '>':
			incrementPtr();
			break;
		case '<':
			decrementPtr();
			break;
		case '+':
			incrementByte();
			break;
		case '-':
			decrementByte();
			break;
		case '.':
			outputByte();
			break;
		case ',':
			inputByte();
		case '[':
			startLoop();
			break;
		case ']':
			endLoop();
			break;
		}

		++m_program;
	}
}

