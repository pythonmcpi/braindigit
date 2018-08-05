#ifndef FLAGS_H
#define FLAGS_H

#include "Common.h"

class Flags
{
	int m_flagCount;
	vector<string> m_flagData;

	bool m_verbose;
	bool m_cppTranspile;
	bool m_cTranspile;

	std::string m_inputFilename;
	std::string m_outputFilename;

public:

	Flags(int flagCount, char **flagData);

	void handle();

	const string &inputFilename() { return m_inputFilename; }
	const string &outputFilename() { return m_outputFilename; }

	bool verbose();
	bool cppTranspile();
	bool cTranspile();
};

#endif