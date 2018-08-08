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
	bool m_pythonTranspile;

	std::string m_inputFilename;
	std::string m_outputFilename;

	void validateFlag(string flag);

	void handleFlags();

public:

	Flags(int flagCount, char **flagData);

	const string &inputFilename() { return m_inputFilename; }
	const string &outputFilename() { return m_outputFilename; }

	bool verbose();
	bool cppTranspile();
	bool cTranspile();
	bool pythonTranspile();
};
#endif