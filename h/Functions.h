#include "../h/Common.h"
#include "../h/BrainfuckCommand.h"

void writeBoilerplateCode(std::ofstream &outputStream);
std::string commandToString(BrainfuckCommand command);
std::string runCmd(std::string cmd, bool printOutput = false);