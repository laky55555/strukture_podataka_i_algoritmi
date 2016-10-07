
double trag (Queue Q)
{
    Stack pomocni;
    int n=0, brojac=0;
    double x,suma=0;
    StMakeNull(&pomocni)
    while(!QuEmpty(Q))
    {
        x = QuFront(Q);
        StPush(x, &pomocni);
        QuDequeue(&Q);
        n++;
    }
    n = sqrt(n);
    while (!StEmpty(pomocni))
    {
        if (brojac%(n+1)==0)
            suma += StTop(pomocni);
        brojac++;
        StPop(&pomocni);
    }
    return suma;
}

void transpose (queue *Q, int n)
{
    Stack pomocni;
    int i, j, brojac, brojac2=0;
    double x;
    for (i=n; i>=1; i--)
    {
        brojac=0;
        for (j=0; j<(n*n)-(n*brojac2); j++)
        {
            x = QuFront(*Q);
            if (brojac%i==0)
                StPush(x, &pomocni);
            else
                QuEngueue (x,Q);
            QuDequeue (Q);
            brojac++;
        }
        brojac2++;
    }
    while(!StEmpty(pomocni))
    {
        EnQueue(StTop(pomocni), Q);
        StPop(&pomocni);
    }
    while (!=QuEmpty(*Q))
    {
        StPush(QuFront(*Q), &pomocni)
        DeQueue (Q);
    }
    while(!StEmpty(pomocni))
    {
        EnQueue(StTop(pomocni), Q);
        StPop(&pomocni);
    }
}
