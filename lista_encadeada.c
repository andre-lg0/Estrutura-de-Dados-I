#include <stdlib.h>
#include <stdio.h>

typedef struct no{
int dado;
struct no* prox;

}nodo;

typedef struct{
nodo * inicio;

}lista;


lista* lista_create(){
lista *l =(lista*)malloc(sizeof(lista));
if(l!= NULL)
l->inicio= NULL;

return l;

}

void insert_list(lista *L,int valor){
nodo *novo =(nodo*)malloc(sizeof(nodo));
novo->dado = valor;
if(L->inicio ==NULL){
L->inicio = novo;
novo->prox = NULL;
}else{
nodo*temp;
temp = L->inicio;
while(temp->prox !=NULL)
temp= temp->prox;
temp->prox = novo;

}
}

void delete_list(lista *L,int valor ){
nodo *aux1,*aux2;
if(L->inicio!=NULL){
  if(L->inicio->dado == valor){
    aux1 = L->inicio;
    L->inicio = L->inicio->prox;
     free(aux1);
   }else{
    aux1= L->inicio;
    aux2 = L->inicio->prox;
    while(aux2!=NULL){
      if(aux2->dado == valor)
         break;
      aux1 = aux2;
      aux2=aux1->prox;
}
   if(aux2!=NULL){
    aux1->prox= aux2->prox;
     free(aux2);
    }

  }
 }

}
