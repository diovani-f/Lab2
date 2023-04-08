#include "fila.h"

struct fila{
	int senha;
	struct fila *prox;
};

void fila_destroi(fila *f)
{
	fila *aux;
	
	while(f != NULL){
		aux = f;
		f = f->prox;
		free(aux);
	}
}

bool fila_vazia(fila *f)
{
	if(f == NULL){
		return true;
	}
	return false; 
}

void fila_insere(fila **f, int d)
{
    fila *aux, *novo = malloc(sizeof(fila));
    
    if(novo){
        novo->senha = d;
        novo->prox = NULL;
        if(*f == NULL){
            *f = novo;
        }else{
            aux = *f;
            while(aux->prox){
                aux = aux->prox;
            }
            aux->prox = novo;
        }
    }else
        printf("\nErro ao alocar memoria\n");
}	

void fila_remove(fila **f)
{
	fila *remover = NULL;

    if(*f){
        remover = *f;
        *f = remover->prox;
    }else{
    	printf("\nERRO.\n");
    	exit(400);
	}
}

void fila_escreve(fila *f)
{
	fila *aux;
	
	for(aux = f; aux != NULL; aux = aux->prox){
		printf("%d\n", aux->senha);
	}
}
