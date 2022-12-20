#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
//#include <sys/queue.h>
#include <unistd.h>

/*************************************
 * Fila para navegacao por niveis
 *************************************//**
TAILQ_HEAD(tailhead, entry) head;

struct entry {
  struct noBst *raiz;
  TAILQ_ENTRY(entry) entries;
};

void add_to_queue(struct noBst *raiz) {
  struct entry *elem = (struct entry *)malloc(sizeof(struct entry));
  if (elem)
    elem->raiz = raiz;
  TAILQ_INSERT_TAIL(&head, elem, entries);
}
/*************************************/

const int INT_MIN = -8745566;

struct noBst
{
    struct noBst *esq;
    struct noBst *dir;
    int valor;
};

/**
 * Função que aloca um novo noBst
 */
struct noBst *alocarNo(int valor)
{
    struct noBst *no = (struct noBst *)malloc(sizeof(struct noBst));
    no->esq = NULL;
    no->valor = valor;
    no->dir = NULL;
    return no;
}

/**
 * Função recursiva para inserir novo nó.
 */

//Recursivo
void inserir(struct noBst **raiz, int valor)
{
    if ((*raiz) == NULL)
    {
        (*raiz) = alocarNo(valor);
    }
    else
    {
        if (valor > (*raiz)->valor)
        {
            inserir(&(*raiz)->dir, valor);
        }
        else
        {
            inserir(&(*raiz)->esq, valor);
        }
    }
}

/**
 * Função recursiva para buscar valor
 */
bool busca(struct noBst *raiz, int valor)
{
    if (raiz == NULL)
    {
        return false;
    }
    else
    {
        if (raiz->valor == valor)
        {
            return true;
        }
        else if (raiz->valor > valor)
        {
            return busca(raiz->esq, valor);
        }
        else
        {
            return busca(raiz->dir, valor);
        }
    }
}

void imprimir(struct noBst *raiz)
{ // ordenado
    if (raiz != NULL)
    {
        imprimir(raiz->esq);
        printf("%d, ", raiz->valor);
        imprimir(raiz->dir);
    }
}

/**
 * Função para encontrar o mínimo valor (forma iterativa)
 */
int minIt(struct noBst *raiz)
{
    if (raiz == NULL)
    {
        return INT_MIN;
    }
    else
    {
        while (raiz->esq != NULL)
        {
            raiz = raiz->esq;
        }
    }
    return raiz->valor;
}

/**
 * Função para encontrar o mínimo valor (forma recursiva)
 */

int minRec(struct noBst *raiz)
{

    if (raiz == NULL){return INT_MIN;}
    else{
        if (raiz->esq != NULL){
            return minRec(raiz->esq);
        }
    }
    return raiz->valor;
}

/**
 * Função para encontrar o maior valor
 */
int maxIt(struct noBst *raiz)
{
    // iteração
    if (raiz == NULL){return INT_MIN;}
    else{while (raiz->dir != NULL){raiz = raiz->dir; }}
    return raiz->valor;
}

int maxRec(struct noBst *raiz){
    //Max recursivo
    if(raiz == NULL){return INT_MIN;}
    else{
        if(raiz->dir != NULL){
            return maxRec(raiz->dir);
        }
    }
    return raiz->valor;
}

int max(int a, int b) {
  if (a > b){
    return a;
  }
  else{
    return b;
    }
}

/**
 * nº de aresta entre raiz e folha mais distante
*/
int altura (struct noBst *raiz){
    if(raiz == NULL){
        return -1;
    } else{
    return 1+ max(altura(raiz->esq), altura(raiz->dir));
    }
}
/*
void navNivel(struct noBst *raiz) {
  TAILQ_INIT(&head); //instanciar  a fila
  // add a raiz na fila
  add_to_queue(raiz);

  struct entry *elem = head.tqh_first; //pega o primeiro elemento da fila
  // enquanto a fila não estiver vazia
  while (elem != NULL) {
    struct noBst *noVisitado = elem->raiz;
    // imprimir/processar o elemento na frente da fila
    printf("%d, ", noVisitado->val);
    //caso as sub-arvore existam add
    // adicionar as sub-árvores à fila
    if (noVisitado->esq != NULL)
      add_to_queue(noVisitado->esq);
    if (noVisitado->dir != NULL)
      add_to_queue(noVisitado->dir);

    // remover o nó que está na frente da fila, para ser capaz de pegar o proximo elemento
    TAILQ_REMOVE(&head, elem, entries);
    free(elem);
    elem = head.tqh_first;
  }
} */
// raiz, esq, dir
void navPreOrdem(struct noBst *raiz) {
  if (raiz != NULL) {
    printf("%d, ", raiz->valor);
    navPreOrdem(raiz->esq);
    navPreOrdem(raiz->dir);
  }
}
// esq,raiz, dir
void navEmOrdem(struct noBst *raiz) {
  if (raiz != NULL) {
    navEmOrdem(raiz->esq);
    printf("%d, ", raiz->valor);
    navEmOrdem(raiz->dir);
  }
}

//esq, dir, raiz
void navPosOrdem(struct noBst *raiz) {
  if (raiz != NULL) {
    navPosOrdem(raiz->esq);
    navPosOrdem(raiz->dir);
    printf("%d, ", raiz->valor);
  }
}


struct noBst *remover(struct noBst *raiz, int valor) {
  // buscamos o nó contendo valor
  if (raiz != NULL) {
    if (valor < raiz->valor)
      raiz->esq = remover(raiz->esq, valor);
    else if (valor > raiz->valor)
      raiz->dir = remover(raiz->dir, valor);
    else { // encontramos nó contendo valor
      if (raiz->esq == NULL && raiz->dir == NULL) { // caso1: nó folha
        free(raiz);
        raiz = NULL;
      } else if (raiz->esq == NULL) { // caso2: nó com um filho (dir)
        struct noBst *temp = raiz->dir;
        free(raiz);
        raiz = temp;
      } else if (raiz->dir == NULL) { // caso2: nó com um filho (esq)
        struct noBst *temp = raiz->esq;
        free(raiz);
        raiz = temp;
      } else {   //caso3: nó tem 2 filhos
        int maiorEsq = maxIt(raiz->esq);
        raiz->valor = maiorEsq;
        raiz->esq = remover(raiz->esq,maiorEsq);
      }
    }
  }
  return raiz;
}
