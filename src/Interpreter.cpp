#include "../h/Interpreter.h"

Interpreter::Interpreter(const char program[]) : m_cells{ 0 }, m_cellsPtr{ m_cells }, m_program{ program } {}

void Interpreter::incrementPtr()
{
	++m_cellsPtr;
}

void Interpreter::decrementPtr()
{
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
	int bal = 1;
	if (*m_cellsPtr == '\0') {
		do {
			++m_program;
			if (*m_program == '[') bal++;
			else if (*m_program == ']') bal--;
		} while (bal != 0);
	}
}

void Interpreter::endLoop()
{
	int bal = 0;
	do {
		if (*m_program == '[') bal++;
		else if (*m_program == ']') bal--;
		--m_program;
	} while (bal != 0);
}

void Interpreter::evaluate()
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