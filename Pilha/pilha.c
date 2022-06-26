
#include "pilha.h"


void CriaPilha(Pilha *p){
    p->top = NULL;

}


int Push(Pilha *p, TipoChave chave){
    TipoApontador novoNo = (TipoApontador)malloc(sizeof(noPilha));

    if(novoNo == NULL){
        printf("Pilha cheia\n");
        return -1;
    }

    novoNo->item  = chave;
    
    if(pilhaVazia(p)){
        novoNo->prox = NULL;
        p->top = novoNo;

    }
    else {
        novoNo->prox = p->top;
        p->top = novoNo;
    }

    return 1;
}


void Pop(Pilha *p){
    TipoApontador aux;
    if(pilhaVazia(p)){
        printf("pilha vazia, nada para remover\n");
        return;
    }
    aux = p->top;
    p->top = aux->prox;
    free(aux);
}



char PilhaVazia(Pilha *p){
    if(p->top == NULL)
        return 1;
    return 0;
}

TipoChave Topo(Pilha *p){
    if(!pilhaVazia(p))
        return p->top->item;

    printf("pilha vazia\n");
    TipoChave I = INT_MIN;
    return I;
}

void ImprimePilha(Pilha *p){
    TipoApontador aux = p->top;
    int i = 0;
    while(aux != NULL){
        printf(" item %d é %d\n", i,aux->item);
        aux = aux->prox;
        i++;
    }



}

void DestroiPilha(Pilha * p){
    while(!pilhaVazia(p))
        pop(p);
}

void PopUntil(Pilha *P, TipoChave x){
	TipoChave I = Topo(P);

	while(!PilhaVazia(P)){
		if(I == x){
			Pop(P);
			break;
		}
		Pop(P);
		I = Topo(P);
	}
}