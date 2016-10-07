#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    char slova[20];    
    int last;
} List;

typedef int position;

position LiEnd (List L)
{
    return (L.last + 1);
}

position LiMakeNull (List *Lp)
{
    Lp->last = -1;
    return 0;
}

void LiInsert (char x, position p, List *Lp) 
{
    position q;
    if (Lp->last >= 20-1)
        exit(101);
    else if ( (p > Lp->last+1 ) || ( p < 0 ) )
        exit(102);
    else
    {
        for (q = Lp->last; q >= p; q--)
            Lp->slova[q+1] = Lp->slova[q];
        Lp->last++;
        Lp->slova[p] = x;
    }
}

void LiDelete (position p, List *Lp)
{
    position q;
    if ( (p > Lp->last ) || (p < 0) )
        exit(102);
    else
    {
        Lp->last--;
        for (q = p; q <= Lp->last; q++)
            Lp->slova[q] = Lp->slova[q+1];
    }
}




int main(void)
{
    int m, i=2, j=0, k;
    List L;
    char string[250];
    gets(string);
    m = string[0];
    k = 0;
    while (string[i] != '\n')
    {
        if (string[i] != '\0')
            L.slova[k] = 1;
        else
        {
            j++;
            k=0;
        }
        i++;
    }
    
    printf ("%s", string);
    
    return 0;
}
