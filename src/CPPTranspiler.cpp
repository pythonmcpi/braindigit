#include "../h/CPPTranspiler.h"

CPPTranspiler::CPPTranspiler(const char program[], ofstream &outputFile)
	: m_program{ program }, m_outputFile{ outputFile }
{
	if (!(m_outputFile.is_open()))
	{
		std::cerr << "Fatal error: Transpiler could not initialise output stream\n";
		exit(-1);
	}

	m_outputFile << "#include <iostream>\n\nint main()\n{\nchar cells[30000];\nchar *ptr = cells;\n";
}

void CPPTranspiler::incrementPtr()
{
	m_outputFile << "++ptr;\n";
}

void CPPTranspiler::decrementPtr()
{
	m_outputFile << "--ptr;\n";
}

void CPPTranspiler::incrementByte()
{
	m_outputFile << "++*ptr;\n";
}

void CPPTranspiler::decrementByte()
{
	m_outputFile << "--*ptr;\n";
}

void CPPTranspiler::outputByte()
{
	m_outputFile << "std::cin.put(*ptr);\n";
}

void CPPTranspiler::inputByte()
{
	m_outputFile << "*ptr = std::cin.get();\n";
}

void CPPTranspiler::startLoop()
{
	m_outputFile << "while (*ptr)\n{\n";
}

void CPPTranspiler::endLoop()
{
	m_outputFile << "}\n";
}

void CPPTranspiler::evaluate()
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