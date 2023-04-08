#include "lista.h"

void menu_lista(Lista **l, arv **a)
{
	arv *aux = *a;
	int c, im, cod;
	float salario;
	char nome[100], cpf[50];
	
	do{
		printf("\nO que deseja fazer (lista):\n1 -> Inserir;\n2 -> Remover;\n3 -> Imprimir;\n0 -> Voltar;\n\n");
		scanf("%d", &c);
		if(c == 1){
			printf("\n\n-- DIGITE AS INFORMACOES DO FUNCIONARIO --\n");
			printf("CPF: ");
			scanf("%s", cpf);
			printf("Nome:");
			getchar();
			fgets(nome, 100, stdin);
			printf("Codigo da filial: ");
			scanf("%d", &cod);
			aux = arv_busca(aux, cod);
			if(aux == NULL){
				printf("\n\nFilial nao encontrada, tente novamente.\n\n");
				return;
			}
			printf("Salario: ");
			scanf("%f", &salario);
			printf("Deseja inserir no inicio ou no fim da lista (1 ou 0 respectivamente)? ");
			scanf("%d", &im);
			if(im == 1){
				lista_insere_inicio(&*l, cpf, nome, salario, aux);
			}else{
				if(im == 0){
					lista_insere_fim(&*l, cpf, nome, salario, aux);
				}else{
					printf("\n\nComando invalido.\n\n");
					continue;
				}
				printf("\n\nINSERIDO COM SUCESSO!\n\n");
			}
			return;
		}else{
			if(c == 2){
				printf("\n--DIGITE AS INFORMACOES PARA REMOCAO --\n");
				printf("Digite o CPF do funcionario que sera removido: ");
				getchar();
				fgets(cpf, 50, stdin);
				lista_remove_cpf(&*l, cpf);
			}else{
				if(c == 3){
					if(*l != NULL){
						printf("\n---- LISTA ----\n");
						lista_escreve(*l);
					}else{
						printf("\n\nVAZIA.\n\n");
					}
				}else{
					if(c == 0){
						return;
					}else{
						printf("\n\nComando invalido.\n\n");
					}
				}
			}
		}
	}while(true);
}

void menu_arv(Lista **l, arv **a)
{
	int c, cod;
	char r_social[100], endereco[100], cpf[100];
	
	do{
		printf("\nO que deseja fazer (arvore):\n1 -> Inserir;\n2 -> Remover;\n3 -> Imprimir;\n0 -> Voltar;\n\n");
		scanf("%d", &c);
		if(c == 1){
			printf("\n\n--DIGITE AS INFORMACOES DA FILIAL--\n");
			printf("Codigo: ");
			scanf("%d", &cod);
			printf("Razao social:");
			getchar();
			fgets(r_social, 100, stdin);
			printf("Endereco:");
			fgets(endereco, 100, stdin);
			arv_insere(&*a, cod, r_social, endereco);
			return;
		}else{
			if(c == 2){
				printf("\n--DIGITE AS INFORMACOES PARA REMOCAO --\n");
				printf("Digite o codigo da filial: ");
				scanf("%d", &cod);
				int cont = lista_conta_fun(*l, cod);
				*a = arv_remove(*a, cod);
				while(cont > 0){
					lista_remove_codigo(&*l, cod);
					cont--;
				}
				return;
			}else{
				if(c == 3){
					if(*a != NULL){
						printf("\n---- ARVORE ----\n");
						arv_escreve(*a);
					}else{
						printf("\n\nVAZIA.\n\n");
					}
				}else{
					if(c == 0){
						return;
					}else{
						printf("\n\nComando invalido.\n\n");
					}
				}
			}
		}
	}while(true);
}

void imp_dados(Lista *l, arv *a)
{
	int cod;
	arv *aux;
	do{
		printf("\nDigite o codigo da filial: ");
		scanf("%d", &cod);
		if(arv_busca(a, cod) != NULL){
			printf("\n-- VINCULO --\n");
			aux = arv_busca(a, cod);
			printf("Razao social da filial: %s", aux->r_social);
			lista_escreve_da_mesma_filial(l, cod);
			return;
		}else{
			printf("\nFilial nao encontrada!\n\n");
			return;
		}
	}while(true);
}

int main()
{
	int esc;
	Lista *l = NULL;
	arv *a = NULL;
	
	do{
		printf("-- MENU --\n");
		printf("Escolha a estrutura que deseja alterar (0 para sair):\n\n1 -> Lista (funcioanarios);\n2 -> Arvore (filiais);\n3 -> Impressao dos dados de vinculo;\n");
		scanf("%d", &esc);
		if(esc == 1){
			menu_lista(&l, &a);
		}else{
			if(esc == 2){
				menu_arv(&l, &a);
			}else{
				if(esc == 3){
					imp_dados(l, a);
				}else{
					if(esc == 0){
						break;
					}else{
						printf("\n\nComando invalido.\n\n");
					}
				}
				
			}
		}
	}while(true);
	
	return 0;
}
