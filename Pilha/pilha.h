#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef int TipoChave;

typedef struct noPilha{
    TipoChave item;
    struct noPilha *prox;
}noPilha;

typedef noPilha *TipoApontador;


typedef struct Pilha{
    TipoApontador top;

}Pilha;

void CriaPilha(Pilha *P);
int Push(Pilha *p, TipoChave chave);
void Pop(Pilha *p);
TipoChave Topo(Pilha *p);

char PilhaVazia(Pilha *p);

void ImprimePilha(Pilha *p);

void DestroiPilha(Pilha * p);

void PopUntil(Pilha *P, TipoChave x);


















#endif
