#ifndef _ARV_H_
#define _ARV_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct arv arv;

struct arv{
	int codigo;
	char r_social[100];
	char endereco[100];
	struct arv *dir, *esq;
};

void arv_insere(arv **a, int cod, char r_social[], char end[]);
void arv_escreve(arv *a);
arv *arv_remove(arv *raiz, int chave);
arv *arv_busca(arv *a, int cod);
void arv_destroi(arv *a);

#endif
