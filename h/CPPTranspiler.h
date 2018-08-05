#ifndef CPPTRANSPILER_H
#define CPPTRANSPILER_H

#include "Common.h"

class CPPTranspiler
{
	ofstream &m_outputFile;
	const char *m_program;

public:

	CPPTranspiler(const char program[], ofstream &outputFile);

	void incrementPtr();
	void decrementPtr();
	void incrementByte();
	void decrementByte();
	void outputByte();
	void inputByte();
	void startLoop();
	void endLoop();

	void evaluate();
};

#endif