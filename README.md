<p align="center">
<img src="https://github.com/Dandigit/braindigit/raw/master/md/img/braindigit-logo.png"></img>
[![Build Status](https://travis-ci.org/Dandigit/braindigit.svg?branch=master)](https://travis-ci.org/Dandigit/braindigit)
</p>

Brainfuck is a classic esoteric programming language written by Urban Müller. It's made up of just 8 simple commands that manipulate an array 
of 30,000 characters: `> < + - . , [ ]`. **Braindigit is a compiler for Brainfuck.** It takes Brainfuck code and turns it into something the 
computer can understand. \
\
Braindigit can...
* Transpile Brainfuck code into C++
* Compile Brainfuck code

## Installing Braindigit
To get started with Braindigit, first [build it](https://github.com/Dandigit/braindigit/blob/master/BUILDING.md). After you've built it, I recommend 
[adding it to the PATH](https://github.com/Dandigit/braindigit/blob/master/PATH.md) and then you're good to go!

## Using Braindigit
So, you've got Braindigit and a freshly written Brainfuck Hello World program. To compile it with Braindigit, simply run:
```
braindigit filename.b
```
from your command line, replacing `filename.b` with the name of your Brainfuck file. \
Braindigit also offers some basic command line options:
```
braindigit filename.b -p
```
will pause the console when your program finishes executing,
```
braindigit filename.b -t
```
will transpile your program to C++, and
```
braindigit filename.b -d
```
will enable the verbose debugging mode so that if something goes wrong, you can see why.
