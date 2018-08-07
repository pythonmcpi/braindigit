#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "Common.h"

class Interpreter
{
	char m_cells[30000];
	char *m_cellsPtr;

	int m_currentCell;

	const char *m_program;

	void incrementPtr();
	void decrementPtr();
	void incrementByte();
	void decrementByte();
	void outputByte();
	void inputByte();
	void startLoop();
	void endLoop();

public:

	Interpreter(const char program[]);

	void evaluateProgram();
};

#endif