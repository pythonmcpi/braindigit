clang++ -std=c++11 src/*.cpp -o braindigit

braindigit tests/helloWorld.b
tests/helloWorld

braindigit tests/helloWorld.b -t
tests/helloWorld

braindigit tests/helloWorld.b -t -d -p
tests/helloWorld
