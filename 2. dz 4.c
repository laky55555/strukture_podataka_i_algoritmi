#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct
{
    char slova[200];    
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



typedef struct
{
    int a;
    char b;
} par;

typedef struct 
{
  par elements[11];
  int last;
} PriorityQueue;

void PrMakeNull(PriorityQueue *Ap)
{
    Ap->last = -1;
}

int PrEmpty(PriorityQueue A) 
{
    if (A.last == -1)
        return 1;
    else
        return 0;
}

void PrInsert (par x, PriorityQueue *Ap) 
{
    int i;
    par temp;
    if ( Ap->last >= 10 )
        exit(801); /* prioritetni red se prepunio */
    else
    {
        (Ap->last)++;
        Ap->elements[Ap->last] = x; /* novi ¡cvor s elementom x */
        i = Ap->last; /* i je indeks ¡cvora u kojem je x */
        while ( (i>0) && (Ap->elements[i].b > Ap->elements[(i-1)/2].b) ) 
        {
            /* operator && u jeziku C je kondicionalan! */
            temp = Ap->elements[i];
            Ap->elements[i] = Ap->elements[(i-1)/2];
            Ap->elements[(i-1)/2] = temp;
            i = (i-1)/2;
        }
    }
}

par PrDeleteMin (PriorityQueue *Ap) 
{
    int i, j;
    par minel, temp;
    if ( Ap->last < 0 )
        exit(802); /* prioritetni red je prazan */
    else 
    {
        minel = Ap->elements[0]; /* najmanji element je u korijenu */
        Ap->elements[0] = Ap->elements[Ap->last];
        /* vrijednost iz zadnjeg ¡cvora prepisuje se u korijen */
        (Ap->last)--; /* izbacujemo zadnji ¡cvor */
        i = 0;
        /* i je indeks ¡cvora gdje se nalazi element iz izba¡cenog ¡cvora */
        while ( i <= (Ap->last+1)/2-1 ) 
        {
            /* mi¡cemo element u ¡cvoru i prema dolje */
            if ((2*i+1==Ap->last) || (Ap->elements[2*i+1].b >= Ap->elements[2*i+2].b ))
                j = 2*i+1;
            else
                j = 2*i+2; /* j je dijete od i koje sadr¡zi manji element */
            if ( Ap->elements[i].b <= Ap->elements[j].b ) 
            {
                /* zamijeni elemente iz ¡cvorova i,j */
                temp = Ap->elements[i];
                Ap->elements[i] = Ap->elements[j];
                Ap->elements[j] = temp;
                i = j;
            }
            else
            return(minel); /* ne treba dalje pomicati */
        }
        return(minel); /* pomicanje je do¡slo sve do lista */
    }
}




int main(void)
{
    PriorityQueue Hrpa;
    par x;
    int m, i=2, j=0, k,z;
    List L[20], konacna;
    char string[250];
    gets(string);
    m = string[0] - '0';
    for (z=0; z<m; z++)
    LiMakeNull(&L[z]);
    PrMakeNull(&Hrpa);
    LiMakeNull(&konacna);
    k = 0;
    while (string[i] != '\0')
    {
        if (isblank(string[i]))
        {
            j++;
            k=0;
            i++;
            continue;
        }
        else
            LiInsert(string[i], k, &L[j]);
        k++;
        i++;
    }

    
    for (i=0; i<m; i++)
    {
        printf("ubacujem %c iz liste %d\n", L[i].slova[0], i+1);
        x.a = i; x.b = L[i].slova[0];
        LiDelete(0, &L[i]);
        PrInsert(x, &Hrpa);
    }
    i=0;
    while (1)
    {
        x = PrDeleteMin(&Hrpa);
        printf("izbacujem %c iz liste %d\n", x.b, x.a+1);
        konacna.slova[i] = x.b;
        if (LiEnd(L[x.a]) > 0)
        {
            x.b = L[x.a].slova[0];
            LiDelete(0, &L[x.a]);
            PrInsert(x, &Hrpa);
            printf("ubacujem %c iz liste %d\n", x.b, x.a+1);
        }
        i++;
        if (Hrpa.last < 0)
            break;
    }
    for (j=0; j<i; j++)
        printf ("%c", konacna.slova[j]);
    return 0;
}
