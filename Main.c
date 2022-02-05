#include <stdio.h>
#include <stdlib.h>
#include "estruturas.c"




int main(){


    /*


    Irá criar 12 colunas de listas encadeadas com 12 linhas akém da posição para baixo;

    A   B   C  D  E  F  G  H  I  J  K  L

    1  13
    |  |
    v  v
    2  14
    |  |
    v  v
    3  15
    |  |
    v  v
    4  16
    |  |
    v  V
    5  17
    |  (...)
    v  Assim em diante
    6
    |
    v
    7
    |
    v
    8
    |
    v
    9
    |
    v
    10
    |
    v
    11
    |
    v
    12


    */
    NodeTabuleiro *listaA;
    NodeTabuleiro *listaB;
    NodeTabuleiro *listaC;
    NodeTabuleiro *listaD;
    NodeTabuleiro *listaE;
    NodeTabuleiro *listaF;
    NodeTabuleiro *listaG;
    NodeTabuleiro *listaH;
    NodeTabuleiro *listaI;
    NodeTabuleiro *listaJ;
    NodeTabuleiro *listaK;
    NodeTabuleiro *listaL;



    l_inicTabuleiro(&listaA);
    l_inicTabuleiro(&listaB);
    l_inicTabuleiro(&listaC);
    l_inicTabuleiro(&listaD);
    l_inicTabuleiro(&listaE);
    l_inicTabuleiro(&listaF);
    l_inicTabuleiro(&listaG);
    l_inicTabuleiro(&listaH);
    l_inicTabuleiro(&listaI);
    l_inicTabuleiro(&listaJ);
    l_inicTabuleiro(&listaK);
    l_inicTabuleiro(&listaL);



    for(int i = 1; i <= 12; i++){
        i_inserirTabuleiroParaBaixo(&listaA,i);
    }

    for(int i = 13; i <= 24; i++){
        i_inserirTabuleiroParaBaixo(&listaB,i);
    }


    for(int i = 25; i <= 36; i++){
        i_inserirTabuleiroParaBaixo(&listaC,i);
    }


    for(int i = 37; i <= 48; i++){
        i_inserirTabuleiroParaBaixo(&listaD,i);
    }


    for(int i = 49; i <= 60; i++){
        i_inserirTabuleiroParaBaixo(&listaE,i);
    }


    for(int i = 61; i <= 72; i++){
        i_inserirTabuleiroParaBaixo(&listaF,i);
    }


    for(int i = 73; i <= 84; i++){
        i_inserirTabuleiroParaBaixo(&listaG,i);
    }


    for(int i = 85; i <= 96; i++){
        i_inserirTabuleiroParaBaixo(&listaH,i);
    }


    for(int i = 97; i <= 108; i++){
        i_inserirTabuleiroParaBaixo(&listaI,i);
    }


    for(int i = 109; i <= 120; i++){
        i_inserirTabuleiroParaBaixo(&listaJ,i);
    }


    for(int i = 121; i <= 132; i++){
        i_inserirTabuleiroParaBaixo(&listaK,i);
    }


    for(int i = 133; i <= 144; i++){
        i_inserirTabuleiroParaBaixo(&listaL,i);
    }


    apontarParaCimaNorPar(listaA); //Faz a alocação para os numeros pares de nos para cima
    apontarParaCimaNorImpar(listaA); // Faz a alocação para os numeros impares de nos para cima


    // insere as alocações para direita...
    apontarParaDireita(listaA, listaB);
    apontarParaDireita(listaB, listaC);
    apontarParaDireita(listaC, listaD);
    apontarParaDireita(listaD, listaE);
    apontarParaDireita(listaE, listaF);
    apontarParaDireita(listaF, listaG);
    apontarParaDireita(listaG, listaH);
    apontarParaDireita(listaH, listaI);
    apontarParaDireita(listaI, listaJ);
    apontarParaDireita(listaJ, listaK);
    apontarParaDireita(listaK, listaL);

    apontarParaDireitaLinhaL(listaL);



    apontarParaEsquerda(listaA, listaB);
    apontarParaEsquerda(listaB, listaC);
    apontarParaEsquerda(listaC, listaD);
    apontarParaEsquerda(listaD, listaE);
    apontarParaEsquerda(listaE, listaF);
    apontarParaEsquerda(listaF, listaG);
    apontarParaEsquerda(listaG, listaH);
    apontarParaEsquerda(listaH, listaI);
    apontarParaEsquerda(listaI, listaJ);
    apontarParaEsquerda(listaJ, listaK);
    apontarParaEsquerda(listaK, listaL);

    apontarParaEsquerdaLinhaA(listaA);



    return 0;
}
