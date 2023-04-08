#include "pilha.h"

struct pilha{
	int id_doc;
	struct pilha *prox;
};

void pilha_destroi(pilha *p)
{
	pilha *aux;
	
	while(p != NULL){
		aux = p;
		p = p->prox;
		free(aux);
	}
}

bool pilha_vazia(pilha *p)
{
	if(p == NULL){
		return true;
	}
	return false; 
}

pilha *pilha_insere(pilha **p, int d)
{
	pilha *aux = malloc(sizeof(pilha));
	aux->id_doc = d;
	aux->prox = *p;
	return aux;
}

void pilha_remove(pilha **p)
{
    pilha *remover = NULL;

    if(*p){
        remover = *p;
        *p = remover->prox;
    }else{
    	printf("\nERRO.\n");
    	exit(400);
	}
}

void pilha_escreve(pilha *p)
{
	pilha *aux;
	
	for(aux = p; aux != NULL; aux = aux->prox){
		printf("%d\n", aux->id_doc);
	}
}



