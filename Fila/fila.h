#ifndef FILA_H
#define FILA_H
#include <stdio.h>
#include <stdlib.h>

typedef int tipoChave;

typedef struct no {
	tipoChave item;
	struct no *prox;
}No;

typedef No* tipoApontador;

typedef struct Fila {
	tipoApontador inicio;
	tipoApontador fim;
}Fila;


void CriaFila(Fila *f);
int InsereFila(Fila *f, tipoChave chave);
int RemoveFila(Fila*f);
char FilaVazia(Fila *f);
tipoChave ItemFrente(Fila *f);
void ImprimeFila(Fila *f);
void DestroiFila(Fila *f);



#endif
