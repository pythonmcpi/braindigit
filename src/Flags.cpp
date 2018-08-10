#include "../h/Flags.h"

Flags::Flags(int flagCount, char **flagData)
	: m_flagCount{ flagCount },
	m_flagData{ flagData, flagData + flagCount },
	m_cppTranspile{ false },
	m_cTranspile{ false },
	m_pythonTranspile{ false },
	m_rubyTranspile{ false }
{
	handleFlags();
}

void Flags::validateFlag(string flag)
{
	if (flag != "-v" &&
		flag != "-o" &&
		flag != "-c" &&
		flag != "-cpp" &&
		flag != "-c++" &&
		flag != "-python" &&
		flag != "-py" &&
		flag != "-ruby" &&
		flag != "-rb")
	{
		error("Fatal error", "Invalid flag \"" + flag + "\"provided");
	}
}

void Flags::handleFlags()
{
	if (m_flagData.size() < 2) error("Fatal error", "No input file provided");

	m_inputFilename = m_flagData[1];
	m_outputFilename = m_inputFilename.substr(0, m_inputFilename.find('.')) + ".cpp";

	for (unsigned int currentIndex = 2; currentIndex < m_flagData.size(); ++currentIndex)
	{
		validateFlag(m_flagData[currentIndex]);

		bool filenameProvided{ false };

		if (m_flagData[currentIndex] == "-v")
			m_verbose = true;
		else if (m_flagData[currentIndex] == "-cpp" || m_flagData[currentIndex] == "-c++")
			m_cppTranspile = true;
		else if (m_flagData[currentIndex] == "-c")
			m_cTranspile = true;
		else if (m_flagData[currentIndex] == "-python" || m_flagData[currentIndex] == "-py")
			m_pythonTranspile = true;
		else if (m_flagData[currentIndex] == "-ruby" || m_flagData[currentIndex] == "-rb")
			m_rubyTranspile = true;
		else if (m_flagData[currentIndex] == "-o")
		{
			m_outputFilename = m_flagData[++currentIndex];
			filenameProvided = true;
		}

		if (!(filenameProvided) && m_cppTranspile)
			m_outputFilename = m_inputFilename.substr(0, m_inputFilename.find('.')) + ".cpp";
		else if (!(filenameProvided) && m_cTranspile)
			m_outputFilename = m_inputFilename.substr(0, m_inputFilename.find('.')) + ".c";
		else if (!(filenameProvided) && m_pythonTranspile)
			m_outputFilename = m_inputFilename.substr(0, m_inputFilename.find('.')) + ".py";
		else if (!(filenameProvided) && m_rubyTranspile)
			m_outputFilename = m_inputFilename.substr(0, m_inputFilename.find('.')) + ".rb";

		if (filenameProvided && !(m_cppTranspile || m_cTranspile || m_pythonTranspile || m_rubyTranspile))
			warning("Warning", "An output filename has been provided, however it will not be used as transpiling has not been enabled");
	}
}

bool Flags::verbose() { return m_verbose; }
bool Flags::cppTranspile() { return m_cppTranspile; }
bool Flags::cTranspile() { return m_cTranspile; }
bool Flags::pythonTranspile() { return m_pythonTranspile; }
bool Flags::rubyTranspile() { return m_rubyTranspile; }