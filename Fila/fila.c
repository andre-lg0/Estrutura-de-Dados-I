#include "fila.h"




void CriaFila(Fila *f){
    f->inicio = NULL;
    f->fim = NULL;
}


int InsereFila(Fila *f, tipoChave chave){
    tipoApontador novoNo = (tipoApontador)malloc(sizeof(No));
    if(novoNo == NULL)
        return -1;

    novoNo->item = chave;
    novoNo->prox = NULL;

    if(FilaVazia(f)){
        f->inicio = novoNo;
        f->fim = novoNo;
        return 1;
    
    }

    f->fim->prox = novoNo;
    f->fim = novoNo;
    return 1;
}

int RemoveFIla(Fila *f){
    tipoApontador aux;

    if(FilaVazia(f)){
        printf("fila vazia\n");
        return -1;
    }
    
    if(f->inicio->prox == NULL){
        aux = f->inicio;
        CriaFila(f);
        free(aux);
        return 1;
    }

    aux = f->inicio;
    f->inicio = aux->prox;
    free(aux);
    return 1;
}


char FilaVazia(Fila *f){
    if(f->inicio==NULL && f->fim == NULL)
        return 1;
    return 0;
}

tipoChave ItemFrente(Fila *f){
    return f->inicio->item;
}

void ImprimeFIla(Fila *f){
    tipoApontador aux;
    int i;
    aux = f->inicio;
    for (i = 0;aux != NULL; i++,aux = aux->prox){
        printf("o item %d é o %d\n", i,aux->item);
    }
}

void DestroiFila(Fila *f){
    while(!FilaVazia(f)){
        RemoveFIla(f);
    }
}