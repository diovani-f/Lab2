#include "pilha.h"
#include "fila.h"

void triagem(fila **a_p, fila **an_p)
{
	char servico[100], g_priori[4];
	int senha;
	
	do{
		printf("\nDigite o servico desejado: ");
		scanf("%s", servico);
		printf("Voce pertence a algum grupo prioritario (sim/nao)?");
		scanf("%s", g_priori);
		printf("Forneca a senha: ");
		scanf("%d", &senha);
		if(strcmp("sim", g_priori) == 0){
			fila_insere(&*a_p, senha);
			return;
		}else{
			if(strcmp("nao", g_priori) == 0){
				fila_insere(&*an_p, senha);
				return;
			}else{
				printf("\n\nComando INVALIDO, digite novamente:\n\n");
			}
		}
	}while(true);
}

void atendimento(fila **a_p, fila **an_p, pilha **p)
{
	char comando[4];
	int id_doc;
	do{
		if(!fila_vazia(*a_p)){
			printf("\n\n-- FILA PRIORITARIA --\n");
			fila_remove(&*a_p);
		}else{
			if(!fila_vazia(*an_p)){
				printf("\n\n-- FILA NAO PRIORITARIA --\n");
				fila_remove(&*an_p);
			}else{
				printf("\nNao ha pessoas na fila.\n\n");
				return;
			}
		}
		printf("Gerar documentos (sim/nao): ");
		scanf("%s", comando);
		if(strcmp("sim", comando) == 0){
			printf("Digite o identificador do documento: ");
			scanf("%d", &id_doc);
			*p = pilha_insere(&*p, id_doc);
			printf("\nDocumento inserido.\n");
			return;
		}else{
			if(strcmp("nao", comando) != 0){
				return;
			}else{
				printf("\n\nComando INVALIDO, digite novamente:\n\n");
			}
		}
	}while(true);
}

int main()
{
	pilha *p = NULL;
	fila *a_p = NULL, *an_p = NULL;
	int comando = 1;
	
	do{
		printf("\n\nSelecione uma opcao:\n\n1 -> Triagem\n2 -> Atendimento\n3 -> Processar documento\n4 -> Imprimir filas e pilha\n0 -> Sair\n");
		scanf("%d", &comando);
		if(comando == 1){
			triagem(&a_p, &an_p);
		}else{
			if(comando == 2){
				atendimento(&a_p, &an_p, &p);
			}else{
				if(comando == 3){
					if(!pilha_vazia(p)){
						pilha_remove(&p);
					}else{
						printf("\n\nSem documentos para processar.\n\n");
					}
				}else{
					if(comando == 4){
						printf("--FILA PRIORITARIA--\n");
						fila_escreve(a_p);
						printf("--FILA NAO PRIORITARIA--\n");
						fila_escreve(an_p);
						printf("--DOCUMENTOS--\n");
						pilha_escreve(p);
					}
				}
			}
		}
	}while(comando != 0);
	
	return 0;
}
