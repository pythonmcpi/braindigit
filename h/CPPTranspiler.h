#ifndef CPPTRANSPILER_H
#define CPPTRANSPILER_H

#include "Common.h"

class CPPTranspiler
{
	ofstream &m_outputFile;
	const char *m_program;

	int m_currentCell;
	int m_openLoops;

	void incrementPtr();
	void decrementPtr();
	void incrementByte();
	void decrementByte();
	void outputByte();
	void inputByte();
	void startLoop();
	void endLoop();

public:

	CPPTranspiler(const char program[], ofstream &outputFile);

	void evaluateProgram();
};

#endif