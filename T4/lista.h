#include "arv.h"
#ifndef _LISTA_H_
#define _LISTA_H_

typedef struct lista Lista;

void lista_insere_inicio(Lista **l, char n_cpf[], char n_nome[], float n_salario, struct arv *n_filial);
void lista_insere_fim(Lista **l, char n_cpf[], char n_nome[], float n_salario, struct arv *n_filial);
void lista_remove_cpf(Lista **l, char cpf[]);
int lista_conta_fun(Lista *l, int cod);
void lista_remove_codigo(Lista **l, int cod);
void lista_escreve(Lista *l);
void lista_escreve_da_mesma_filial(Lista *l, int cod);
void lista_destroi(Lista *l);

#endif

