
void Invert(QUEUE *Q)
{
    elementtype temp;
    temp = QuFront(*Q);
    QuDequeue(Q);
    if (!QuEmpty(*Q))
        Invert(Q)
    QuEnqueue (temp, Q);
}
