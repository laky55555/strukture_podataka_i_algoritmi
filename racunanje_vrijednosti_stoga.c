#include <stdio.h>
#include <stack>


float zbroj_u_stogu (stack *S)
{
    float suma, vrh;
    if (is_empty(S) == 1)
        return 0;
    else
    {
        vrh = st_top(S);
        st_pop(&S);
        suma = zbroj_u_stogu (&S);
        suma += vrh;
        st_push(&S, vrh);
        return suma;
    }
}


int main (void)
{
    stack A;
    float zbroj;
    zbroj = zbroj_u_stogu(&A);


    return 0;
}
