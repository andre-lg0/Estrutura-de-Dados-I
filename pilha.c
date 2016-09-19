#include <stdio.h>
#include <stdlib.h>
#define Max 4

typedef struct{
int dados[Max];
int head;

} Stack;



Stack * stack_create(){
Stack *p = (Stack*)malloc(sizeof(Stack));
if(p)
p->head = -1;
return p;

}

void Static_push(Stack *P,int v){
if(P->head+1<Max )
P->dados[++(P->head)]=v;
else
puts("stack overflow");


}


int stack_pop(Stack *P,int *v){
if(P->head > -1){

*v = P->dados[P->head--];
return 1;
}
puts("\npilha vazia");
return 0;

}


int main (){
Stack *P1 = stack_create();
Stack *P2 = stack_create();
int i;
int carros[]={1,2,3,5};
int mover;
int numero =3;



for(i=0;i<Max;i++){
Static_push(P1,carros[i]);

}
while(stack_pop(P1,&mover)){
if(numero==mover ){
   puts("\ncarro removido com sucesso");
   break;
}else{
     Static_push(P2,mover);
       printf("%d",mover);


   }


}

while(stack_pop(P2,&mover)){
Static_push(P1,mover);
printf("%d",mover);

}



}



