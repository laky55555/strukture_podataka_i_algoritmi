
typedef struct{
    int *element;
    int top, alocirano;
} Stack;    

void StMakeNull(Stack *S)
{
    S->alocirano = S->top = 0;
    S->element = NULL;
}

void StPush(int x, Stack *S)
{
    if (S->alocirano == S->top)
    {
        S->element = (int *)realloc(S->element,sizeof(int)*(S->alocirano + 10));
        if (S->element == NULL)
            printf ("Nema mjesta");
        S->alocirano += 10;
    }
    S->element[S->top] = x;
    S->top++;
}

void StPop (Stack *S)
{
    if(StEmpty(*S))
        printf ("Stog je prazan");
    S->top--;
    if (S->alocirano - S->top > 10)
    {
        S->element = (int *)realloc(S->element,sizeof(int)*(S->alocirano - 10));
        if (S->element = NULL)
            printf ("Nema mjesta");
        S->alocirano -= 10
    }
}



