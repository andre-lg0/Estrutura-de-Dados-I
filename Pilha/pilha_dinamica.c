#include <stdlib.h>
#include <stdio.h>

typedef struct no{
  int dados;
  struct no *prox;
}nodo;

typedef struct{
nodo *head;

}Dstack;

Dstack * create_stack(){
Dstack *novo = (Dstack*)malloc(sizeof(Dstack));
if(novo!=NULL)
novo->head = NULL;
return novo;

}

void Dstack_push(Dstack *S,int valor){
nodo *novo = (nodo*)malloc(sizeof(nodo));
novo->dados= valor;
novo->prox =S->head;
S->head = novo;
}

void Dstack_pop(Dstack *S,int *v){
nodo *aux = S->head;
*v = aux->dados;
if(S->head!=NULL){
S->head = S->head->prox;
free(aux);
}else{
  puts("stack underflow");
}

}
