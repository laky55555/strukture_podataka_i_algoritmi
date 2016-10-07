/*U kontekstu atp. Stack napiˇsite potprogram void InsertSecond (elementtype x, Stack *Sp) koji
ubacuje element x u stog *Sp, tako da x bude drugi element odozdo (tj. drugi element od dna stoga).
Medusobni redoslijed ostalih elemenata ostaje nepromijenjen. Potprogram treba biti neovisan o implementaciji
atp. Stack. Pokuˇsajte napisati potprogram tako da ne koristite dodatna polja ni atp-ove (ako
ne ide, smijete uvesti joˇs jedan dodatni atp po volji, ali ne i polje).*/
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
void InsertSecond (int a, Stack *S)
{
    int temp;
    temp=StTop(*S);
    StPop(S);
    if(StEmpty(*S))
    {

        StPush(temp,S);
        StPush(a,S);
    }
    else
    {
        InsertSecond(a,S);
        StPush(temp, S);
    }
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
    InsertSecond(0,&s1);
    printf ("\nodluka\n");
    ispis(s1);
    return 0;
}
