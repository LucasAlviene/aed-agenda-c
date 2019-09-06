#include <stdio.h>
#include <stdlib.h>
#define PR 10
void *getP(void *pBuffer,int nPos);
void *addP(void *pBuffer);
void add(void *pBuffer);

int main(){
    void *pBuffer = NULL;
    int *escolha,*tamanho,*qnt,*nPos,*n;

    pBuffer = (void *)malloc(PR * sizeof(int));
    escolha = (int *)(pBuffer);
    nPos = (int *)(pBuffer + sizeof(int));
    qnt = (int *)(pBuffer + sizeof(int) * 2);
    *qnt = 0;
    *escolha = 1;
    do{
        printf(" -- MENU --\n1 - Adicionar\n2 - Procurar\n3 - Remover\nEscolha um numero: ");

        scanf("%d",escolha);

        switch (*escolha)
        {
            case 1:
                add(pBuffer);
            break;
            case 2:
            break;
        }
        
    }while(*escolha != 0);

}

void add(void *pBuffer){
    int *valor,*n,*numero;
    
    //valor = (int *)(pBuffer + sizeof(int) * PR + sizeof(int));

    valor = (int *)addP(pBuffer);
    scanf("%d",valor);
    

    n = (int *)getP(pBuffer,1);
    printf("\n%d\n",*n);
}

void *getP(void *pBuffer,int nPos){

    return pBuffer + sizeof(int) * PR + sizeof(int) * 4;
}

void *addP(void *pBuffer){
    int *qnt,*novo;
    qnt = (int *)(pBuffer + sizeof(int) * 2);
    *qnt += 1;
    novo = (pBuffer + sizeof(int) * PR) + sizeof(int) * (*qnt);

    //pBuffer = realloc(pBuffer,(pBuffer + sizeof(int) * PR) + sizeof(int) * (*qnt));
    return novo;
}

// git config --global user.name ""
// git config --global user.email ""