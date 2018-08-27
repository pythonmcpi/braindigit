#include "../h/RubyTranspiler.h"

RubyTranspiler::RubyTranspiler(const char program[], ofstream &outputFile) :
	m_program{ program }, m_outputFile{ outputFile }, m_currentCell{ 0 }, m_openLoops{ 0 }, m_loopIndents{ "" }
{
	if (!(m_outputFile.is_open())) error("Internal error", "Could not create output file. Try running Braindigit as an administrator.");

	m_outputFile << "@cells = [0]\n@ptr = 0\n\n";
}

void RubyTranspiler::incrementPtr()
{
	m_outputFile << m_loopIndents << "@ptr += 1\n";
	m_outputFile << m_loopIndents << "@cells.push(0) if @ptr == @cells.length\n";
}

void RubyTranspiler::decrementPtr()
{
	m_outputFile << m_loopIndents << "@ptr = (@ptr == 0 ? @cells.size - 1 : @ptr - 1)\n";
}

void RubyTranspiler::incrementByte()
{
	m_outputFile << m_loopIndents << "@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)\n";
}

void RubyTranspiler::decrementByte()
{
	m_outputFile << m_loopIndents << "@cells[@ptr] = (@cells[@ptr] > 0 ? @cells[@ptr] - 1 : 255)\n";
}

void RubyTranspiler::outputByte()
{
	m_outputFile << m_loopIndents << "print @cells[@ptr].chr if @cells[@ptr]\n";
}

void RubyTranspiler::inputByte()
{
	m_outputFile << m_loopIndents << "@cells[@ptr] = STDIN.getc\n@cells[@ptr] = 0 unless @cells[@ptr]\n";
}

void RubyTranspiler::startLoop()
{
	m_outputFile << m_loopIndents << "while @cells[@ptr] != 0\n";
	m_loopIndents += "\t";
	++m_openLoops;
}

void RubyTranspiler::endLoop()
{
	if (m_loopIndents.length() > 2) m_loopIndents = m_loopIndents.substr(0, m_loopIndents.length() - 2);
	else m_loopIndents = "";
	m_outputFile << m_loopIndents << "end\n";
	--m_openLoops;
}

void RubyTranspiler::evaluateProgram()
{
	while (*m_program)
	{
		switch (*m_program)
		{
		case '>':
			incrementPtr();
			break;
		case '<':
			decrementPtr();
			break;
		case '+':
			incrementByte();
			break;
		case '-':
			decrementByte();
			break;
		case '.':
			outputByte();
			break;
		case ',':
			inputByte();
			break;
		case '[':
			startLoop();
			break;
		case ']':
			endLoop();
			break;
		}

		++m_program;
	}

	if (m_openLoops > 0) error("Loop error", "Unclosed loop, expected ']'");
	if (m_openLoops < 0) error("Loop error", "Non-existent loop closed, expected '['");
}
