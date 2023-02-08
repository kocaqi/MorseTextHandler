#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED

typedef struct englishText
{
    char c;
    struct englishText *next;
} english;

/*This function is used to convert one Latin Character
into International Morse Character*/
void charToMorse(char ch, int* dotCnt, int* hypCnt)
{
    switch(ch)
    {
    case 'a':
    case 'A':
        printf(".-");
        *dotCnt++;
        *hypCnt++;
        break;
    case 'b':
    case 'B':
        printf("-...");
        *dotCnt+=3;
        *hypCnt++;
        break;
    case 'c':
    case 'C':
        printf("-.-.");
        *dotCnt+=2;
        *hypCnt+=2;
        break;
    case 'd':
    case 'D':
        printf("-..");
        *dotCnt+=2;
        *hypCnt+=1;
        break;
    case 'e':
    case 'E':
        printf(".");
        *dotCnt+=1;
        break;
    case 'f':
    case 'F':
        printf("..-.");
        *dotCnt+=3;
        *hypCnt+=1;
        break;
    case 'g':
    case 'G':
        printf("--.");
        *dotCnt+=1;
        *hypCnt+=2;
        break;
    case 'h':
    case 'H':
        printf("....");
        *dotCnt+=4;
        break;
    case 'i':
    case 'I':
        printf("..");
        *dotCnt+=2;
        break;
    case 'j':
    case 'J':
        printf(".---");
        *dotCnt+=1;
        *hypCnt+=3;
        break;
    case 'k':
    case 'K':
        printf("-.-");
        *dotCnt+=1;
        *hypCnt+=2;
        break;
    case 'l':
    case 'L':
        printf(".-..");
        *dotCnt+=3;
        *hypCnt+=1;
        break;
    case 'm':
    case 'M':
        printf("--");
        *hypCnt+=2;
        break;
    case 'n':
    case 'N':
        printf("-.");
        *dotCnt+=1;
        *hypCnt+=1;
        break;
    case 'o':
    case 'O':
        printf("---");
        *hypCnt+=3;
        break;
    case 'p':
    case 'P':
        printf(".--.");
        *dotCnt+=2;
        *hypCnt+=2;
        break;
    case 'q':
    case 'Q':
        printf("--.-");
        *dotCnt+=1;
        *hypCnt+=3;
        break;
    case 'r':
    case 'R':
        printf(".-.");
        *dotCnt+=2;
        *hypCnt+=1;
        break;
    case 's':
    case 'S':
        printf("...");
        *dotCnt+=3;
        break;
    case 't':
    case 'T':
        printf("-");
        *hypCnt+=1;
        break;
    case 'u':
    case 'U':
        printf("..-");
        *dotCnt+=2;
        *hypCnt+=1;
        break;
    case 'v':
    case 'V':
        printf("...-");
        *dotCnt+=3;
        *hypCnt+=1;
        break;
    case 'w':
    case 'W':
        printf(".--");
        *dotCnt+=1;
        *hypCnt+=2;
        break;
    case 'x':
    case 'X':
        printf("-..-");
        *dotCnt+=2;
        *hypCnt+=2;
        break;
    case 'y':
    case 'Y':
        printf("-.--");
        *dotCnt+=1;
        *hypCnt+=3;
        break;
    case 'z':
    case 'Z':
        printf("--..");
        *dotCnt+=2;
        *hypCnt+=2;
        break;
    case '1':
        printf(".----");
        *dotCnt+=1;
        *hypCnt+=4;
        break;
    case '2':
        printf("..---");
        *dotCnt+=2;
        *hypCnt+=3;
        break;
    case '3':
        printf("...--");
        *dotCnt+=3;
        *hypCnt+=2;
        break;
    case '4':
        printf("....-");
        *dotCnt+=4;
        *hypCnt+=1;
        break;
    case '5':
        printf(".....");
        *dotCnt+=5;
        break;
    case '6':
        printf("-....");
        *dotCnt+=4;
        *hypCnt+=1;
        break;
    case '7':
        printf("--...");
        *dotCnt+=3;
        *hypCnt+=2;
        break;
    case '8':
        printf("---..");
        *dotCnt+=2;
        *hypCnt+=3;
        break;
    case '9':
        printf("----.");
        *dotCnt+=1;
        *hypCnt+=4;
        break;
    case '0':
        printf("-----");
        *dotCnt+=5;
        break;
    case '.':
        printf(".-.-.-");
        *dotCnt+=3;
        *hypCnt+=3;
        break;
    case ',':
        printf("--..--");
        *dotCnt+=2;
        *hypCnt+=4;
        break;
    case '?':
        printf("..--..");
        *dotCnt+=4;
        *hypCnt+=2;
        break;
    case '!':
        printf("-.-.--");
        *dotCnt+=2;
        *hypCnt+=4;
        break;
    case ':':
        printf("---...");
        *dotCnt+=3;
        *hypCnt+=3;
        break;
    case ';':
        printf("-.-.-.");
        *dotCnt+=3;
        *hypCnt+=3;
        break;
    case '-':
        printf("-....-");
        *dotCnt+=4;
        *hypCnt+=2;
        break;
    case '_':
        printf("..--.-");
        *dotCnt+=3;
        *hypCnt+=3;
        break;
    case '"':
        printf(".-..-.");
        *dotCnt+=4;
        *hypCnt+=2;
        break;
    case ' ':
        printf(" / ");
        break;
    case '\n':
        printf("\n");
        break;
    default:
        printf("#");
    }
    printf(" ");
}

/*These two functions are used to convert text into Morse Code
The first function reads the text from a file
The second one asks the user to enter his own text*/
void textIntoMorseFileReading()
{
    int dotCnt = 0;
    int hypCnt = 0;
    char ch;
    FILE* inputFile;
    char space; //to read the newline after second menu
    scanf("%c", &space);
    printf("Enter file name: ");
    char fileName[50];
    scanf("%s", fileName);
    inputFile=fopen(fileName, "r");
    if(inputFile==NULL)
    {
        printf("File cannot be opened!");
        return;
    }
    ch = fgetc(inputFile);
    while(ch!=EOF)
    {
        //print Morse Code for every character in the file
        charToMorse(ch, &dotCnt, &hypCnt);
        ch = fgetc(inputFile);
    }
    printf("\n--Statstics--\nDots: %d\nHyphens: %d", dotCnt, hypCnt);
    fclose(inputFile);
}

void textIntoMorseCommandPrompt()
{
    int dotCnt=0;
    int hypCnt=0;
    english *head;
    english *newChar;
    english *temp;
    head = (english*)malloc(sizeof(english));
    char space;
    scanf("%c",&space); //enter key
    //int i=0;
    char tempChar;
    printf("Enter text to encode: ");
    scanf("%c", &tempChar);
    head->c = tempChar;
    head->next = NULL;
    temp = head;
    while(tempChar!='\n')
    {
        newChar = (english*)malloc(sizeof(english));
        scanf("%c", &tempChar);
        if(tempChar!='\n')
        {
            newChar->c = tempChar;
            newChar->next = NULL;
            temp -> next = newChar;
            temp = temp->next;
        }
    }
    temp = head;
    while(temp != NULL)
    {
        charToMorse(temp->c, &dotCnt, &hypCnt);
        temp = temp->next;
    }
    printf("\n--Statstics--\nDots: %d\nHyphens: %d", dotCnt, hypCnt);
    free(temp);
    destroySLL(head);
}

#endif // TEXT_H_INCLUDED
