#include<stdio.h>
#include<stdlib.h>

typedef struct celltag{
    char element;
    struct celltag *next;
} celltype;

typedef celltype *Stack;

void StMakeNull (Stack *Sp)
{
    *Sp = NULL;
}

int StEmpty (Stack S)
{
    if (S == NULL)
        return 1;
    else
        return 0;
}

void StPush (char x, Stack *Sp)
{
    celltype *temp;
    temp = *Sp;
    *Sp = (celltype*)malloc(sizeof(celltype));
    (*Sp)->element = x;
    (*Sp)->next = temp;
}

void StPop (Stack *Sp)
{
    Stack temp;
    if (StEmpty(*Sp))
        exit(202);
    else
    {
        temp = *Sp;
        *Sp = (*Sp)->next;
        free(temp);
    }
}

char StTop (Stack S)
{
    if (StEmpty(S))
        exit(202);
    else
        return (S->element);
}

int operat (char x)
{
    if (x == '*' || x == '/' || x == '+' || x == '-' || x == '^' || x == '(' || x == ')')
        return 1;
    return 0;
}

int veci_jednak (char x, Stack S)
{
    char y;
    if(StEmpty(S))
        return 0;
    y = StTop(S);
    if (x=='(')
        return 0;
    else if (x == '+' || x == '-')
    {
        if (y == '(')
            return 0;
        return 1;
    }
    else if (x == '*' || x == '/')
    {
        if (y == '(' || y == '+' || y == '-')
            return 0;
        return 1;
    }
    else if (x == '^')
    {
        if (y == '^')
            return 1;
        return 0;
    }
    return 0;
}


int main (void)
{
    Stack stog;
    char string[100];
    int i=0;
    StMakeNull(&stog);
    scanf("%[^\n]", string);
    while (string[i]!='\0')
    {
        if (!operat(string[i]))
            printf("%c", string[i]);
        else if (string[i] == ')')
        {
            while(StTop(stog) != '(')
            {
                printf ("%c", StTop(stog));
                StPop(&stog);
            }
            StPop(&stog);
        }
        else
        {
            while(veci_jednak(string[i], stog))
            {
                printf ("%c", StTop(stog));
                StPop(&stog);
            }
            StPush(string[i], &stog);
        }
        i++;
    }
    while(!StEmpty(stog))
    {
        printf("%c", StTop(stog));
        StPop(&stog);
    }

    free (stog);
    return 0;
}
