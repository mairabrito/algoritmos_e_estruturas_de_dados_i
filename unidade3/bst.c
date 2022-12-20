#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main(void){
    
    struct noBst *raiz = NULL;
    inserir(&raiz, 12);
    inserir(&raiz, 8);
    inserir(&raiz, 14);
    inserir(&raiz, 4);
    inserir(&raiz, 10);
    inserir(&raiz, 18);
    inserir(&raiz, 2);
    inserir(&raiz, 6);
    inserir(&raiz, 16);
    inserir(&raiz, 20);

// Árvore a ser criada
  //        12
  //       /  \
  //      8    14
  //     / \     \
  //    4   10    18
  //   / \       /  \
  //  2   6     16   20

  //preOrdem: 12,8,4,2,6,10,14,18,16,20
  //posOrdem: 2,6,4,10,8,16,20,18,14,12


    imprimir(raiz);
    printf("\n%d\n", busca(raiz, 40));
    printf("%d\n", busca(raiz, 20));
    printf("%d\n", busca(raiz, 2));
    printf("%d\n", busca(raiz, 25));

    //Min iterativo
    int valorMinIt = minIt(raiz);
    printf("Valor MinIt: %d\n", valorMinIt);

    //Min Recursiva
    int valorMinRec = minRec(raiz);
    printf("Valor MinRec: %d\n", valorMinRec);

    //Max Iterativo
    int ValorMaxIt = maxIt(raiz);
    printf("Valor MaxIt: %d\n", ValorMaxIt);

    //Max Recursivo
    int ValorMaxRec = maxRec(raiz);
    printf("Valor MaxRec: %d\n", ValorMaxRec);

    //Altura
    int alturaBST = altura(raiz);
    printf("Altura da Bst: %d\n", alturaBST);

    //navNivel(raiz);
    navPreOrdem(raiz);
    printf("\n");
   // navEmOrdem(raiz);
    navPosOrdem(raiz);
    remover(raiz, 12);
     printf("\n");
    navPreOrdem(raiz);
    printf("\n");
   // navEmOrdem(raiz);
    printf("\n");
    navPosOrdem(raiz);

    




}