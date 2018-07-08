#include "../h/Common.h"

class Flags
{
	int m_argc;
	char ** m_argv;

	std::string m_fileName;

	bool m_pause;
	bool m_debug;
	bool m_compile;

public:

	Flags(int argc, char *argv[]);

	bool flagExists(const std::string& option);

	void handle();

	std::string &fileName();

	bool pause();
	bool debug();
	bool compile();
};