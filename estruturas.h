#ifndef ESTRUTURAS_H_INCLUDED
#define ESTRUTURAS_H_INCLUDED

typedef struct _nodeTabuleiro{
    struct _nodeTabuleiro *cima;
    struct _nodeTabuleiro *baixo;
    struct _nodeTabuleiro *esq;
    struct _nodeTabuleiro *dir;
    int posicao;
    char embarcacao[2];
} NodeTabuleiro;


void l_inicTabuleiro(NodeTabuleiro **l);
void i_inserirTabuleiroParaBaixo(NodeTabuleiro **l, int posicaoN);
void apontarParaCimaNorPar (NodeTabuleiro *le);
void apontarParaCimaNorImpar (NodeTabuleiro *le);
void apontarParaDireita (NodeTabuleiro *le, NodeTabuleiro *li);
void apontarParaDireitaLinhaL (NodeTabuleiro *le);
void apontarParaEsquerda (NodeTabuleiro *le, NodeTabuleiro *li);
void apontarParaEsquerdaLinhaA (NodeTabuleiro *le);

#endif // ESTRUTURAS_H_INCLUDED
