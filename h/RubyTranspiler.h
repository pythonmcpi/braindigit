#ifndef RUBYTRANSPILER_H
#define RUBYTRANSPILER_H

#include "Common.h"

class RubyTranspiler
{
	ofstream &m_outputFile;
	const char *m_program;

	int m_currentCell;
	int m_openLoops;
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

	RubyTranspiler(const char program[], ofstream &outputFile);

	void evaluateProgram();
};

#endif