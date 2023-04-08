#include "menu.h"

void menu_aluno(Aluno **listaA)
{
	char com[100];
	
	do{
		printf("\nDeseja:\n-> Listar\n-> Inserir\n");
		scanf("%s", com);
		if(strcmp(com, "inserir") == 0){
			cadastrar_aluno(&*listaA);
			return;
		}else{
			if(strcmp(com, "listar") == 0){
				listar_aluno(*listaA);
				return;
			}else{
				printf("\nCOMANDO INVALIDO, digite novamente.\n");
				continue;
			}
		}
	}while(true);
}

void menu_projeto(Projeto **listaProj, Professor *listaP)
{
	char com[100];
	
	do{
		printf("\nDeseja:\n-> Listar\n-> Inserir\n");
		scanf("%s", com);
		if(strcmp(com, "inserir") == 0){
			 cadastrar_projeto(&*listaProj, listaP);
			return;
		}else{
			if(strcmp(com, "listar") == 0){
				listar_projeto(*listaProj);
				return;
			}else{
				printf("\nCOMANDO INVALIDO, digite novamente.\n");
				continue;
			}
		}
	}while(true);
}

void menu_vinculo(Vinculo **listaV, Projeto *listaProj, Aluno *listaA)
{
	char com[100];
	
	do{
		printf("\nDeseja:\n-> Listar\n-> Inserir\n");
		scanf("%s", com);
			if(strcmp(com, "listar") == 0){
				listar_vinculo(*listaV);
				return;
			}else{
                if(strcmp(com, "inserir") == 0){
                    cadastrar_vinculo(&*listaV, listaProj, listaA);
                    return;
                }else{
                    printf("\nCOMANDO INVALIDO, digite novamente.\n");
                    continue;
                }
			    }
	}while(true);
}

void menu_professor(Professor **listaP)
{
	char com[100];
	
	do{
		printf("\nDeseja:\n-> Listar\n-> Inserir\n");
		scanf("%s", com);
		if(strcmp(com, "inserir") == 0){
			cadastrar_professor(&*listaP);
			return;
		}else{
			if(strcmp(com, "listar") == 0){
				listar_professor(*listaP);
				return;
			}else{
				printf("\nCOMANDO INVALIDO, digite novamente.\n");
				continue;
			}
		}
	}while(true);
}


void menu_principal(int *aux)
{
    
	char com[100];
	
	do{
		printf("Digite em qual lista deseja fazer alteracoes ou um comando (palavra destacada):\n-> Aluno\n-> Projeto\n-> Vinculo\n-> Professor\n-> Remover (Vinculo)\n-> Encerrar\n");
		scanf("%s", com);
		if(strcmp(com, "aluno") == 0){
			*aux = 1;
			return;
		}else{
			if(strcmp(com, "projeto") == 0){
				*aux = 2;
				return;
			}else{
				if(strcmp(com, "vinculo") == 0){
					*aux = 3;
                    return;
				}else{
					if(strcmp(com, "professor") == 0){
		 				*aux = 4;
		 				return;
					}else{
						if(strcmp(com, "encerrar") == 0){
                            *aux = 5;
							return;
						}else{
                            if(strcmp(com, "remover") == 0){
                                *aux = 6;
							    return;
						    }else{
                                printf("\nComando INVALIDO. Escreva novamante.\n\n");
                                continue;
                            }   
						}
					}
				}
			}
		}
	}while(true);
	
	*aux = 0;
}
