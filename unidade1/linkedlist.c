#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(){
    struct linkedlist* lista = inicializarLista();

    inserirElementoNoFim(lista,40);
    inserirElementoNoFim(lista,50);
    inserirElementoNoFim(lista,20);
    inserirElementoNoFim(lista,68);
    imprimirLista(lista);


    inserirElementoNoInicio(lista, 5);
    imprimirLista(lista);

    inserirElementoNoFim(lista,11);
    imprimirLista(lista);

    //printf("%d", obterElementoEmPosicao(lista, 3));
    
    inserirElementoEmPosicao(lista,7, 2);
    imprimirLista(lista);

    removerElementoEmPosicao(lista, 5);
    imprimirLista(lista);


    inverterLista(lista);
    imprimirLista(lista);

    return 0;
}



