#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#ifndef _LISTA_H_
#define _LISTA_H_

typedef struct aluno Aluno;
typedef struct professor Professor;
typedef struct vinculo Vinculo;
typedef struct projeto Projeto;

void cadastrar_projeto(Projeto **listaProj, Professor *listaP);
void listar_projeto(Projeto *listaProj);
void cadastrar_aluno(Aluno **listaA);
void listar_aluno(Aluno *listaA);
void cadastrar_professor(Professor **listaP);
void listar_professor(Professor *listaP);
void cadastrar_vinculo(Vinculo **listaV, Projeto *listaProj, Aluno *listaA);
void listar_vinculo(Vinculo *listaV);
void remover_vinculo(Vinculo **listaV, Projeto **listaProj);
void apresentar_final(Projeto *listaProj, Vinculo *listaV, int *aux);

void libera_memoria(Projeto *listaProj, Aluno *listaA, Vinculo *listaV, Professor *listaP);

#endif
