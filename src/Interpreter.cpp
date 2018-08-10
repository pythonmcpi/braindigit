#include "../h/Interpreter.h"

Interpreter::Interpreter(const char program[]) : m_cells{ 0 }, m_cellsPtr{ m_cells }, m_currentCell{ 0 }, m_program { program } {}

void Interpreter::incrementPtr()
{
	if (++m_currentCell > 29999) error("Cells error", "Cannot increment the tape to values greater than 30000");
	++m_cellsPtr;
}

void Interpreter::decrementPtr()
{
	if (--m_currentCell < 0) error("Cells error", "Cannot decrement the tape to values lesser than 0");
	--m_cellsPtr;
}

void Interpreter::incrementByte()
{
	++*m_cellsPtr;
}

void Interpreter::decrementByte()
{
	--*m_cellsPtr;
}

void Interpreter::outputByte()
{
	cout.put(*m_cellsPtr);
}

void Interpreter::inputByte()
{
	*m_cellsPtr = cin.get();
}

void Interpreter::startLoop()
{
	int offset{ 1 };

	if (*m_cellsPtr == '\0') {
		do
		{
			++m_program;
			if (*m_program == '[') ++offset;
			else if (*m_program == ']') --offset;
		} while (offset != 0);
	}
}

void Interpreter::endLoop()
{
	int offset{ 0 };

	do
	{
		if (*m_program == '[') ++offset;
		else if (*m_program == ']') --offset;
		--m_program;
	} while (offset != 0);
}

void Interpreter::evaluateProgram()
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
}
