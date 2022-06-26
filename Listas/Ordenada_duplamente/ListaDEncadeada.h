#ifndef LISTA_DUPLAMENTE_H
#define LISTA_DUPLAMENTE_H

#define SEM_ERRO 0
#define POS_INVALIDA -1
#define NAO_ENCONTROU -2
#define LISTA_CHEIA -3

typedef int TipoChave;
typedef struct {
	TipoChave chave;
} TipoItem;

typedef struct TipoNo *TipoApontador;

typedef struct TipoNo {
	TipoItem item;
	struct TipoNo *prox, *ant;
} TipoNo;

typedef struct {
	TipoApontador inicio, fim;
} TipoLista;

void CriaLista(TipoLista *L);
int InsereLista(TipoLista *L, TipoItem I);
void RemoveLista(TipoLista *L, TipoChave C);
TipoApontador PesquisaLista(TipoLista *L, TipoChave C);

char ListaVazia(TipoLista *L);
char ListaCheia(TipoLista *L);

void ImprimeLista(TipoLista *L);
void ImprimeListaInvertida(TipoLista *L);

#endif
