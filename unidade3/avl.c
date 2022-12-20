#include "avl.h"
#include <stdio.h>

int main(void) {

  struct noAvl *raiz = NULL;

  for (int i = 0; i < 20; i++)
    inserir(&raiz, i);

  imprimir(raiz);
}