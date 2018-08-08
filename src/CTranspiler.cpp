#include "../h/CTranspiler.h"

CTranspiler::CTranspiler(const char program[], ofstream &outputFile)
	: m_program{ program }, m_outputFile{ outputFile }, m_currentCell{ 0 }, m_openLoops{ 0 }
{
	if (!(m_outputFile.is_open())) error("Internal error", "Could not create output file. Try running Braindigit as an administrator.");

	m_outputFile << "#include <stdio.h>\n\nint main()\n{\nchar cells[30000];\nchar *ptr = cells;\n";
}

void CTranspiler::incrementPtr()
{
	if (++m_currentCell > 29999) error("Cells error", "Cannot increment the tape to values greater than 30000");
	m_outputFile << "++ptr;\n";
}

void CTranspiler::decrementPtr()
{
	if (--m_currentCell < 0) error("Cells error", "Cannot decrement the tape to values lesser than 0");
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
	++m_openLoops;
}

void CTranspiler::endLoop()
{
	m_outputFile << "}\n";
	--m_openLoops;
}

void CTranspiler::evaluateProgram()
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

	if (m_openLoops > 0) error("Loop error", "Unclosed loop, expected ']'");
	if (m_openLoops < 0) error("Loop error", "Non-existent loop closed, expected '['");

	m_outputFile << "}\n";
}

