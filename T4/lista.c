#include "lista.h"

struct lista{
	char cpf[50], nome[50];
	struct arv *filial;
	float salario;
	struct lista *prox;
};

void lista_insere_inicio(Lista **l, char n_cpf[], char n_nome[], float n_salario, struct arv *n_filial)
{
	Lista *novo = malloc(sizeof(Lista));
	
	if(novo){
		strcpy(novo->cpf, n_cpf);
		strcpy(novo->nome, n_nome);
		novo->salario = n_salario;
		novo->filial = n_filial;
		novo->prox = *l;
		*l = novo;
	}else{
		printf("Erro ao alocar memoria.\n");
	}
}

void lista_insere_fim(Lista **l, char n_cpf[], char n_nome[], float n_salario, struct arv *n_filial)
{
	Lista *aux, *novo = malloc(sizeof(Lista));
	
	if(novo){
		strcpy(novo->cpf, n_cpf);
		strcpy(novo->nome, n_nome);
		novo->salario = n_salario;
		novo->filial = n_filial;
		novo->prox = NULL;
		
		if(*l == NULL){
			*l = novo;
		}else{
			aux = *l;
			while(aux->prox){
				aux = aux->prox;
			}
			aux->prox = novo;
		}
	}else{
		printf("Erro ao alocar memoria.\n");
	}
}
void lista_remove_cpf(Lista **l, char cpf[])
{
	Lista *aux, *remover = NULL;
	
	if(*l){
		if(strcmp((*l)->cpf, cpf) == 0){ 
			remover = *l;
			*l = remover->prox;
		}else{
			aux = *l;
			while(aux->prox && strcmp(aux->prox->cpf, cpf) == 0){
				aux = aux->prox;
			}
			if(aux->prox){
				remover = aux->prox;
				aux->prox = remover->prox;
			}
		}
	}else{
		printf("\nCPF nao encontrado.\n");
		return;
	}
	*l = remover;
	printf("\nRemovido com sucesso.\n");
}

int lista_conta_fun(Lista *l, int cod)
{
	int cont = 0;
	Lista *aux;
	
	for(aux = l; aux != NULL; aux = aux->prox){
		if(aux->filial->codigo == cod){
			cont++;
		}
	}
	return cont;
}

void lista_remove_codigo(Lista **l, int cod)
{
	Lista *aux, *remover = NULL;
	
	if(*l){
		if((*l)->filial->codigo == cod){ 
			remover = *l;
			*l = remover->prox;
		}else{
			aux = *l;
			while(aux->prox && aux->prox->filial->codigo == cod){
				aux = aux->prox;
			}
			if(aux->prox){
				remover = aux->prox;
				aux->prox = remover->prox;
			}
		}
	}
	*l = remover;
}

void lista_escreve(Lista *l)
{
	Lista *aux;
	
	for(aux = l; aux != NULL; aux = aux->prox){
		printf("CPF: %s\nNome: %sFilial: %sSalario: %.2f\n\n", aux->cpf, aux->nome, aux->filial->r_social, aux->salario);
	}
}

void lista_escreve_da_mesma_filial(Lista *l, int cod)
{
	Lista *aux;
	
	for(aux = l; aux != NULL; aux = aux->prox){
		if(aux->filial->codigo == cod){
			printf("Funcionario: %sCPF: %s\n\n", aux->nome, aux->cpf);
		}
	}
}

void lista_destroi(Lista *l)
{
	Lista *aux;
	
	while(l != NULL){
		aux = l;
		l = l->prox;
		free(aux);
	}
}
