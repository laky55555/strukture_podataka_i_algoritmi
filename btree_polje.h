#define MAXLENGTH 1023
#define PRAZNO -1
#define node int
#define LAMBDA -1

typedef struct {
  labeltype labels[MAXLENGTH];
} BTREE;

void MAKE_NULL(BTREE *);
int EMPTY(BTREE);
void kopiraj_stablo(BTREE, BTREE *, node, node);
node CREATE(labeltype, BTREE, BTREE, BTREE *);
void LEFT_SUBTREE(BTREE, BTREE *);
void RIGHT_SUBTREE(BTREE, BTREE *);
node INSERT_LEFT_CHILD(labeltype, node, BTREE *);
node INSERT_RIGHT_CHILD(labeltype, node, BTREE *);
void DELETE(node, BTREE *);
node ROOT(BTREE);
node LEFT_CHILD(node, BTREE);
node RIGHT_CHILD(node, BTREE);
node PARENT(node, BTREE);
labeltype LABEL(node, BTREE);
void CHANGE_LABEL(labeltype, node, BTREE *);

void MAKE_NULL(BTREE *T) {
  int i;
  for (i = 0; i < MAXLENGTH; ++i)
    T->labels[i] = PRAZNO;
}

int EMPTY(BTREE T) {
  return T.labels[0] == PRAZNO;
}

void kopiraj_stablo(BTREE T1, BTREE *T2, node i, node j) {
  MAKE_NULL(T2);
  if (i < 0 || i >= MAXLENGTH || T1.labels[i] == PRAZNO)
    return;
  if (j < 0 || j >= MAXLENGTH)
    return;
  T2->labels[j] = T1.labels[i];
  kopiraj_stablo(T1, T2, 2 * i + 1, 2 * j + 1);
  kopiraj_stablo(T1, T2, 2 * i + 2, 2 * j + 2);
}

node CREATE(labeltype l, BTREE TL, BTREE TR, BTREE *T) {
  T->labels[0] = l;
  kopiraj_stablo(TL, T, 0, 1);
  kopiraj_stablo(TR, T, 0, 2);
  return 0;
}

void LEFT_SUBTREE(BTREE T, BTREE *TL) {
  kopiraj_stablo(T, TL, 1, 0);
}

void RIGHT_SUBTREE(BTREE T, BTREE *TR) {
  kopiraj_stablo(T, TR, 2, 0);
}

node INSERT_LEFT_CHILD(labeltype l, node i, BTREE *T) {
  if (i < 0 || i >= MAXLENGTH || T->labels[i] == PRAZNO) {
    printf("INSERT_LEFT_CHILD: Ne postoji taj cvor.");
    exit(1);
  }
  if (2 * i + 1 >= MAXLENGTH) {
    printf("INSERT_LEFT_CHILD: Ne mogu dodati lijevo dijete.");
    exit(1);
  }
  T->labels[2 * i + 1] = l;
  return 2 * i + 1;
}

node INSERT_RIGHT_CHILD(labeltype l, node i, BTREE *T) {
  if (i < 0 || i >= MAXLENGTH || T->labels[i] == PRAZNO) {
    printf("INSERT_RIGHT_CHILD: Ne postoji taj cvor.");
    exit(1);
  }
  if (2 * i + 2 >= MAXLENGTH) {
    printf("INSERT_RIGHT_CHILD: Ne mogu dodati desno dijete.");
    exit(1);
  }
  T->labels[2 * i + 2] = l;
  return 2 * i + 2;
}

void DELETE(node i, BTREE *T) {
  if (i < 0 || i >= MAXLENGTH || T->labels[i] == PRAZNO) {
    printf("DELETE: Ne postoji taj cvor.");
    exit(1);
  }
  if (2 * i + 1 < MAXLENGTH && T->labels[2 * i + 1] != PRAZNO) {
    printf("DELETE: Cvor ima dijete.");
    exit(1);
  }
  if (2 * i + 2 < MAXLENGTH && T->labels[2 * i + 2] != PRAZNO) {
    printf("DELETE: Cvor ima dijete.");
    exit(1);
  }
  T->labels[i] = PRAZNO;
}

node ROOT(BTREE T) {
  if (T.labels[0] == PRAZNO)
    return LAMBDA;
  return 0;
}

node LEFT_CHILD(node i, BTREE T) {
  if (i < 0 || i >= MAXLENGTH || T.labels[i] == PRAZNO) {
    printf("LEFT_CHILD: Ne postoji taj cvor.");
    exit(1);
  }
  if (2 * i + 1 >= MAXLENGTH || T.labels[2 * i + 1] == PRAZNO)
    return LAMBDA;
  return 2 * i + 1;
}

node RIGHT_CHILD(node i, BTREE T) {
  if (i < 0 || i >= MAXLENGTH || T.labels[i] == PRAZNO) {
    printf("RIGHT_CHILD: Ne postoji taj cvor.");
    exit(1);
  }
  if (2 * i + 2 >= MAXLENGTH || T.labels[2 * i + 2] == PRAZNO)
    return LAMBDA;
  return 2 * i + 2;
}

node PARENT(node i, BTREE T) {
  if (i < 0 || i >= MAXLENGTH || T.labels[i] == PRAZNO) {
    printf("PARENT: Ne postoji taj cvor.");
    exit(1);
  }
  if (i == 0)
    return LAMBDA;
  return (i - 1) / 2;
}

labeltype LABEL(node i, BTREE T) {
  if (i < 0 || i >= MAXLENGTH || T.labels[i] == PRAZNO) {
    printf("LABEL: Ne postoji taj cvor.");
    exit(1);
  }
  return T.labels[i];
}

void CHANGE_LABEL(labeltype l, node i, BTREE *T) {
  if (i < 0 || i >= MAXLENGTH || T->labels[i] == PRAZNO) {
    printf("CHANGE_LABEL: Ne postoji taj cvor.");
    exit(1);
  }
  T->labels[i] = l;
}


void PREORDER_ispis(BTREE T)
{
    PREORDER_ispis_pom(T, ROOT(T));
}

void PREORDER_ispis_pom(BTREE T, node lokacija)
{
    if (LAMBDA == lokacija)
        return;
     
    printf("...", LABEL(lokacija, T));
    PREORDER_ispis_pom(T, LEFT_CHILD(tren, T));
    PREORDER_ispis_pom(T, RIGHT_CHILD(tren, T));
}
 

int main (void)
{
    BTREE stablo;
    char string[1000];
    int i, trenutna;
    MAKE_NULL(&stablo);
    scanf("%[^\n]", string);
    trenutna = ROOT(stablo);
    while (string[i] != '\0')
    {
        CHANGE_LABEL(string[i], trenutna, &stablo);
        if (!broj)
        {
            
        }
        else
        {
            INSERT_LEFT_CHILD('-', trenutna, &stablo);
            INSERT_RIGHT_CHILD('-', trenutna, &stablo)
        }
        i++;
    }
    
    
    
    
    
    return 0;
}
