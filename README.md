# Promptero

Promptero is a header file that has tons of functions that come together to make a C++ Prompt that you can integrate into your program or project, there are multiple types of functions that make up Promptero. 
There are cmds which are commands that the user can run from the userprompt (ex. the info command and the version command).
There are processes that handle everything (the master process and the prompt process).
There are also funcs which make up other important functions.

XXXX = your program that will be using Promptero.
To use this with a c++ program, you must include iostream, signal.h, and Promptero.hpp in your c++ program.
then call the activate() function in XXXX to start Promptero.

    #include <iostream>
    #include <signal.h>
    #include "Promptero.hpp"

    int main (){
        std::cout << "Welcome to XXXX";
        activate();
        // Promptero is now running
    }

activate() runs forever so once Promptero starts running it will also run forever. There is a boolean variable called activateswitch which by default is true, it also acts as a ON/OFF switch for activate(), ON if true, OFF if false.
As long as activateswitch is ON, activate() will keep running forever. However, if you modify Promptero to turn the activateswitch OFF at a certain point (ex. turn the activateswitch OFF once the user runs a command), then Promptero will stop running and control will be returned back to your c++ program.
To start Promptero again, simply turn activateswitch ON and then call activate()
The activateswitch should only be turned off in Promptero, and ON in your c++ program.
When adding a custom command, put it in according to the documentation (documentation link here), or put #include "yourheaderfile.h" in this file and then put your custom command in yourheaderfile.h according to the documentation.
To modify, just change all traces of XXXX to the name of your program or project.

A process is a function that is very important and is needed (and contains things that are needed) for Promptero to work.

The master process is the process that the entire process tree runs in.

The prompt process is the process the prompt runs in.

When modifying Promptero for use with your program, You should never add a second master process or prompt process.

A func is a function that is run from a process and is usually necessary for Promptero.

A cmd is a function that the user can ask Promptero to run.

For more info, please see the comments in Promptero.
