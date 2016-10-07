
void Eliminate (List *Lp, elementtype x)
{
    position p,q;
    p = LiFirst(*Lp);
    while (p != LiEnd(*Lp))
    {
        if (x < LiRetrive(p, *Lp))
        {
            q = p;   
            LiDelete(q, *Lp);
        }
        p = LiNext(p, *Lp);
    }
}
