#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define elementtype char
#define labeltype char
#define LAMBDA NULL
    typedef struct celltag1
    {
        elementtype element;
        struct celltag1 *next;
    } celltype1;

    typedef struct _cell
    {
    labeltype label;
    struct _cell *leftchild, *rightchild;
    } celltype;

    typedef celltype *node;
    typedef celltype *BinaryTree;
    typedef celltype1 *List;
    typedef celltype1 *position;


void BiMakeNull (BinaryTree*);
int BiEmpty (BinaryTree);
void BiCreate (labeltype, BinaryTree, BinaryTree, BinaryTree*);
node kopiraj (BinaryTree);
void BiLeftSubtree (BinaryTree, BinaryTree*);
void BiRightSubtree (BinaryTree, BinaryTree*);
node BiInsertLeftChild (labeltype, node, BinaryTree*);
node BiInsertRigthChild (labeltype, node, BinaryTree*);
void BiDelete (node, BinaryTree*);
node BiRoot (BinaryTree);
node BiLeftChild (node, BinaryTree);
node BiRightChild (node, BinaryTree);
void roditelj (node*, node, node);
node BiParent(node, BinaryTree);
labeltype BiLabel(node, BinaryTree);
void BiChangeLabel(labeltype, node, BinaryTree*);


    position LiEnd(List L)
    {
        position q;
        q = L;
        while (q->next != NULL)
            q = q->next;
        return q;
    }

    int jesuma(int n)
    {
    int i=2; int k=2;
    for(i=2;i<n;k=2*k){
        i=i+k;
        }
    if(i==n)return 1;
            else return 0;
    }

    position LiMakeNull(List *Lp)
    {
        *Lp = (celltype1*)malloc(sizeof(celltype1));
        (*Lp)->next = NULL;
        return (*Lp);
    }

    void LiInsert(elementtype x, position p, List *Lp)
    {
        position temp;
        temp = p->next;
        p->next = (celltype1*)malloc(sizeof(celltype1));
        p->next->element = x;
        p->next->next = temp;
    }

    void LiDelete(position p, List *Lp)
    {
        position temp;
        temp = p->next;
        p->next = p->next->next;
        free(temp);
    }

    position LiFirst(List L)
    {
        return L;
    }

    position LiNext(position p, List L)
    {
        if (p->next == NULL)
            exit(102);
        return (p->next);
    }

    position LiPrevious(position p, List L)
    {
        position q;
        for (q = L; q->next != p; q = q->next);
        return q;
    }

    elementtype LiRetrieve(position p, List L)
    {
        return p->next->element;
    }

    void LiPrint(List L)
    {
        printf("\n");
        position p = LiFirst(L);

        while (p != LiEnd(L))
        {
            printf("%c ", LiRetrieve(p, L));
            p = LiNext(p, L);
        }
        printf("\n");
    }


    void BiMakeNull(BinaryTree *Tp)
    {
        *Tp = NULL;
    }

    int BiEmpty(BinaryTree T)
    {
        if (T)
            return 0;
        return 1;
    }

    void BiCreate(labeltype l, BinaryTree TL, BinaryTree TR, BinaryTree *Tp)
    {
        *Tp = (celltype*)malloc(sizeof(celltype));
        (*Tp)->label = l;
        (*Tp)->leftchild = TL;
        (*Tp)->rightchild = TR;
    }

    BinaryTree copy(BinaryTree T)
    {
        BinaryTree B, BL, BR;

        BiMakeNull(&B);
        BiMakeNull(&BL);
        BiMakeNull(&BR);

        if (T == NULL)
            return B;

        if (T->leftchild == NULL && T->rightchild == NULL)
        {
            BiCreate(T->label, BL, BR, &B);
            return B;
        }

        BL = copy(T->leftchild);
        BR = copy(T->rightchild);
        BiCreate(T->label, BL, BR, &B);

        return B;
    }

    void BiLeftSubtree(BinaryTree T, BinaryTree *TL)
    {
        *TL = copy(T->leftchild);
    }

    void BiRightSubtree(BinaryTree T, BinaryTree *TR)
    {
        *TR = copy(T->rightchild);
    }

    node BiInsertLeftChild(labeltype l, node i, BinaryTree *Tp)
    {
        if (!i)
        {
            printf("Taj cvor ne postoji.");
            exit(1);
        }

        if (i->leftchild != NULL)
        {
            printf("Taj cvor vec ima lijevo dijete.");
            exit(2);
        }

        if (!(i->leftchild = (celltype*)malloc(sizeof(celltype))))
        {
            printf("Nema dovoljno memorije.");
            exit(3);
        }

        i->leftchild->label = l;
        i->leftchild->leftchild = i->leftchild->rightchild = NULL;

        return i->leftchild;
    }

    node BiInsertRightChild(labeltype l, node i, BinaryTree *Tp)
    {
        if (!i)
        {
            printf("Taj cvor ne postoji.");
            exit(1);
        }

        if (i->rightchild != NULL)
        {
            printf("Taj cvor vec ima desno dijete.");
            exit(2);
        }

        if (!(i->rightchild = (celltype*)malloc(sizeof(celltype))))
        {
            printf("Nema dovoljno memorije.");
            exit(3);
        }

        i->rightchild->label = l;
        i->rightchild->leftchild = i->rightchild->rightchild = NULL;

        return i->rightchild;
    }

    void roditelj(node *parent, node i, node root)
    {
        if ((root->leftchild == i) || (root->rightchild == i))
            *parent = root;

        if (*parent)
            return;

        if (root->leftchild)
            roditelj(parent, i, root->leftchild);

        if (root->rightchild)
            roditelj(parent, i, root->rightchild);
    }

    node BiParent(node i, BinaryTree T)
    {
        if (!i)
        {
            printf("Taj cvor ne postoji.");
            exit(1);
        }

        if (i == T)
            return NULL;

        node parent = NULL;
        roditelj(&parent, i, T);
        return parent;
    }

    node BiRoot(BinaryTree T)
    {
        return T;
    }

    node BiLeftChild(node i, BinaryTree T)
    {
        if (!i)
        {
            return LAMBDA;
        }

        if (i->leftchild == NULL)
            return LAMBDA;

        return i->leftchild;
    }

    node BiRightChild(node i, BinaryTree T)
    {
        if (!i)
        {
            return LAMBDA;
        }

        if (i->rightchild == NULL)
            return LAMBDA;

        return i->rightchild;
    }

    void BiDelete(node i, BinaryTree *Tp)
    {
        if (!i)
        {
            printf("Taj cvor ne postoji.");
            exit(1);
        }

        if (i->leftchild || i->rightchild)
        {
            printf("Taj cvor ima dijete te ga nije moguce obrisati.");
            exit(4);
        }

        node p = BiParent(i, *Tp);

        if (p == LAMBDA)
        {
            free(i);
            return;
        }

        if (BiLeftChild(p, *Tp) == i)
            p->leftchild = NULL;
        else
            p->rightchild = NULL;

        free(i);
    }

    labeltype BiLabel(node i, BinaryTree T)
    {
        if (!i)
        {
            return 'L';
        }

        return i->label;
    }

    void BiChangeLabel(labeltype l, node i, BinaryTree *Tp)
    {
        if (!i)
        {
            printf("Taj cvor ne postoji.");
            exit(1);
        }

        i->label = l;
    }


    void preorder(BinaryTree p)
    {
    if(p==NULL)
    {
        printf("Prazna lista\n");
        return;
    }

    printf("%c ",p->label);
    if (p->leftchild) preorder(p->leftchild);
    if (p->rightchild) preorder(p->rightchild);
    }

    int prebroji(BinaryTree p)
    {
    if(p==NULL)return 0;
    if(p-> leftchild == NULL && p->rightchild== NULL )return 1;
    if (p->leftchild == NULL ) return prebroji(p->rightchild)+1;
    if (p->rightchild == NULL ) return prebroji(p->leftchild)+1;
    return ( prebroji(p->rightchild)+prebroji(p->leftchild)+1 );
    }

    node HeapDodaj(BinaryTree *Hrpa, node tren, labeltype k)
    {
        BinaryTree L,R;
        node zadnji;

        if( BiLeftChild( tren, *Hrpa ) ==NULL  )
            {
              /*  printf("\n*uspjesno insertan lijevo*\n");
                printf("kao dijete slova: %d",BiLabel(tren,*Hrpa));*/
                zadnji=BiInsertLeftChild ( k , tren, Hrpa);
                return zadnji;
            }

        if( BiRightChild( tren, *Hrpa )==NULL  )
            {
               /* printf("\n*uspjesno insertan desno*\n");
                printf("kao dijete slova: %d",BiLabel(tren,*Hrpa));*/
                zadnji=BiInsertRightChild ( k , tren, Hrpa);
                return zadnji;
            }

        BiLeftSubtree(tren,&L);
        BiRightSubtree(tren,&R);
        if ( prebroji(L) == prebroji (R) ) return HeapDodaj(&L,BiLeftChild(tren,*Hrpa),k);
        if ( jesuma(prebroji(L)+1) ) return HeapDodaj(&R, BiRightChild(tren,*Hrpa),k);
        return HeapDodaj(&L, BiLeftChild(tren,*Hrpa),k);
    }

    void LabelSwap ( node i , node j , BinaryTree *T)
    {
    labeltype temp;
    labeltype a,b;
    a=BiLabel ( i, *T);
    b=BiLabel ( j, *T);
        if ( a > b )
        {
            temp = BiLabel (i, *T);
            BiChangeLabel ( BiLabel (j,*T) , i , T );
            BiChangeLabel ( temp, j , T );
            if (BiParent (j,*T) == NULL )return;
            LabelSwap ( j, BiParent(j, *T),  T );
        }

    }

    void HeapAdd(BinaryTree *Hrpa, labeltype k)
    {
    node zadnji;
    zadnji = HeapDodaj(Hrpa, *Hrpa, k);
    /*if(BiParent(zadnji,*Hrpa)==NULL){printf("Bananaaaaaaaa");return;}
    printf("\ntreba-");*/
    LabelSwap (zadnji, BiParent (zadnji,*Hrpa), Hrpa  );
    }

    node nadjizadnji(BinaryTree *Hrpa, node tren)
    {
        BinaryTree L,R;
        node zadnji;

        if( BiLeftChild( tren, *Hrpa ) ==NULL && BiRightChild(tren, *Hrpa)== NULL  )
            {
                return tren;
            }


        BiLeftSubtree(tren,&L);
        BiRightSubtree(tren,&R);

        if( BiRightChild( tren, *Hrpa )==NULL  )return nadjizadnji(&L,BiLeftChild(tren,*Hrpa));
        if ( prebroji(L) == prebroji (R) ) return nadjizadnji(&R,BiRightChild(tren,*Hrpa));
       /*if ( jesuma(prebroji(R)+1 ) && jesuma(prebroji(L)+1) ) return nadjizadnji(&L, BiLeftChild(tren,*Hrpa));*/
        if( jesuma(prebroji (R)+1 ) ) return nadjizadnji (&L, BiLeftChild(tren,*Hrpa));
        return nadjizadnji(&R, BiRightChild(tren,*Hrpa));
    }

        void sortiraj ( BinaryTree *T)
        {
        labeltype temp;
        labeltype a,b;
        node L;
        if( BiLeftChild(*T,*T)==NULL && BiRightChild(*T,*T)==NULL )return;


                            if (BiLeftChild(*T,*T )!= NULL && BiRightChild (*T,*T)!= NULL)
                            {
                                a=BiLabel ( BiLeftChild(*T,*T),  *T);
                                b=BiLabel ( BiRightChild(*T,*T),  *T);
                                if (a>=b)
                                {
                                              if ( a > BiLabel( *T,*T) )
                                                    {
                                                    temp = BiLabel (*T, *T);
                                                    BiChangeLabel ( a , *T, T );
                                                    BiChangeLabel ( temp, BiLeftChild(*T,*T) , T );
                                                    L=BiLeftChild( *T, *T);
                                                    sortiraj (&L);
                                                    /*BiLeftSubtree(*T,&K);
                                                    sortiraj (&K);*/
                                                    }
                                }
                                 else
                                 {
                                                    if ( b > BiLabel( *T,*T) )
                                                    {
                                                    temp = BiLabel (*T, *T);
                                                    BiChangeLabel ( b , *T, T );
                                                    BiChangeLabel ( temp, BiRightChild(*T,*T) , T );
                                                    L=BiRightChild( *T, *T);
                                                    sortiraj (&L);
                                                    /*BiRightSubtree(*T,&K);
                                                    sortiraj ( &K);*/
                                                    }
                                 }
                            return;
                            }

                if(BiLeftChild(*T,*T) != NULL )
                    {
                    a=BiLabel ( BiLeftChild(*T,*T),  *T);
                            if ( a > BiLabel( *T,*T) )
                            {
                            temp = BiLabel (*T, *T);
                            BiChangeLabel ( a , *T, T );
                            BiChangeLabel ( temp, BiLeftChild(*T,*T) , T );
                            L=BiLeftChild( *T, *T);
                            sortiraj (&L);
                            /*BiLeftSubtree(*T,&K);
                            sortiraj (&K);*/
                            }
                    }

                if(BiRightChild(*T,*T) != NULL )
                    {
                    b=BiLabel ( BiRightChild(*T,*T),  *T);
                            if ( b > BiLabel( *T,*T) )
                            {
                            temp = BiLabel (*T, *T);
                            BiChangeLabel ( b , *T, T );
                            BiChangeLabel ( temp, BiRightChild(*T,*T) , T );
                            L=BiLeftChild( *T, *T);
                            sortiraj (&L);
                            /*BiRightSubtree(*T,&K);
                            sortiraj ( &K);*/
                            }
                    }

        }




    labeltype HeapDelMax(BinaryTree *Hrpa)
    {
        node zadnji;
        labeltype vracaj;
        zadnji = nadjizadnji ( Hrpa, *Hrpa );
        vracaj=BiLabel(*Hrpa,*Hrpa);
        BiChangeLabel ( BiLabel(zadnji, *Hrpa) , *Hrpa, Hrpa );
        if(BiRoot(*Hrpa) != zadnji)
        {
        BiDelete(zadnji,Hrpa);
        /*printf ( " -> preorder prije sorta: ");
        preorder(*Hrpa);*/
        sortiraj(Hrpa);
        }
        else BiMakeNull(Hrpa);
        return vracaj;
    }


    void HeapSort(List *L, int n)
    {
    position p =LiFirst(*L);
    elementtype k;
    BinaryTree Hrpa;
    BiMakeNull (&Hrpa);
    p=*L;
        printf("\n");
        printf("Ubacujem %c", LiRetrieve( p,*L) );
        k=LiRetrieve (p, *L);
        BiCreate( k, NULL, NULL, &Hrpa);
        p = LiNext( p, *L );
        printf ( " -> preorder: ");
        preorder(Hrpa);
        printf("\n");
        while( p != LiEnd( *L ) )
        {
        printf("\nUbacujem %c", LiRetrieve( p,*L) );
        k=LiRetrieve ( p , *L );
        HeapAdd(&Hrpa, k);
        printf ( " -> preorder: ");
        preorder(Hrpa);
        printf("\n");
         p = LiNext( p, *L );
        }

        p=*L;
        while(p !=LiEnd(*L) )
        {
        printf("\nBrisem najveceg to je %c", BiLabel(BiRoot(Hrpa), Hrpa));
        k=HeapDelMax(&Hrpa);
        LiDelete(p,L);
        LiInsert(k,p,L);
        printf ( " -> preorder: ");
        preorder(Hrpa);
        printf("\n");
        p = LiNext( p, *L );
        }
    }






int main(void)
{
    int n=0;
    elementtype temp;
    List L1,L2;
    position p;

   /* printf("Upisite broj clanova liste:\n");
    scanf("%d",&broj);

    printf("Upisite clanove liste:\n");
    */

    L1=LiMakeNull(&L1);
    p=L1;

    while(1)
    {
        scanf(" %c",&temp);
        if(temp=='0')break;
        n++;
        LiInsert(temp,p,&L1);
        p=LiNext(p,L1);
    }

    HeapSort(&L1, n);

    printf("\n\nSortirana lista:\n ****");
    LiPrint(L1);
    printf(" **** \n ");


    return 0;


}
