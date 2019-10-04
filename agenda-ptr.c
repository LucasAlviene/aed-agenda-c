#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PR 3
void buscar(void *pBuffer);
void imprimir(void *pBuffer);
void add(void *pBuffer);
void remover(void *pBuffer);

void insertionSort(void *pBuffer);

struct info{
    int id;
    int telefone;
    char nome[20];
};

typedef struct info Pessoa;

int main(){
    void *pBuffer = NULL;
    int *escolha,*tamanho,*qnt,*nPos,*n;

    pBuffer = (void *)malloc(sizeof(int) * PR);
    escolha = (int *)(pBuffer);
    qnt = (int *)(pBuffer + sizeof(int));
    nPos = (int *)(pBuffer + sizeof(int)*2);
    *qnt = 0;
    *escolha = 1;

    do{
        printf(" -- MENU --\n1 - Adicionar\n2 - Imprimir\n3 - Procurar\n4 - Remover\nEscolha um numero: ");

        scanf("%d",escolha);

        switch (*escolha)
        {
            case 1:
                pBuffer = realloc(pBuffer,(sizeof(int) * PR + (sizeof(Pessoa) * (*qnt))));
                escolha = (int *)(pBuffer);
                qnt = (int *)(pBuffer + sizeof(int));
                add(pBuffer);
                (*qnt)++;
            break;
            case 2:
                imprimir(pBuffer);
            break;
            case 3:
                pBuffer = realloc(pBuffer,(sizeof(int) * PR + (sizeof(Pessoa) * (*qnt))) + sizeof(char) * 20);
                escolha = (int *)(pBuffer);
                qnt = (int *)(pBuffer + sizeof(int));
                buscar(pBuffer);
            break;
            case 4:
                pBuffer = realloc(pBuffer,(sizeof(int) * PR + (sizeof(Pessoa) * ((*qnt)+1))) + sizeof(char) * 20);
                buscar(pBuffer);
                pBuffer = realloc(pBuffer,(sizeof(int) * PR + (sizeof(Pessoa) * (*qnt))));
                escolha = (int *)(pBuffer);
                qnt = (int *)(pBuffer + sizeof(int));
            break;
            case 5:
                pBuffer = realloc(pBuffer,(sizeof(int) * PR + (sizeof(Pessoa) * (*qnt+1))) + sizeof(int));
                escolha = (int *)(pBuffer);
                qnt = (int *)(pBuffer + sizeof(int));
                insertionSort(pBuffer);

            break;
        }
        printf("\n\n");
    }while(*escolha != 0);
}

void remover(void *pBuffer){
    int *i,*qnt;
    Pessoa *pInicio,*pAux,*pProximo;

    i = (int *)(pBuffer + sizeof(int)*2);
    qnt = (int *)(pBuffer + sizeof(int));    

    pAux = (Pessoa *)(pBuffer + sizeof(int) * PR + sizeof(char) * 20 + sizeof(Pessoa) * (*qnt)+1);
    while(*i<*qnt){
        pInicio = (Pessoa *)(pBuffer + sizeof(int) * PR + sizeof(char) * 20 + sizeof(Pessoa) * *i);
        pProximo = (Pessoa *)(pBuffer + sizeof(int) * PR + sizeof(char) * 20 + sizeof(Pessoa) * (*i+1));
        *pAux = *pInicio;
        *pProximo = *pInicio;
        *pInicio = *pAux;
        (*i)++;
    }
    (*qnt)--;
}

void buscar(void *pBuffer){
    char *nome;
    int *i,*qnt,*escolha;
    Pessoa *pInicio;
    
    escolha = (int *)(pBuffer);
    qnt = (int *)(pBuffer + sizeof(int));
    i = (int *)(pBuffer + sizeof(int)*2);
    nome = (char *)(pBuffer + sizeof(int)* PR + sizeof(Pessoa) * *qnt);
    *i = 0;
    printf(" -- Procurar contato --\n");
    printf("Digite o nome: ");
    scanf("%s",nome);
    while(*i<*qnt){
        pInicio = (Pessoa *)(pBuffer + sizeof(int) * PR + sizeof(Pessoa) * *i);
        if(strcmp(nome,pInicio->nome) == 0){
            if(*escolha == 3) printf("Nome: %s\nTelefone:%d\n",pInicio->nome,pInicio->telefone);
            if(*escolha == 4) remover(pBuffer);
            break;
        }
        (*i)++;
    }

}

void insertionSort(void *pBuffer){ 
    int *i, *j,*qnt; 
    Pessoa *pInicio,*pProximo,*pAux;
    qnt = (int *)(pBuffer + sizeof(int));
    i = (int *)(pBuffer + sizeof(int)*2);
    j = (int *)(pBuffer + sizeof(int) * PR + sizeof(char) * 20 + sizeof(Pessoa) * (*qnt)+1);
    pAux = (Pessoa *)(pBuffer + sizeof(int) * PR + sizeof(char) * 20 + sizeof(Pessoa) * (*qnt));

    for (*i = 1; *i < *qnt; *(i)++) { 
        pInicio = (Pessoa *)(pBuffer + sizeof(int) * PR + sizeof(Pessoa) * *i); 
        *pAux = *pInicio;
        *j = *i - 1; 
        while (*j >= 0 && strcmp(pInicio,pProximo) == 1) { 
            pProximo = (Pessoa *)(pBuffer + sizeof(int) * PR + sizeof(Pessoa) * *j);
            *pInicio = *pProximo;
            *j = *j - 1; 
        } 
        *pProximo = *pAux; 
    } 
} 

void imprimir(void *pBuffer){
    int *i,*qnt;
    Pessoa *pInicio;
    
    qnt = (int *)(pBuffer + sizeof(int));
    i = (int *)(pBuffer + sizeof(int)*2);
    *i = 0;
    printf(" -- Lista de contatos --\n");
    while(*i<*qnt){
        pInicio = (Pessoa *)(pBuffer + sizeof(int) * PR + sizeof(Pessoa) * *i);
        printf("Nome: %s\nTelefone:%d\n",pInicio->nome,pInicio->telefone);
        (*i)++;
    }
}

void add(void *pBuffer){
    int *qnt;
    Pessoa *pAtual;
    
    qnt = (int *)(pBuffer + sizeof(int));
    pAtual = (Pessoa *)(pBuffer + sizeof(int) * PR + sizeof(Pessoa) * (*qnt));
    printf(" -- Adicionar contato --\n");
    printf("Insira o nome: ");
	scanf("%s", (*pAtual).nome);
	printf("Insira a Telefone: ");
	scanf("%d", &(*pAtual).telefone);
}


// git config --global user.name ""
// git config --global user.email ""