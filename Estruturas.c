#include<stdio.h>
#include<stdlib.h>

struct CasaNo{
    struct CasaNo *cima;
    struct CasaNo *baixo;
    struct CasaNo *esq;
    struct CasaNo *dir;
    char valor;
}CasaNo;

struct Tabuleiro {
    struct CasaNo *inicio; //Ponto inicial do tabuleiro 1-A
    struct CasaNo *ultimoVertical;
    struct CasaNo *ultimoHorizontal;
}Tabuleiro;


void IniciaCasaNo(struct CasaNo *casaNo , char tipoNavio){ //Aponta tudo pra nulo e atribui um valor pro nó inicial
    casaNo->baixo = NULL;
    casaNo->cima = NULL;
    casaNo->esq = NULL;
    casaNo->dir = NULL;
    casaNo->valor = tipoNavio;
}

void AlocaCasaNo(struct CasaNo **casaNo, char tipoNavio){ //Aloca espaço da memória pra Casa inicial
    *casaNo = malloc(sizeof(CasaNo));
    IniciaCasaNo(*casaNo, tipoNavio);

}

void PrintaCasaNo(struct CasaNo *casaNo){ //Printa nó
    printf("Valor da casa: %c", casaNo->valor);
}

void IniciaTabuleiro(struct Tabuleiro *tabuleiro){
    struct CasaNo *no;
    AlocaCasaNo(&no, ' ');

    tabuleiro->inicio = no;
    tabuleiro->ultimoHorizontal = no;
    tabuleiro->ultimoVertical = no;
}

void CriarTabuleiroVazio(struct Tabuleiro *tabuleiro){ //Criar uma lista de 4 direções duplamente encadeada
    struct CasaNo *aux = tabuleiro->inicio;

    for(int i = 0;i<12;i++){ //percorrer horizontal
        
        for(int j = 0; j<12; j++){ //percorrer na vertical
            struct CasaNo *novoNo; //criar um no temporario pra percorrer vertical
            AlocaCasaNo(&novoNo, ' ');  //aloca na memoria
            tabuleiro->ultimoVertical->baixo = novoNo; //aponta pra baixo um novo nó pra percorrer até o ultimo
            novoNo->cima = tabuleiro->ultimoVertical; //Aponta para o antigo último
            tabuleiro->ultimoVertical = novoNo; //Definindo o último

        }
        struct CasaNo *novoNo2;
        AlocaCasaNo(&novoNo2, ' ');
        tabuleiro->ultimoHorizontal->dir = novoNo2;
        novoNo2->esq = tabuleiro->ultimoHorizontal;
        tabuleiro->ultimoHorizontal = novoNo2;
        tabuleiro->ultimoVertical = novoNo2; //Reinciar o ultimo Vertical, já que ele terá que percorrer uma nova coluna 
    }
}