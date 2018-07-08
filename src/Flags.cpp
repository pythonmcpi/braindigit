#include "../h/Flags.h"

Flags::Flags(int argc, char *argv[])
	: m_argc{ argc }, m_argv{ argv }, m_fileName{ argv[1] }, m_pause{ false }, m_debug{ false }, m_compile{ true }
{

}

bool Flags::flagExists(const std::string& option)
{
	return std::find(m_argv, m_argv + m_argc, option) != m_argv + m_argc;
}

void Flags::handle()
{
	if (m_argc < 2 || m_argc > 5)
	{
		std::cerr << "Usage: brainfuck <file.b> | -p | -d | -t |\n";
		exit(2);
	}

	if (flagExists("-d"))
	{
		m_debug = true;
		std::cout << "(i) Debugging is enabled\n";
	}

	if (flagExists("-p"))
	{
		m_pause = true;
		if (m_debug)
			std::cout << "(i) Console pausing is enabled\n";
	}
	if (flagExists("-t"))
	{
		m_compile = false;
		if (m_debug)
			std::cout << "(i) Compiling is disabled\n";
	}
}

std::string& Flags::fileName()
{
	return m_fileName;
}

bool Flags::pause()
{
	return m_pause;
}

bool Flags::debug()
{
	return m_debug;
}

bool Flags::compile()
{
	return m_compile;
}