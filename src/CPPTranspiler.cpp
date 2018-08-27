#include "../h/CPPTranspiler.h"

CPPTranspiler::CPPTranspiler(const char program[], ofstream &outputFile)
	: m_program{ program }, m_outputFile{ outputFile }, m_currentCell{ 0 }, m_openLoops{ 0 }
{
	if (!(m_outputFile.is_open())) error("Internal error", "Could not create output file. Try running Braindigit as an administrator.");

	m_outputFile << "#include <iostream>\n\nint main()\n{\nchar cells[30000];\nint ptr = 0;\n";
}

void CPPTranspiler::incrementPtr()
{
	if (++m_currentCell > 29999) error("Cells error", "Cannot increment the tape to values greater than 30000");
	m_outputFile << "ptr = (ptr == 29999 ? 0 : ptr + 1);\n";
}

void CPPTranspiler::decrementPtr()
{
	if (--m_currentCell < 0) error("Cells error", "Cannot decrement the tape to values lesser than 0");
	m_outputFile << "ptr = (ptr == 0 ? 29999 : ptr - 1);\n";
}

void CPPTranspiler::incrementByte()
{
	m_outputFile << "cells[ptr] = (cells[ptr] < 255 ? cells[ptr] + 1 : 0);\n";
}

void CPPTranspiler::decrementByte()
{
	m_outputFile << "cells[ptr] = (cells[ptr] > 0 ? cells[ptr] - 1 : 255);\n";
}

void CPPTranspiler::outputByte()
{
	m_outputFile << "std::cout.put(cells[ptr]);\n";
}

void CPPTranspiler::inputByte()
{
	m_outputFile << "cells[ptr] = std::cin.get();\n";
}

void CPPTranspiler::startLoop()
{
	m_outputFile << "while (cells[ptr])\n{\n";
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
			break;
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