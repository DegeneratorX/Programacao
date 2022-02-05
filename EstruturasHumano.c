#include <stdio.h>
#include <stdlib.h>


typedef struct _nodeTabuleiro{
    struct _nodeTabuleiro *cima;
    struct _nodeTabuleiro *baixo;
    struct _nodeTabuleiro *esq;
    struct _nodeTabuleiro *dir;
    int posicao;
    char embarcacao[2];
} NodeTabuleiro;



void l_inicTabuleiro(NodeTabuleiro **l){
    (*l) = NULL;
}

void i_inserirTabuleiroParaBaixo(NodeTabuleiro **l, int posicaoN){
    NodeTabuleiro *novo;

    novo = (NodeTabuleiro*)malloc(sizeof(NodeTabuleiro));

    novo->posicao = posicaoN;
    stpcpy(novo->embarcacao,"@");

    novo->baixo = *l;
    *l = novo;



}



void apontarParaCimaNorPar (NodeTabuleiro *le) {


   int anterior = 1;


   NodeTabuleiro *novo;
   novo = (NodeTabuleiro*)malloc(sizeof(NodeTabuleiro));


   /*

   Vai descendo a lista e os nos pares vao apontando para cima...

   1

   ^
   |
   v

   2 (agora aponta para cima e para baixo)

   |
   v

   3

   ^
   |
   v

   4 (agora aponta para cima e para baixo)

   |
   v

   5

   ...


   */


   NodeTabuleiro *p; // Vai indo para baixo.. (apontar apenas para os pares)
   for (p = le; p != NULL; p = p->baixo){
        if(anterior % 2 != 0){
            novo->cima = p;
            anterior++;
        } else {
            le = novo;
            anterior++;
        }

   }



}





void apontarParaCimaNorImpar (NodeTabuleiro *le) {

   int anterior = 1;


   NodeTabuleiro *novo;
   novo = (NodeTabuleiro*)malloc(sizeof(NodeTabuleiro));


   /*

   Vai descendo a lista e os nos impares vao apontando para cima...

   NULL

   ^
   1

   ^
   |
   v

   2

   ^
   |
   v

   3

   ^
   |
   v

   4
   ^
   |
   v

   5

   ...


   */


   NodeTabuleiro *p; // Vai indo para baixo..
   for (p = le; p != NULL; p = p->baixo){
        if(anterior % 2 == 0){
            novo->cima = p;
            anterior++;
        } else {

            if(anterior == 1){
                le = NULL;
                anterior++;
            } else {
                 le = novo;
                 anterior++;


            }
        }

   }



}




void apontarParaDireita (NodeTabuleiro *le, NodeTabuleiro *li) {



   NodeTabuleiro *novo;
   novo = (NodeTabuleiro*)malloc(sizeof(NodeTabuleiro));


   /*

   Vai descendo a lista e os nos  vao apontando para a direita...

                    ^    ^
                    |    |
                    x -> y -> ...
                    |    |
                    v    v


   */


   NodeTabuleiro *p; // Vai indo para baixo..
   NodeTabuleiro *q;
   for (p = le, q = li; p != NULL; p = p->baixo, q = q->baixo){

        novo->dir = q;
        le = novo;

   }



}



void apontarParaDireitaLinhaL (NodeTabuleiro *le) {



   NodeTabuleiro *novo;
   novo = (NodeTabuleiro*)malloc(sizeof(NodeTabuleiro));


   /*

   Vai descendo a lista e os nos  vao apontando para a direita com o valor Nulo (ultima linha)..

                    ^    ^
                    |    |
                    x -> y -> NULL
                    |    |
                    v    v


   */


   NodeTabuleiro *p; // Vai indo para baixo..
   NodeTabuleiro *q;
   for (p = le; p != NULL; p = p->baixo){

        novo->dir = NULL;
        le = novo;

   }



}




void apontarParaEsquerda (NodeTabuleiro *le, NodeTabuleiro *li) {



   NodeTabuleiro *novo;
   novo = (NodeTabuleiro*)malloc(sizeof(NodeTabuleiro));


   /*

   Vai descendo a lista e os nos  vao apontando para a esquerda...

                    ^    ^
                    |    |
           ...  <-> x <->y <-> ...
                    |    |
                    v    v


   */


   NodeTabuleiro *p; // Vai indo para baixo..
   NodeTabuleiro *q;
   for (p = le, q = li; p != NULL; p = p->baixo, q = q->baixo){

        novo->esq = p;
        li = novo;

   }



}




void apontarParaEsquerdaLinhaA (NodeTabuleiro *le) {



   NodeTabuleiro *novo;
   novo = (NodeTabuleiro*)malloc(sizeof(NodeTabuleiro));


   /*

   Vai descendo a lista e os nos  vao apontando para a esquerda com o valor Nulo (ultima linha)..

                    ^     ^
                    |     |
           NULL <-> x <-> y <-> NULL
                    |     |
                    v     v


   */


   NodeTabuleiro *p; // Vai indo para baixo..
   NodeTabuleiro *q;
   for (p = le; p != NULL; p = p->baixo){

        novo->esq = NULL;
        le = novo;

   }



}
