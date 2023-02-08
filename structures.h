#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

/*This function is used to fill the binary tree with English Alphabet characters
so as to be used to decode Morse code into text*/
Node* fillTree()
{
    //create the root node
    Node *root;

    //Allocate memory for every node of the tree
    root = (Node*)malloc(sizeof(Node));

    root->left=(Node*)malloc(sizeof(Node));
    root->right=(Node*)malloc(sizeof(Node));

    root->left->left=(Node*)malloc(sizeof(Node));
    root->left->right=(Node*)malloc(sizeof(Node));
    root->right->left=(Node*)malloc(sizeof(Node));
    root->right->right=(Node*)malloc(sizeof(Node));

    root->left->left->left=(Node*)malloc(sizeof(Node));
    root->left->left->right=(Node*)malloc(sizeof(Node));
    root->left->right->left=(Node*)malloc(sizeof(Node));
    root->left->right->right=(Node*)malloc(sizeof(Node));
    root->right->left->left=(Node*)malloc(sizeof(Node));
    root->right->left->right=(Node*)malloc(sizeof(Node));
    root->right->right->left=(Node*)malloc(sizeof(Node));
    root->right->right->right=(Node*)malloc(sizeof(Node));

    root->left->left->left->left=(Node*)malloc(sizeof(Node));
    root->left->left->left->right=(Node*)malloc(sizeof(Node));
    root->left->left->right->left=(Node*)malloc(sizeof(Node));
    root->left->left->right->right=(Node*)malloc(sizeof(Node));
    root->left->right->left->left=(Node*)malloc(sizeof(Node));
    root->left->right->left->right=(Node*)malloc(sizeof(Node));
    root->left->right->right->left=(Node*)malloc(sizeof(Node));
    root->left->right->right->right=(Node*)malloc(sizeof(Node));
    root->right->left->left->left=(Node*)malloc(sizeof(Node));
    root->right->left->left->right=(Node*)malloc(sizeof(Node));
    root->right->left->right->left=(Node*)malloc(sizeof(Node));
    root->right->left->right->right=(Node*)malloc(sizeof(Node));
    root->right->right->left->left=(Node*)malloc(sizeof(Node));
    root->right->right->left->right=(Node*)malloc(sizeof(Node));
    root->right->right->right->left=(Node*)malloc(sizeof(Node));
    root->right->right->right->right=(Node*)malloc(sizeof(Node));

    root->left->left->left->left->left=NULL;
    root->left->left->left->right->left=NULL;
    root->left->left->right->left->left=NULL;
    root->left->left->right->right->left=NULL;
    root->left->right->left->left->left=NULL;
    root->left->right->left->right->left=NULL;
    root->left->right->right->left->left=NULL;
    root->left->right->right->right->left=NULL;
    root->right->left->left->left->left=NULL;
    root->right->left->left->right->left=NULL;
    root->right->left->right->left->left=NULL;
    root->right->left->right->right->left=NULL;
    root->right->right->left->left->left=NULL;
    root->right->right->left->right->left=NULL;
    root->right->right->right->left->left=NULL;
    root->right->right->right->right->left=NULL;

    root->left->left->left->left->right=NULL;
    root->left->left->left->right->right=NULL;
    root->left->left->right->left->right=NULL;
    root->left->left->right->right->right=NULL;
    root->left->right->left->left->right=NULL;
    root->left->right->left->right->right=NULL;
    root->left->right->right->left->right=NULL;
    root->left->right->right->right->right=NULL;
    root->right->left->left->left->right=NULL;
    root->right->left->left->right->right=NULL;
    root->right->left->right->left->right=NULL;
    root->right->left->right->right->right=NULL;
    root->right->right->left->left->right=NULL;
    root->right->right->left->right->right=NULL;
    root->right->right->right->left->right=NULL;
    root->right->right->right->right->right=NULL;


    //Fill the tree with English Letter Characters
    root->left->c = 'E';
    root->right->c = 'T';

    root->left->left->c = 'I';
    root->left->right->c = 'A';
    root->right->left->c = 'N';
    root->right->right->c = 'M';

    root->left->left->left->c = 'S';
    root->left->left->right->c = 'U';
    root->left->right->left->c = 'R';
    root->left->right->right->c = 'W';
    root->right->left->left->c = 'D';
    root->right->left->right->c = 'K';
    root->right->right->left->c = 'G';
    root->right->right->right->c = 'O';

    root->left->left->left->left->c = 'H';
    root->left->left->left->right->c = 'V';
    root->left->left->right->left->c = 'F';
    root->left->left->right->right->c = ' ';
    root->left->right->left->left->c = 'L';
    root->left->right->left->right->c = ' ';
    root->left->right->right->left->c = 'P';
    root->left->right->right->right->c = 'J';
    root->right->left->left->left->c = 'B';
    root->right->left->left->right->c = 'X';
    root->right->left->right->left->c = 'C';
    root->right->left->right->right->c = 'Y';
    root->right->right->left->left->c = 'Z';
    root->right->right->left->right->c = 'Q';
    root->right->right->right->left->c = ' ';
    root->right->right->right->right->c = ' ';
    return root;
}

void destroyTree(Node *root)
{
    if(root==NULL)
        return;
    destroyTree(root->left);
    destroyTree(root->right);
    free(root);
}

void destroySLL(english *head)
{
    while(head != NULL)
    {
        english *temp = head;
        head = head->next;
        free(temp);
    }
    free(head);
}

void destroyDLL(morse *head)
{
    while(head != NULL)
    {
        morse *temp = head;
        head = head->next;
        free(temp);
    }
    free(head);
}

#endif // STRUCTURES_H_INCLUDED
