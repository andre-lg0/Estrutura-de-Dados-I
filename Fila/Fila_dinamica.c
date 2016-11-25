#include <stdlib.h>
#include <stdio.h>

typedef struct no{
int dado;
struct no *prox;

}nodo;

typedef struct{
nodo *inicio;
nodo *fim;

}Dinamic_Q;


Dinamic_Q* create_queque(){
   Dinamic_Q *novo = (Dinamic_Q*)malloc(sizeof(Dinamic_Q));
   if(novo!=NULL){
     novo->inicio = NULL;
     novo->fim = NULL;

   }
return (novo);
}


int Dfila_inserir(Dinamic_Q *Q,int info){
nodo *novo = (nodo*)malloc(sizeof(nodo));
if(novo){
novo->dado = info;
novo->prox =NULL;
if(Q->inicio==NULL&&Q->fim==NULL){
  Q->inicio = novo;
  Q->fim = novo;
return 1;
}else{
Q->fim->prox = novo;
Q->fim = novo;
return 1;
}
}
return 0;

}


int Dfila_remove(Dinamic_Q *Q,int *v){
nodo *aux;
aux = Q->inicio;
*v= aux->dado;
if(Q->inicio==NULL){
putenv("fila vazia");
return 0;
}else{
if(Q->inicio->prox==NULL){
Q->inicio=NULL;
Q->fim= NULL;
free(aux);
return 1;
}
Q->inicio = Q->inicio->prox;
free(aux);
return 1;
}
}


int main(){



}

