# Promptero

Promptero is a header file that has tons of functions that come together to make a C++ Prompt that you can integrate into your program or project, those functions include commands that can be run from the prompt (the infocommand and versioncommmand), processes that handle everything (the master process and the prompt process), and funcs which make up other important functions.

XXXX = your program that will be using Promptero.
To use this with a c++ file, put #include <iostream> + <signal.h> + "Promptero.hpp", and any other header files that a command, func, process, etc in here uses, then call the activate() function in XXXX to start Promptero.
When adding a custom command, put it in according to the documentation (documentation link here), or put #include "yourheaderfile.h" in this file and then put your custom command in yourheaderfile.h according to the documentation.
To modify, just change all traces of XXXX to the name of your program or project.

Made with love :)

Process Tree + Notes on how it should be written

A process is a function that is very important and is needed (and contains things that are needed) for Promptero to work.
The master process is the process that the entire process tree runs in.
The prompt process is the process the prompt runs in.
There should never be a second master process or prompt process.
"directly run" = being run from int main() or from a command.
A func is a function that is run from a process and is usually necessary for Promptero.
A command is a function that the user can ask Promptero to run, it is run from /userinputhandler\.
For the name of the master/prompt process or a func/command, /name\
For a descriptor [descripter] (descripter: [master process], [prompt process], [func], [command])
For a flag, <flag> (flags: <can throw xerrors>, <can run yon>)
For a note, (note)
For 2 notes, (note) {note}

/master\ [master process] <repeats forever> (runs userprompthandler and x after userprompthandler finishes)
|___/userprompthandler\ [prompt process] (will never need to be directly run and is automatically run forever)
|   |___/userprompt\ [func] saves input from the user to be used later (can be run whenever a command needs input from user, ex. a command is asking the user to type something to name a file)
|   |___/userinputhandler\ [Func] <can throw xerrors> graps input from the user (will never need to be directly run, userprompthandler does that for you) 
|   |   |___/.command\ [command] <can throw xerrors> <can run yon> any command that can be run in XXXX, ex. mkfilecmd (will never need to be directly run, userinputhandler does that for you) {the "." can be the name of any command, ex. version or info}
|   |   |
|   |___/yon\ [Func] <can throw xerrort1s1 (invalid option)> asks the user "yes" or "no" and saves and refines their input to be used later (can be run whenever a command asks the user a yes or no question ex. if the users want to end XXXX or not) {userinputhandler can run yon and XXXX can be returned back to userinputhandler once yon is done running}
|___/x\ [Func] catches xerrors and xoutputs and decides what to with them, ex. telling the user about them (will never need to be directly run, master does that for you)
