#ifndef __LISTA_H__
#define __LISTA_H__
#include <stdio.h>
#include <stdlib.h>

#define SEM_ERRO 0
#define POS_INVALIDA -1
#define NAO_ENCONTROU -2
#define LISTA_CHEIA -3


typedef int TipoChave;

typedef struct {
	TipoChave chave;
	//char nome[50];
} TipoItem;

typedef struct TipoNo{
    TipoItem item;
    struct TipoNo *prox;
}TipoNo;

typedef struct TipoNo *TipoApontador;

typedef struct {
    TipoApontador inicio, fim;

}TipoLista;

void CriaLista(TipoLista *L);
	
int InsereLista(TipoLista *L, TipoItem I);

static int RemoveListaPosicao(TipoLista *L, TipoApontador p);

void RemoveLista(TipoLista *L, TipoChave C);

TipoApontador PesquisaLista(TipoLista *L, TipoChave C);
	

char ListaVazia(TipoLista *L);
char ListaCheia(TipoLista *L);

void ImprimeLista(TipoLista *L);

	
#endif