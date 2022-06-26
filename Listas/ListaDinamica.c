#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>

void CriaLista(TipoLista *L) {
	L->fim = NULL;
	L->inicio = NULL;
	printf("Eh nois!\n");
}

int InsereLista(TipoLista *L, TipoItem I) {

	TipoApontador p;

	p = (TipoApontador) malloc(sizeof(TipoNo));
	if (p == NULL) {
		printf("Deu ruim... tá com memória lotada!\n");
		return LISTA_CHEIA;
	}

	p->item = I;
	p->prox = NULL;
	if (ListaVazia(L)) {
		L->inicio = p;
		L->fim = p;
		p->prox = NULL; 
	} else {
		L->fim->prox = p;
		L->fim = p;
	}
	
	return SEM_ERRO;

}


static int RemoveListaPosicao(TipoLista *L, TipoApontador p) {
	
	if (p == NULL) {
		printf("Posicao invalida\n");
		return POS_INVALIDA;
	}

	// unico elemento
	if (p == L->inicio && p == L->fim) {
		CriaLista(L);
		free(p);
		return SEM_ERRO;
	}

	// remove do inicio
	if (p == L->inicio) {
		L->inicio = L->inicio->prox;
		free(p);
		return SEM_ERRO;
	}

	// remove do meio
	TipoApontador aux = L->inicio;
	while(aux->prox != NULL && aux->prox != p) {
		aux = aux->prox;
	}

	aux->prox = p->prox;

	// remove do fim
	if (aux->prox == NULL) {
		L->fim = aux;
	}

	free(p);
	return SEM_ERRO;
}

void RemoveLista(TipoLista *L, TipoChave C) {
	TipoApontador p = PesquisaLista(L, C);
	int e = RemoveListaPosicao(L, p);
	if (e == POS_INVALIDA)
		printf("Deu ruim\n");
	else
		printf("Sucesso\n");
}

TipoApontador PesquisaLista(TipoLista *L, TipoChave C) {
	TipoApontador p;

	p = L->inicio;
	while(p != NULL) {
		if (p->item.chave == C)
			return p;
		p = p->prox;
	}

	return p;
}

char ListaVazia(TipoLista *L) {
	return L->fim == NULL && L->inicio == NULL;
}
char ListaCheia(TipoLista *L);

void ImprimeLista(TipoLista *L)  {
        TipoApontador P = L->inicio;

	int i = 0;
	while(P != NULL) {
		if (P->prox != NULL)
			printf("%d: chave=%d, Proximo=%d\n", i, P->item.chave, P->prox->item.chave);
		else
			printf("%d: chave=%d, Proximo=NULO\n", i, P->item.chave);
		P = P->prox;
		i++;
	}
}
