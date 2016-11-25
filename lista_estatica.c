#include <stdio.h>
#include <stdlib.h>
#define max 10


typedef struct{
int dados[max];
int index;
}stack;

  stack* stack_create(){
stack *s =(stack*)malloc(sizeof(stack));
if(s!=NULL)
s->index =-1;
return s;
}

void stack_insert(stack *S,int info){
if(S->index +1< max -1)
S->dados[++(S->index)]=info;
else// nao posso inserir.
puts("overflow");
}


int list_seach(stack *S,int valor){
  int i;
  for(i = 0;i<= S->index;i++)
       if(S->dados[i]== valor)
       return i;
   return -1;

}

void list_delete(stack *S,int valor){
int posicao = list_seach(S,valor);
if(posicao !=-1){
int aux = S->dados[S->index];
S->dados[S->index]= S->dados[posicao];
S->dados[posicao]= aux;
S->index--;
}
else
puts("lista vazia ou posiçao nao encontrada");
}

void lista_print(stack *S){
  int i;
  for(i=0;i<=S->index;i++)
  printf("lista %d\n",S->dados[i] );
}


int main(int argc, char const *argv[]) {
  stack *L = stack_create();
int numeros[]={1,2,3,4,5,6},i;
for(i=0;i<6;i++){
  stack_insert(L,numeros[i]);

}
lista_print(L);

  return 0;
}
