#include <stdio.h>
#include <stdlib.h>
#define PR 3
void *getP(void *pBuffer,int nPos);
void imprimir(void *pBuffer);
void add(void *pBuffer);

struct info{
    int id;
    int telefone;
    char nome[];
};

typedef struct info Pessoa;

int main(){
    void *pBuffer = NULL;
    int *escolha,*tamanho,*qnt,*nPos,*n;

    pBuffer = (void *)malloc(80000);
    escolha = (int *)(pBuffer);
    qnt = (int *)(pBuffer + sizeof(int));
    nPos = (int *)(pBuffer + sizeof(int)*2);
    *qnt = 0;
    *escolha = 1;

    do{
        printf(" -- MENU --\n1 - Adicionar\n2 - Procurar\n3 - Remover\nEscolha um numero: ");

        scanf("%d",escolha);

        switch (*escolha)
        {
            case 1:
                (*qnt)++;
                //pBuffer = realloc(pBuffer,(sizeof(int) * PR + (sizeof(Pessoa) * (*qnt) * 5)));
                escolha = (int *)(pBuffer);
                qnt = (int *)(pBuffer + sizeof(int));
                add(pBuffer);
            break;
            case 2:
                imprimir(pBuffer);
            break;
        }
        printf("\n\n%d\n\n",*qnt);
    }while(*escolha != 0);
}

void imprimir(void *pBuffer){
    int *i,*qnt;
    Pessoa *pInicio,*pAtual;
    
    qnt = (int *)(pBuffer + sizeof(int));
    i = (int *)(pBuffer + sizeof(int)*2);
    *i = 0;
    pInicio = (Pessoa *)(pBuffer + sizeof(int) * PR + sizeof(Pessoa));
    while(*i<*qnt){
        printf("Nome: %s\nTelefone:%d\n",pInicio->nome,pInicio->telefone);
        pInicio += sizeof(Pessoa);;
        (*i)++;
    }
}

void add(void *pBuffer){
    int *qnt;
    Pessoa *pAtual;
    
    qnt = (int *)(pBuffer + sizeof(int));

    pAtual = (Pessoa *)(pBuffer + sizeof(int) * PR + sizeof(Pessoa) * (*qnt));
    printf("Insira o nome: ");
	scanf("%s", (*pAtual).nome);
	printf("Insira a Telefone: ");
	scanf("%d", &(*pAtual).telefone);
}


// git config --global user.name ""
// git config --global user.email ""