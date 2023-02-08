#ifndef STATS_H_INCLUDED
#define STATS_H_INCLUDED

/*These two functions are used to print statistics in the screen
The functions print how many dots and hyphens are in a Morse Code
The first function reads the Morse Code from a file
The second one asks the user to enter his own Morse Code*/
void statisticsFileReading()
{
    char ch; //to store each char in the file
    int dotCnt=0; //to count dots
    int hypCnt=0; //to count hyphens
    char space;
    scanf("%c", &space);
    printf("Enter file name: ");
    char fileName[50];
    scanf("%s", fileName); //reading the name of the file
    FILE* inputFile;
    inputFile=fopen(fileName, "r");
    if(inputFile==NULL)
    {
        printf("File cannot be opened!");
        return;
    }
    ch = fgetc(inputFile);
    while(ch!=EOF)
    {
        if(ch=='.')
            dotCnt++;
        else if(ch=='-')
            hypCnt++;
        ch = fgetc(inputFile);
    }
    printf("Dots: %d\nHyphens: %d", dotCnt, hypCnt);
    fclose(inputFile);
}

void statisticsCommandPrompt()
{
    char tempChar;
    scanf("%c", &tempChar); //enter key
    int dotCnt=0;
    int hypCnt=0;
    printf("Enter Morse Code to analyse: ");
    scanf("%c", &tempChar);
    while(tempChar!='\n')
    {
        if(tempChar=='.')
            dotCnt++;
        else if(tempChar=='-')
            hypCnt++;
        scanf("%c", &tempChar);
    }
    printf("Dots: %d\nHyphens: %d", dotCnt, hypCnt);
}

#endif // STATS_H_INCLUDED
