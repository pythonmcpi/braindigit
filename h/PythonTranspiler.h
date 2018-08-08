#ifndef PYTHONTRANSPILER_H
#define PYTHONTRANSPILER_H

#include "Common.h"

class PythonTranspiler
{
	ofstream &m_outputFile;
	const char *m_program;

	int m_currentCell;
	string m_loopIndents;

	void incrementPtr();
	void decrementPtr();
	void incrementByte();
	void decrementByte();
	void outputByte();
	void inputByte();
	void startLoop();
	void endLoop();

public:

	PythonTranspiler(const char program[], ofstream &outputFile);

	void evaluateProgram();
};

#endif