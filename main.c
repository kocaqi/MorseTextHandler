#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "morse.h"
#include "text.h"
#include "stats.h"
#include "structures.h"

/*These three functions are used to print messages to the screen
and give the user the possibility to choose what he wants to do*/
void showIntro();
int showTypeOfReadingMenu();
int showHandlerMenu();
/*This is the run() function which calls all other
functions in order to execute the program*/
void run();

int main()
{
    run();
    return 0;
}

void showIntro()
{
    printf("Hello, welcome to my project which encodes and decodes morse code\n");
}

int showTypeOfReadingMenu()
{
    int option;
    printf("Option 1 choses file handling and Option 2 lets the user type directly into command prompt\n\n");
    printf("Which option would you like to choose..\n");
    printf("1) Read from file\n");
    printf("2) Command prompt\n");
    scanf("%d", &option);
    return option;
}

int showHandlerMenu()
{
    int option;
    printf("Which option would you like to choose..\n");
    printf("1) Encode\n");
    printf("2) Decode\n");
    printf("3) Statistics\n");
    scanf("%d", &option);
    return option;
}

void run()
{
    Node *root;
    root=fillTree();
    showIntro();
    int type = showTypeOfReadingMenu();
    int handling = showHandlerMenu();
    if(type==1 && handling==1)
        textIntoMorseFileReading();
    else if(type==1 && handling==2)
        morseIntoTextFileReading(root);
    else if(type==1 && handling==3)
        statisticsFileReading();
    else if(type==2 && handling==1)
        textIntoMorseCommandPrompt();
    else if(type==2 && handling==2)
        morseIntoTextCommandPrompt(root);
    else
        statisticsCommandPrompt();
    //free(root);
}
