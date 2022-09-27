#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"


int main(void){
    struct arraylist* lista = inicializar(5);
    inserirElementoNoFim(lista, 1);
    inserirElementoNoFim(lista, 4);
    inserirElementoNoFim(lista, 5);
    inserirElementoNoFim(lista, 6);
    inserirElementoNoFim(lista, 2);
    inserirElementoNoFim(lista, 48);
    inserirElementoNoFim(lista, 7);
    //inserirElementoNoFim(lista, 8);
    //inserirElementoNoFim(lista, 9);
    //inserirElementoNoFim(lista, 10);

    //printf("%d", obterElementoEmPosicao(lista, 5));
    //printf("\n%d", obterElementoEmPosicao(lista, 10));
    
    exibirLista(lista);
    inverterLista(lista, lista->quantidade);
    //exibirLista(lista);

    inserirElementoEmPosicao(lista, 88, 3);
    exibirLista(lista);
   
    //removerElementoEmPosicao(lista, 3);
    //exibirLista(lista);
   
    //removerElementoNoFim(lista);
    //exibirLista(lista);

    ordenarCrescente(lista, lista->quantidade);
    exibirLista(lista);

    //inserirElementoEmPosicao(lista, 45, 25);
    //exibirLista(lista);

    ordenarDecrescente(lista, lista->quantidade);
    exibirLista(lista);
    //printf("%d", lista->vetor[2]);
    return 0;
};
 