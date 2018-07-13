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

// I have no idea what this does or how it does it - I just copied it off of the internet
// Commented out: unused, caused compatibility issues
/* std::string runCmd(std::string cmd, bool printOutput)
{
    std::string result = "";
    FILE* pipe = _popen(cmd.c_str(), "r");
    if (!pipe) throw std::runtime_error("popen() failed in getOutputFromCmd");
    try {
        while (!feof(pipe)) {
			char c;
            if ((c=getc(pipe)) != EOF)
			{
                result += c;
                
                if (printOutput)
				{
					std::cout << c;
					std::cout.flush();
				}
			}
        }
    } catch (...) {
        _pclose(pipe);
        throw;
    }
    _pclose(pipe);
    return result;
} */
