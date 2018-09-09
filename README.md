<p align="center">
<img src="https://github.com/Dandigit/braindigit/raw/master/md/img/braindigit-logo.png"></img>
<br>
<a href="https://travis-ci.org/Dandigit/braindigit">
<img src="https://travis-ci.org/Dandigit/braindigit.svg?branch=master"></img>
</a>
</p>

**A compiler, transpiler and interpreter for Brainfuck.** \
Brainfuck is a classic esoteric programming language written by Urban Müller. It's made up of just 8 simple commands that 
manipulate an array of 30,000 characters: `> < + - . , [ ]`. Braindigit takes Brainfuck code and turns it into something the 
computer can understand, so that you can focus on your Brainfuck program that solves climate change, ends terrorism and
prevents nuclear war. [Source code here, by the way](http://heeeeeeeey.com/).

Braindigit can...
* Interpret Brainfuck code
* Transpile Brainfuck code to C++, C, Python and Ruby

## Installing Braindigit
To get started with Braindigit, first [build it](https://github.com/Dandigit/braindigit/blob/master/BUILDING.md). After you've built it, I recommend 
[adding it to the PATH](https://github.com/Dandigit/braindigit/blob/master/PATH.md) and then you're good to go!

## Using Braindigit
So, you've got Braindigit and a freshly written Brainfuck Hello World program. To run it with Braindigit, simply run:
```
braindigit filename.b
```
from your command line, replacing `filename.b` with the name of your Brainfuck file. This will (by default) invoke the interpreter.

Braindigit also offers some basic command line options to manipulate its behaviour. To list them all, simply run:
`braindigit -h`.
