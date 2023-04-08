#ifndef _FILA_H_
#define _FILA_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct fila fila;

void fila_destroi(fila *f);

bool fila_vazia(fila *f);

void fila_insere(fila **f, int d);

void fila_remove(fila **f);

void fila_escreve(fila *f);

#endif
