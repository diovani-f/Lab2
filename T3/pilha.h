#ifndef _PILHA_H_
#define _PILHA_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct pilha pilha;

void pilha_destroi(pilha *p);

bool pilha_vazia(pilha *p);

pilha *pilha_insere(pilha **p, int d);

void pilha_remove(pilha **p);

void pilha_escreve(pilha *p);

#endif
