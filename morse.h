#ifndef MORSE_H_INCLUDED
#define MORSE_H_INCLUDED

/*This structure defines a node in the  binary tree, which contains the English Letter Character
and 2 pointer to its left and right children, which are also nodes of the same type*/
typedef struct node
{
    char c;
    struct node *left;
    struct node *right;
} Node;

typedef struct morse
{
    char c;
    struct morse *prev;
    struct morse *next;
} morse;

/*These two functions are used to convert Morse Code into text
The first function reads the Morse Code from a file
The second one asks the user to enter his own Morse Code*/
void morseIntoTextFileReading(Node *root)
{
    int dotCnt = 0;
    int hypCnt = 0;
    char ch;
    /*this char variable is used to read the newline
    that is input after choosing from the second menu, so as
    not to interrupt with the name of the file, also to get
    the characters of the file one-by-one*/
    scanf("%c", &ch);
    printf("Enter file name: ");
    FILE* inputFile;
    char fileName[50];
    scanf("%s", fileName); //reading the name of the file
    inputFile=fopen(fileName, "r");
    if(inputFile==NULL) //in case not given correct name, or anything else gone wrong
    {
        printf("File cannot be opened!");
        return;
    }
    Node *temp;
    temp = root; //we iterate through the tree using another helping variable, so as to keep reference of the root untouched
    ch = fgetc(inputFile);
    while(ch!=EOF)
    {
        //if the current character is a dot, go to the left child and read the next character
        if(ch=='.')
        {
            temp=temp->left;
            ch=fgetc(inputFile);
            dotCnt++;
        }
        //if the current character is a hyphen, go to the right child and read the next character
        else if(ch=='-')
        {
            temp=temp->right;
            ch=fgetc(inputFile);
            hypCnt++;
        }
        //if the current charatcer is a space
        else
        {
            //print the corresponding English Alphabet Letter
            printf("%c", temp->c);
            //read next character
            ch=fgetc(inputFile);
            //if END OF FILE is reached, get out of the loop
            if(ch==EOF)
                break;
            //otherwise, if it is a slash, then we are dealing with a space in English Text
            else if(ch=='/')
            {
                printf(" "); //print the space
                ch=fgetc(inputFile); //read the next character in the file, which is a space
                ch=fgetc(inputFile); //then read the next character, which is the first of the next letter
            }
            temp = root; //make temp variable point at the beginning of the tree for the next letter to be calculated properly
        }
    }
    printf("\n--Statstics--\nDots: %d\nHyphens: %d", dotCnt, hypCnt);
    fclose(inputFile); //close the file
    destroyTree(root);
    free(temp);
}

void morseIntoTextCommandPrompt(Node *root)
{
    /*this space char variable is used to read the newline
    that is input after choosing from the second menu, so as
    not to interrupt with the name of the file*/
    char space;
    scanf("%c", &space);

    int dotCnt = 0;
    int hypCnt = 0;

    morse *head;
    morse *curr;
    morse *last;
    printf("Enter text to decode: ");
    head = (morse*)malloc(sizeof(morse));
    char tempChar;
    scanf("%c", &tempChar);
    head->c = tempChar;
    head->prev=NULL;
    head->next=NULL;
    last = head;
    while(tempChar!='\n')
    {
        curr = (morse*)malloc(sizeof(morse));
        scanf("%c", &tempChar);
        curr->c = tempChar;
        curr->prev = last;
        curr->next = NULL;
        last->next = curr;
        last = curr;
    }
    Node *temp;
    temp=root; //we iterate through the tree using another helping variable, so as to keep reference of the root untouched
    curr=head;
    while(1)
    {
        //use the same logic as above to iterate through the tree
        tempChar = curr->c;
        if(tempChar=='.')
        {
            temp=temp->left;
            curr = curr->next;
            dotCnt++;
        }
        else if(tempChar=='-')
        {
            temp=temp->right;
            curr = curr->next;
            hypCnt++;
        }
        else
        {
            printf("%c", temp->c);
            temp=root; //make temp point again to beginning of tree
            curr = curr->next;
            if(curr == NULL)
                break;
            tempChar = curr->c;
            if(tempChar=='\0')
                break;
            else if(tempChar == '/')
            {
                printf(" ");
                curr = curr->next->next;
            }
        }
    }
    printf("\n--Statstics--\nDots: %d\nHyphens: %d", dotCnt, hypCnt);
    free(temp);
    destroyTree(root);
    free(curr);
    free(last);
    destroyDLL(head);
}

#endif // MORSE_H_INCLUDED
