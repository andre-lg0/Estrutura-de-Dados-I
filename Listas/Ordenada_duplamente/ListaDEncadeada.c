#include "ListaDEncadeada.h"
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
	/*p->prox = NULL;
	if (ListaVazia(L)) {
		L->inicio = p;
		L->fim = p;
	} else {
		L->fim->prox = p;
		L->fim = p;
	}
	*/

	p->ant = NULL;
	if (ListaVazia(L)) {
                L->inicio = p;
                L->fim = p;
		p->prox = NULL;
        } else if (L->inicio->item.chave > I.chave) { //primeira posicao
	
		p->prox = L->inicio;
		L->inicio->ant = p;
		L->inicio = p;

	} else { // todos os demais

		TipoApontador aux;
		aux = L->inicio;
		while(aux->prox != NULL && aux->prox->item.chave < I.chave) {
			aux = aux->prox;
		}

		p->prox = aux->prox;
		p->ant = aux;
		aux->prox = p;
		if (p->prox != NULL)
			p->prox->ant = p;

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
		L->inicio->ant = NULL; 
		free(p);
		return SEM_ERRO;
	}

	/*// remove do meio
	TipoApontador aux = L->inicio;
	while(aux->prox != NULL && aux->prox != p) {
		aux = aux->prox;
	}*/

	p->ant->prox = p->prox;

	// remove do fim
	if (p == L->fim) {
		L->fim = p->ant;
	} else {
		p->prox->ant = p->ant;
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

void ImprimeListaInvertida(TipoLista *L)  {
        TipoApontador P = L->fim;

	int i = 0;
	while(P != NULL) {
		if (P->ant != NULL)
			printf("%d: chave=%d, Anterior=%d\n", i, P->item.chave, P->ant->item.chave);
		else
			printf("%d: chave=%d, Anterior=NULO\n", i, P->item.chave);
		P = P->ant;
		i++;
	}
}
