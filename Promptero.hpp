/*
Version 1
Promptero -- By Cactical.
Promptero is a header file that has tons of functions that come together to make a C++ Prompt that you can integrate into your program or project, those functions include commands that can be run from the prompt (the infocommand and versioncommmand), processes that handle everything (the master process and ), and funcs which 
XXXX = your program that will be using Promptero.
To use this with a c++ file, put #include <iostream> + <signal.h> + "Promptero.hpp", and any other header files that a command, func, process, etc in here uses, then call the activate() function in XXXX to start Promptero.
When adding a custom command, put it in according to the documentation (documentation link here), or put #include "yourheaderfile.h" in this file and then put your custom command in yourheaderfile.h according to the documentation.
To modify, just change all traces of XXXX to the name of your program or project.

Made with love :)

Process Tree

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

*/

// #### global variable settings >>>>

/* activateswitch var. A switch that controls if activate() will run when being called (on state) or not (off state).
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
This var is effectively a switch that controls whether activate will be on (activate will run) or off (activate wont run). Once activate() is called in the XXXX file, control will be passed to Promptero and Promptero wil be in control forever, but you can return control to XXXX by making activateswitch false in the XXXX file, then control will return to the XXXX file. You can also return control to Promptero by simply making activateswitch true and then calling activate() to start up Promptero again. */
bool activateswitch = true;

/* userinput var. Input from the user. 
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
When userprompt is called, the user types something and whatever they type becomes userinput and userinputhandler decides what to do with userinput. */
std::string userinput;

/* yoninputrefined var. Refined version of yoninput var.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
XXXX takes the yoninput var (only specified in the yon func) and refines it and maps the refined version to this var.*/
std::string yoninputrefined;

// #### x error and output settings >>>>

/* X output: type 1 (command cancelled). 
--------------------------------------------------------
Is true if: a command was cancelled. */
bool xOUTPUTt1;

/* X error: type 1 (*info*).
------------------------------------------------------------------------------------------------------
Is true if: userinput couldnt be matched with the name of a command.*/
bool xERRORt1;

/* X error: type 1 subtype 1 (*info*).
----------------------------------------------------------------------------------------------------------------------------------------------
Is true if: userinput couldnt be matched with the name of a option that a command gave the user.*/
bool xERRORt1s1;

/* X error: type 2 (command cancelled unexpectedly). 
-------------------------------------------------------------------------
Is true if: a command was cancelled unexpectedly. */
bool xERRORt2;

/* X error: type 2 subtype 1 (command cancelled because the command is not fully developed). 
--------------------------------------------------------------------------------------------------------------------------------------
Is true if: a command was run but it was cancelled because it was not fully developed yet. */
bool xERRORt2s1;

// <<<< x error and outputsettings ####

// <<<< global variable settings ####

// #### function settings >>>>

// #### function declaration >>>>

// Only declare a function here if necessary, otherwise declare the function when defining it like normal.

// Basic necessary functions

void activate();
void master();
void userprompthandler();
void userprompt();
void userinputhandler();
void x();
void yon();
__sighandler_t signalhandler();

// commands 

void infocommand();
void versioncommand();
int endcommand();
void examplecommand();


// <<<< function declaration ####

// #### function definition >>>>


/* signalhandler func. Handles the sigint signal.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
If the user does ctrl+c (sigint) this func will start and it will tell them to use the endprgm (not completely working yet). */
void signalhandler(int signum) {
   std::cout << "\nPlease use the endprgm, \"end.\" U: ";
}

/* activate func. Activates Promptero.
------------------------------------------------------
Starts Promptero and calls master(). */
void activate() {
    while (activateswitch == true) {
        signal(SIGINT, signalhandler);
        master();
    }    
}

/* master process. Handles userprompthandler and x and makes userprompthandler and x run forever.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
The master process, which is the first thing that runs in XXXX. Immediately runs userprompthandler and then runs x to catch errors and extra output once userprompthandler finishes. */
void master() {    
    userprompthandler();
    x();
}


/* prompt process. Handles userprompt and userinputhandler.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
Runs userprompt so the user can tell XXXX what to do, then runs userinputhandler so XXXX can do something with what the user tells XXXX to do.*/
void userprompthandler() {
    userprompt();
    userinputhandler();
}

/* userprompt. Prompt that the user types in. 
-----------------------------------------------------------------------------------
Input from this prompt is dumped into the var userinput. */
void userprompt() {
    std::cout << "U: "; std::getline(std::cin, userinput);
}

/* userinputhandler func. Handles user input.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
Sees if userinput matches up with a command name, if so, run the command, if not, change the xERRORt1 var to true to have X throw a error. */
void userinputhandler() {
    if (userinput == "info") {
        infocommand();        
    } else if (userinput == "version") {
        versioncommand();
    }  else if (userinput == "end") {
        std::cout << "Are you sure you want to end?";
        yon();
        if (yoninputrefined == "Y") {
            endcommand();
        } else if (yoninputrefined == "N") {
            // Throw "command cancelled" output
            xOUTPUTt1 = true;
        }
    } else if (userinput == "example") {
        examplecommand();
    } else {
        // Check to see if userinput is empty, if so, dont display a error and just throw the user back into the prompt.
        if (userinput == "") {
            xERRORt1 = false;
        } else {
            // Throw "Invalid prgm" error
            xERRORt1 = true;
        }
    }
}

/* x func. Error and extra output handler.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
Runs everytime userprompthandler is run to catch errors and extra output. If a error is thrown it catches it and displays a error, and then disables the error so it wont show again, if some extra output is thrown then it does the same thing. */
void x() {
    if (xOUTPUTt1 == true) {
        std::cout << "command cancelled. \n";
        xOUTPUTt1 = false;
    } else if (xERRORt1 == true) {
        std::cout << "command does not exist. \n";
        xERRORt1 = false;
    } else if (xERRORt1s1 == true){
        std::cout << "option does not exist. \n";
        xERRORt1s1 = false;
    } else if (xERRORt2 == true) {
        std::cout << "command cancelled unexpectedly. \n";
        xERRORt2 = false;
    } else if (xERRORt2s1 == true) {
        std::cout << "command cancelled. reason: command is not fully developed yet. \n";
        xERRORt2s1 = false;
    }
}


/* yon func. Asks the user yes or no whenever a func or command asks the user a question that can be answered with yes or no. 
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
Asks user yes or no and runs userprompt so the user can answer, then it takes what the user said and maps it to a var, then refine that var and decide what to do with the refined var. */
void yon() {
    // (yon func var) | Input yon takes from the user, yon takes the input from userinput and maps it to variable called yoninput
    std::string yoninput;
    std::cout << " (Y/N) \n";
    std::cout << "\\___ ";
    userprompt();
    yoninput = userinput;

    if (yoninput == "Y") {
        yoninputrefined = "Y";
    } else if (yoninput == "y") {
        yoninputrefined = "Y";   
    } else if (yoninput == "Yes") {
        yoninputrefined = "Y";   
    } else if (yoninput == "yes") {
        yoninputrefined = "Y";   
    } else if (yoninput == "YES") {
        yoninputrefined = "Y";
    } else if (yoninput == "N") {
        yoninputrefined = "N";   
    } else if (yoninput == "n") {
        yoninputrefined = "N";
    } else if (yoninput == "No") {
        yoninputrefined = "N";  
    } else if (yoninput == "no") {
        yoninputrefined = "N";
    } else if (yoninput == "NO") {
        yoninputrefined = "N";
    } else {
        xERRORt1s1 = true;
        x();
    }
}
/* Info command. Displays info about XXXX.
-----------------------------------------------------------
Displays info and help guide. */ 
void infocommand() {
    std::cout << "\nXXXX (version X.X.X) -- By Cactical.\n";
    std::cout << "XXXX is a (*info*).\n";
    std::cout << "To exit XXXX, please use the endcommand, \"end\". \n";
    std::cout << "\n";
    std::cout << "                           COMMANDS\n";
    std::cout << "----------------------------------------------------------\n";
    std::cout << "[^] = Not fully developed\n";
    std::cout << "When running a command, you must type the name of it in lowercase for it to run.\n"; 
    std::cout << "[^] Info - Displays this help guide and info.\n";
    std::cout << "Version - Displays version of XXXX.\n";
    std::cout << "End - Ends the current XXXX session. \n";
    std::cout << "Example - Displays the word \"example\". \n";
}

/* Version command. Displays version of XXXX.
----------------------------------------------------------------
Shows version of XXXX. */
void versioncommand() {
    std::cout << "XXXX X.X.X";
}


/* End command. Ends XXXX.
------------------------------------------------------------------------------------------------------------------------------------------
What the user will type to end the command they are in, if they arent in one then XXXX will end. */
int endcommand() {
    exit(0);
}

/* Example command. Example program
--------------------------------------------------------
Displays example text. */
void examplecommand() {
    std::cout << "This is a example command.\n";
}

// <<<< function definition ####

// <<<< function settings ####








