#include "../h/CPPTranspiler.h"

CPPTranspiler::CPPTranspiler(const char program[], ofstream &outputFile)
	: m_program{ program }, m_outputFile{ outputFile }, m_currentCell{ 0 }
{
	if (!(m_outputFile.is_open())) error("Internal error", "Could not create output file. Try running Braindigit as an administrator.");

	m_outputFile << "#include <iostream>\n\nint main()\n{\nchar cells[30000];\nchar *ptr = cells;\n";
}

void CPPTranspiler::incrementPtr()
{
	if (++m_currentCell > 29999) error("Semantic error", "Cannot increment the tape to values greater than 30000");
	m_outputFile << "++ptr;\n";
}

void CPPTranspiler::decrementPtr()
{
	if (++m_currentCell < 0) error("Semantic error", "Cannot decrement the tape to values lesser than 0");
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

void CPPTranspiler::evaluateProgram()
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

	m_outputFile << "}\n";
}