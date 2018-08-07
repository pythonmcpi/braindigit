#ifndef CTRANSPILER_H
#define CTRANSPILER_H

#include "Common.h"

class CTranspiler
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

	CTranspiler(const char program[], ofstream &outputFile);

	void evaluateProgram();
};

#endif