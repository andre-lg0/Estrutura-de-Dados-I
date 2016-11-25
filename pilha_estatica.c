#include <stdlib.h>
#include <stdio.h>
#define max 10

typedef struct{
  int dados[max];
  int head;

}Stack;

Stack *stack_create(){
  Stack * novo =(Stack*)malloc(sizeof(Stack));
  if(novo!= NULL)
  novo->head =-1;
  return novo;
}

void Stack_push(Stack *S,int valor){
  if(S->head +1<max)
     S->dados[++(S->head)]=valor;
else
  puts("stack overflow");

}

int Stack_pop(Stack *S, int *v){
if(S->head != -1){
  *v = S->dados[S->head--];
  return 1;

}
puts("stack underflow");
return 0;

}
