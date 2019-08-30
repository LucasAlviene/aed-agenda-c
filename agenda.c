#include <stdio.h>

//teste

struct dados_struct{
    int id;
    char nome[50];
    char data[10];
    struct dados *prox;
};
typedef struct dados_struct dados;

dados *init(void);
void add(dados *p,int *i);
void imprime(dados * ini);
void *buscar(dados * ini);

int main(){


    dados *agenda;
    int *i,n=0;
    agenda = init();
    int escolha;
    i = &n;
    do{
        printf("1-Adicionar\n2-Listar\n3-Remover\n4-Buscar\n0-Sair\n");
        printf("Escolhas uma das opcoes: ");
        scanf("%d",&escolha);
        switch(escolha){
            case 1:
                add(agenda,i);
            break;
            case 2:
                imprime(agenda);
            break;
            case 3:
                remova(agenda);
            break;
            case 4:
                buscar(agenda);
            break;
        }
    }while(escolha != 0);


    return 0;
}

void *buscar(dados * ini){
    int id;

    printf("Insira o ID: ");
    scanf("%d",&id);

	dados *p;
	p = ini->prox;
	while (p != NULL && p->id != id)
		p = p->prox;
    if(p != NULL){
        printf("\nNome: %s\nDescricao:%s\n\n", p->nome,p->data);
    }else{
        printf("\nNada encontrado\n\n");
    }

}

void remova(dados * ini)
{
    int id;

    printf("\nInsira o ID: ");
    scanf("%d",&id);

	dados *p, *q;
	p = ini;
	q = ini->prox;
	while ((q != NULL) && (q->id != id)) {
		p = q;
		q = q->prox;
	}
	if (q != NULL) {
		p->prox = q->prox;
		free(q);
	}
    printf("\nRemovido\n");
}

void imprime(dados * ini)
{
	dados *p;

    printf("\nLISTAR \n\n");
	for (p = ini->prox; p != NULL; p = p->prox)
		printf("\nID:%d\nNome: %s\nDescricao:%s\n\n", p->id,p->nome,p->data);
}
void add(dados * p,int *i)
{
	dados *nova;

	nova = (dados *) malloc(sizeof(dados));
    nova->id = *i;
    *i = (*i)+1;
    printf("Nome: ");
    scanf("%s",nova->nome);
    printf("Data: ");
    scanf("%s",nova->data);

    printf("\n\n");

	nova->prox = p->prox;
	p->prox = nova;
}

dados *init(void)
{
	dados *start;

	start = (dados *) malloc(sizeof(dados));
	start->prox = NULL;
	return start;
}