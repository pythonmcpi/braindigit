# Building Braindigit
Before you begin, you're going to need the following:
* The Braindigit source code (see below)
* A C++11 compiler

## Getting the Source Code
If you haven't already got Git on your system, download and install it from [here](https://git-scm.com/downloads). Once it's 
installed, run
```
git clone https://github.com/Dandigit/braindigit.git
```
from your command line or Git BASH. A `braindigit` directory containing the source code will then download.

## Windows (VC++)
### With Visual Studio
If you'd like to build Braindigit on Windows, it's easiest to use Microsoft's Visual C++ compiler and Visual Studio. Simply
navigate to the `visualstudio` directory in the source code and open the `braindigit.sln` Visual Studio project. From there, 
you can hit Ctrl+Shift+B to build Braindigit. Once the build is finished, you'll find the binary file in the 
`visualstudio/Debug` directory.

### From the Command Line
Alternatively, you can use the Visual C++ command line tools to build Braindigit. Open the 'Developer Command Prompt for VS' 
app that came with the Visual C++ build tools, navigate to the root source code directory and run
```
cl /EHsc src/*.cpp /out:braindigit.exe
```

## macOS (Clang)
To build Braindigit on macOS, you'll need the Clang compiler. To check if it's already installed, run
```
clang -v
```
in a Terminal window. If a popup appears prompting you to install the Developer Tools, accept it, and Clang will install. If 
instead you recieve output from the Terminal window, you're good to go to the next step. \
Once you've installed Clang you can run
```
clang++ -std=c++11 src/*.cpp -o braindigit
```
from a Terminal window.

## Linux (G++)
On Linux, the build process is very similar to macOS. So similar, in fact, that if you have the Clang compiler installed on
your system (run `clang -v` to check), you can follow the macOS instructions! However, if you'd prefer to use G++, follow these
instructions. \
If G++ is installed (it should be, run `g++ -v` to check), simply run the command
```
g++ -std=c++11 src/*.cpp -o braindigit
```
to build Braindigit.
