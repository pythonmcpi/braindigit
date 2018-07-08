#include "../h/Functions.h"

void writeBoilerplateCode(std::ofstream &outputStream)
{
	outputStream << "#include <iostream>\n#include <stdio.h>\n\nint main(int argc, char *argv[])\n{\nchar *ptr = new char[30000]{ 0 };\n";
}

std::string commandToString(BrainfuckCommand command)
{
	switch (command)
	{
	case INCREMENT_PTR: return "INCREMENT_PTR";
	case DECREMENT_PTR: return "DECREMENT_PTR";
	case INCREMENT_BYTE: return "INCREMENT_BYTE";
	case DECREMENT_BYTE: return "DECREMENT_BYTE";
	case OUTPUT_BYTE: return "OUTPUT_BYTE";
	case INPUT_BYTE: return "INPUT_BYTE";
	case LOOP_START: return "LOOP_START";
	case LOOP_END: return "LOOP_END";
	default: return "(!) INTERNAL ERROR: Could not convert BrainfuckCommand to string";
	}
}