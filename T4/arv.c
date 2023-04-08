#include "arv.h"
	
void arv_insere(arv **a, int cod, char r_social[], char end[])
{
	arv *aux = *a;
	while(aux){
		if(cod < aux->codigo){
			a = &aux->esq;
		}else{
			a = &aux->dir;
		}
		aux = *a;
	}
	aux = malloc(sizeof(arv));
	aux->codigo = cod;
	strcpy(aux->r_social, r_social);
	strcpy(aux->endereco, end);
	aux->esq = NULL;
	aux->dir = NULL;
	*a = aux;
}

arv* arv_remove(arv *raiz, int chave) {
    if(raiz == NULL){
        printf("\nFilial nao encontrada!\n");
        return;
    } else {
        if(raiz->codigo == chave) {
            if(raiz->esq == NULL && raiz->dir == NULL) {
                free(raiz);
                printf("\nRemovida com sucesso.\n");
                return NULL;
            }else{
                if(raiz->esq != NULL && raiz->dir != NULL){
                    arv *aux = raiz->esq;
                    while(aux->dir != NULL)
                        aux = aux->dir;
                    raiz->codigo = aux->codigo;
                    aux->codigo = chave;
                    raiz->esq = arv_remove(raiz->esq, chave);
                    printf("\nRemovida com sucesso.\n");
                    return raiz;
                }else{
                    arv *aux;
                    if(raiz->esq != NULL)
                        aux = raiz->esq;
                    else
                        aux = raiz->dir;
                    free(raiz);
                    printf("\nRemovida com sucesso.\n");
                    return aux;
                }
            }
        }else{
            if(chave < raiz->codigo)
                raiz->esq = arv_remove(raiz->esq, chave);
            else
                raiz->dir = arv_remove(raiz->dir, chave);
        }
        return raiz;
    }
}

arv *arv_busca(arv *a, int cod)
{
	if(a){
		if(cod == a->codigo){
			return a;
		}else{
			if(cod < a->codigo){
				return arv_busca(a->esq, cod);
			}else{
				return arv_busca(a->dir, cod);
			}
		}
	}
	return NULL;
}

void arv_escreve(arv *a)
{
	if(a){
		arv_escreve(a->dir);
		printf("Codigo: %d\nRazao Social: %sEndereco: %s\n", a->codigo, a->r_social, a->endereco);
		arv_escreve(a->esq);
	}
}

void arv_destroi(arv *a)
{
	if(a->dir != NULL || a->esq != NULL){
		arv_destroi(a->dir);
		arv_destroi(a->esq);
		free(a);
	}
}

