#include "../h/PythonTranspiler.h"

PythonTranspiler::PythonTranspiler(const char program[], ofstream &outputFile) :
	m_program{ program }, m_outputFile{ outputFile }, m_currentCell{ 0 }, m_openLoops{ 0 }, m_loopIndents{ "" }
{
	if (!(m_outputFile.is_open())) error("Internal error", "Could not create output file. Try running Braindigit as an administrator.");

	m_outputFile << "import sys\n\ncells = [0]\nptr = 0\n\n";
}

void PythonTranspiler::incrementPtr()
{
	m_outputFile << m_loopIndents << "ptr += 1\n" << m_loopIndents << "if ptr == len(cells): cells.append(0)\n";
}

void PythonTranspiler::decrementPtr()
{
	m_outputFile << m_loopIndents << "ptr = len(cells) - 1 if ptr == 0 else ptr - 1\n";
}

void PythonTranspiler::incrementByte()
{
	m_outputFile << m_loopIndents << "cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0\n";
}

void PythonTranspiler::decrementByte()
{
	m_outputFile << m_loopIndents << "cells[ptr] = cells[ptr] - 1 if cells[ptr] > 0 else 255\n";
}

void PythonTranspiler::outputByte()
{
	m_outputFile << m_loopIndents << "sys.stdout.write(chr(cells[ptr]))\n";
}

void PythonTranspiler::inputByte()
{
	m_outputFile << m_loopIndents << "cells[ptr] = ord(sys.stdin.read(1))\n";
}

void PythonTranspiler::startLoop()
{
	m_outputFile << m_loopIndents << "while cells[ptr]:\n";
	m_loopIndents += "\t";
	++m_openLoops;
	m_outputFile << m_loopIndents << "pass\n";
}

void PythonTranspiler::endLoop()
{
	if (m_loopIndents.length() > 2) m_loopIndents = m_loopIndents.substr(0, m_loopIndents.length() - 2);
	else m_loopIndents = "";
	--m_openLoops;
}

void PythonTranspiler::evaluateProgram()
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
}
