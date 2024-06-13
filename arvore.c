#include <stdio.h>
#include <stdlib.h>

typedef struct TNoABP
{
    int chave;
    struct TNoABP *esq;
    struct TNoABP *dir;
}TNoABP;

void insereABP (TNoABP **r, int key) 
{
    if (*r == NULL)
    {
        TNoABP *r2;
        r2 = (TNoABP*)malloc(sizeof(TNoABP));
        if(r2==NULL) //verifica se não houve problema na alocação da árvore.
        {
            printf("\nSO nao liberou memoria!"); 
            return;
        }
        r2->chave = key;
        r2->esq = NULL;
        r2->dir = NULL;
        *r = r2;
    }
    else if ((*r)->chave > key)
        insereABP(&(*r)->esq, key);
    else
        insereABP(&(*r)->dir, key);
}

int achaMaiorEsq(TNoABP **no1)
{
    
    int x;
    TNoABP *r3;

    if((*no1)->dir != NULL)
        return(achaMaiorEsq(&(*no1)->dir));
    else
    {
        r3 = *no1;
        x = (*no1)->chave;
        *no1 = (*no1)->esq;
        free(r3);
        r3 = NULL;
        return(x);
    }
}




void removeABP (TNoABP **r, int key)
{
    TNoABP *r2;
        if(*r != NULL)
        {
            if((*r)->chave == key)
            {
                r2 = *r;
                if((*r)->esq == NULL)
                {
                    *r = (*r)->dir;
                    free(r2);
                    r2 = NULL;
                }
                
                else if((*r)->dir == NULL)
                {
                    *r = (*r)->esq;
                    free(r2);
                    r2 = NULL;  
                }
                
                else ((*r)->chave = achaMaiorEsq(&(*r)->esq));
            }
        else if((*r)->chave < key)
            removeABP(&(*r)->dir,key);
        else 
            removeABP(&(*r)->esq,key);
        }
}


void printABP (TNoABP *raiz) //travessia em ordem
{
    if (raiz==NULL) return;
    printABP (raiz->esq);
    printf("%d\n", raiz->chave);
    printABP (raiz->dir);
}

int main()
{
    TNoABP *raiz = NULL;
    int i, n = -1, chave, k;
    //TNoABP *raiz2 = NULL;
    
    while (n<0) //para admitir apenas valores positivos.
    {
        scanf("%d", &n);
    }
    
    for (i=0; i<n; i++)
    {
        scanf("%d", &chave);
        insereABP (&raiz, chave);
    }
    //printf("////////////");
    
    
    scanf("%d", &k); //chave do nó a ser removido
    removeABP (&raiz, k);
    //printf("\nPrintando arvore!\n");
    printABP (raiz);
}