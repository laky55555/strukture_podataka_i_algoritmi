#include <stdio.h>
#include <queue.h>

int SQ (Queue *Qp)
{
    Queue pomocni;
    elementtype x;
    int brojelemenata, i, j, duplikat;
    QuMakeNull(&pom);
    while (!=QuEmpty(*Qp))
    {
        x = QuFront(*Qp);
        QuDequeue (*Qp);
        QuEnqueue (x, &pomocni);
        brojelemenata++;
    }
    for (j=0; j<n; j++)
    {
        x = QuFront(pomocni);
        QuDequeue (*Qp);
        QuEnqueue (x, &pomocni);
        if ()
    }
}
