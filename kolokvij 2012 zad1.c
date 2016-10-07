#include <stdio.h>

typedef struct
{
    int top;
    int polje[6];
}Stack;


int StEmpty (Stack S)
{
    if(S.top==6)return 1;
    return 0;
}
int StTop (Stack S)
{
    return S.polje[S.top];
}
void StPop (Stack *s)
{
    s->top++;
}
void StPush (int broj, Stack *s)
{
    s->top--;
    s->polje[s->top]=broj;
}

void ispis (Stack s)
{
    int i;
    for(i=5;i>=s.top;i--)printf ("%d ", s.polje[i]);
    printf ("\n");
}


void PushBottom (int x, Stack *S)
{
    int temp;
    temp = StTop(*S);
    StPop(S);
    if (StEmpty(*S))
        StPush(x, S);
    else
        PushBottom(x, S);
    StPush(temp, S);
}
void StMakeNull (Stack *s)
{
    s->top=6;
}
int main()
{
    Stack s1;
    int temp, i;
    StMakeNull(&s1);
    printf ("upsite stog\n");
    for(i=0;i<5;i++)
    {
        scanf("%d", &temp);
        StPush(temp,&s1);
    }
    printf ("ispis stoga od dna prema gore\n");
    ispis (s1);
    PushBottom(0,&s1);
    printf ("\nodluka\n");
    ispis(s1);
    return 0;
}

