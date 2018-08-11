#include "../h/CTranspiler.h"

CTranspiler::CTranspiler(const char program[], ofstream &outputFile)
	: m_program{ program }, m_outputFile{ outputFile }, m_currentCell{ 0 }, m_openLoops{ 0 }
{
	if (!(m_outputFile.is_open())) error("Internal error", "Could not create output file. Try running Braindigit as an administrator.");

	m_outputFile << "#include <stdio.h>\n\nint main()\n{\nchar cells[30000];\nint ptr = 0;\n";
}

void CTranspiler::incrementPtr()
{
	m_outputFile << "ptr = (ptr == 29999 ? 0 : ptr + 1);\n";
}

void CTranspiler::decrementPtr()
{
	m_outputFile << "ptr = (ptr == 0 ? 29999 : ptr - 1);\n";
}

void CTranspiler::incrementByte()
{
	m_outputFile << "cells[ptr] = (cells[ptr] < 255 ? cells[ptr] + 1 : 0);\n";
}

void CTranspiler::decrementByte()
{
	m_outputFile << "cells[ptr] = (cells[ptr] > 0 ? cells[ptr] - 1 : 29999);\n";
}

void CTranspiler::outputByte()
{
	m_outputFile << "putchar(cells[ptr]);\n";
}

void CTranspiler::inputByte()
{
	m_outputFile << "cells[ptr] = getchar();\n";
}

void CTranspiler::startLoop()
{
	m_outputFile << "while (cells[ptr])\n{\n";
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

