#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
//#include <sys/queue.h>
#include <unistd.h>

const int INT_MIN = -2147483647;

/*************************************
 * Fila para navegacao por niveis
 ************************************
TAILQ_HEAD(tailhead, entry) head;

struct entry {
  struct noAvl *raiz;
  TAILQ_ENTRY(entry) entries;
};

void add_to_queue(struct noAvl *raiz) {
  struct entry *elem = (struct entry *)malloc(sizeof(struct entry));
  if (elem)
    elem->raiz = raiz;
  TAILQ_INSERT_TAIL(&head, elem, entries);
}
/*************************************/

struct noAvl {
  struct noAvl *esq;
  int val, altura, bf;
  struct noAvl *dir;
};

void imprimir(struct noAvl *raiz) {
  if (raiz != NULL) {
    imprimir(raiz->esq);
    printf("%d (bf=%d), ", raiz->val, raiz->bf);
    imprimir(raiz->dir);
  }
}

/**
 * Funcao que aloca um novo noAvl.
 **/
struct noAvl *alocarNo(int val) {
  struct noAvl *no = (struct noAvl *)malloc(sizeof(struct noAvl));
  no->esq = NULL;
  no->val = val;
  no->altura = 0;
  no->bf = 0;
  no->dir = NULL;
  return no;
}

void atualizar(struct noAvl *raiz) {
  if (raiz != NULL) {
    int hEsq = 0, hDir = 0;
    if (raiz->esq != NULL)
      hEsq = raiz->esq->altura;
    if (raiz->dir != NULL)
      hDir = raiz->dir->altura;

    raiz->altura = 1 + (hEsq > hDir ? hEsq : hDir);
    raiz->bf = hDir - hEsq;
  }
}

struct noAvl *rotDireita(struct noAvl *raiz) {
  struct noAvl *novaRaiz = raiz->esq;
  raiz->esq = novaRaiz->dir;
  novaRaiz->dir = raiz;
  atualizar(raiz);
  atualizar(novaRaiz);
  return novaRaiz;
}

struct noAvl *rotEsquerda(struct noAvl *raiz) {
  struct noAvl *novaRaiz = raiz->dir;
  raiz->dir = novaRaiz->esq;
  novaRaiz->esq = raiz;
  atualizar(raiz);
  atualizar(novaRaiz);
  return novaRaiz;
}

struct noAvl *rebalancEsqEsq(struct noAvl *raiz) {
  return rotDireita(raiz);
}

struct noAvl *rebalancEsqDir(struct noAvl *raiz) {
  raiz->esq = rotEsquerda(raiz->esq);
  return rotDireita(raiz);
}

struct noAvl *rebalancDirDir(struct noAvl *raiz) {
  return rotEsquerda(raiz);
}

struct noAvl *rebalancDirEsq(struct noAvl *raiz) {
  raiz->dir = rotDireita(raiz->dir);
  return rotEsquerda(raiz);
}

struct noAvl *rebalanceamento(struct noAvl *raiz) {
  if (raiz != NULL) {
    if (raiz->bf == -2) {
      if (raiz->esq != NULL && raiz->esq->bf <= 0) // esq-esq
        raiz = rebalancEsqEsq(raiz);
      else // esq-dir
        raiz = rebalancEsqDir(raiz);
    } else if (raiz->bf == 2) {
      if (raiz->dir != NULL && raiz->dir->bf >= 0) // dir-dir
        raiz = rebalancDirDir(raiz);
      else // esq-dir
        raiz = rebalancDirEsq(raiz);
    }
  }
  return raiz;
}

/**
 * Funcao recursiva para inserir novo no.
 **/
void inserir(struct noAvl **raiz, int val) {
  if ((*raiz) == NULL)
    (*raiz) = alocarNo(val);
  else {
    if (val > (*raiz)->val)
      inserir(&(*raiz)->dir, val);
    else
      inserir(&(*raiz)->esq, val);

    atualizar(*raiz);
    //(*raiz) = rebalanceamento(*raiz);
  }
}

/**
 * Funcao recursiva para buscar valor.
 **/
bool buscar(struct noAvl *raiz, int val) {
  if (raiz == NULL) {
    return false;
  } else {
    if (raiz->val == val)
      return true;
    else if (raiz->val > val)
      return buscar(raiz->esq, val);
    else
      return buscar(raiz->dir, val);
  }
}

int minIt(struct noAvl *raiz) { // raiz eh local
  if (raiz == NULL)
    return INT_MIN;
  while (raiz->esq != NULL)
    raiz = raiz->esq;
  return raiz->val;
}

int minRec(struct noAvl *raiz) { // raiz eh local
  if (raiz == NULL)
    return INT_MIN;
  else if (raiz->esq != NULL)
    return minRec(raiz->esq);
  return raiz->val;
}

int maxBST(struct noAvl *raiz) { // raiz eh local
  if (raiz == NULL)
    return INT_MIN;
  else if (raiz->dir != NULL)
    return maxBST(raiz->dir);
  return raiz->val;
}

int max(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}

int altura(struct noAvl *raiz) {
  if (raiz == NULL)
    return -1;
  else {
    return 1 + max(altura(raiz->esq), altura(raiz->dir));
  }
}

/*
void navNivel(struct noAvl *raiz) {
  TAILQ_INIT(&head);
  // add a raiz na fila
  add_to_queue(raiz);

  struct entry *elem = head.tqh_first;
  // enquanto a fila não estiver vazia
  while (elem != NULL) {
    struct noAvl *noVisitado = elem->raiz;
    // imprimir/processar o elemento na frente da fila
    printf("%d, ", noVisitado->val);
    // adicionar as sub-árvores à fila
    if (noVisitado->esq != NULL)
      add_to_queue(noVisitado->esq);
    if (noVisitado->dir != NULL)
      add_to_queue(noVisitado->dir);

    // remover o nó que está na frente da fila
    TAILQ_REMOVE(&head, elem, entries);
    free(elem);
    elem = head.tqh_first;
  }
}*/

void navPreOrdem(struct noAvl *raiz) {
  if (raiz != NULL) {
    printf("%d, ", raiz->val);
    navPreOrdem(raiz->esq);
    navPreOrdem(raiz->dir);
  }
}

void navEmOrdem(struct noAvl *raiz) {
  if (raiz != NULL) {
    navEmOrdem(raiz->esq);
    printf("%d, ", raiz->val);
    navEmOrdem(raiz->dir);
  }
}

void navPosOrdem(struct noAvl *raiz) {
  if (raiz != NULL) {
    navPosOrdem(raiz->esq);
    navPosOrdem(raiz->dir);
    printf("%d, ", raiz->val);
  }
}

struct noAvl *remover(struct noAvl *raiz, int val) {
  if (raiz == NULL)
    return raiz;
  else if (val < raiz->val)
    raiz->esq = remover(raiz->esq, val);
  else if (val > raiz->val)
    raiz->dir = remover(raiz->dir, val);
  else { // val == raiz->val
    if (raiz->esq == NULL && raiz->dir == NULL) {
      free(raiz);
      raiz = NULL;
    } else if (raiz->dir == NULL) {
      struct noAvl *noASerRemovido = raiz;
      raiz = raiz->esq;
      free(noASerRemovido);
    } else if (raiz->esq == NULL) {
      struct noAvl *noASerRemovido = raiz;
      raiz = raiz->dir;
      free(noASerRemovido);
    } else { // possui dois filhos
      int maxEsq = maxBST(raiz->esq);
      raiz->val = maxEsq;
      raiz->esq = remover(raiz->esq, maxEsq);
    }
  }
  return raiz;
}