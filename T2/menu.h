#include "lista.h"
#ifndef _MENU_H_
#define _MENU_H_

void menu_aluno(Aluno **listaA);
void menu_projeto(Projeto **listaProj, Professor *listaP);
void menu_vinculo(Vinculo **listaV, Projeto *listaProj, Aluno *listaA);
void menu_professor(Professor **listaP);
void menu_principal(int *aux);

#endif
