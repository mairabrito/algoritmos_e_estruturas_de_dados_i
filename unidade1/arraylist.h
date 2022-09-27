#include <stdio.h>
#include <stdlib.h>

struct arraylist {
    int* vetor; //alocar o vetor
    int quantidade; //Quantidade de elementos inseridos no vetor
    int capacidade; // capacidade atual do vetor
};

//inicializar o arraylist
struct arraylist* inicializar(int capacidade) {
    struct arraylist* lista = (struct arraylist*)malloc(sizeof(struct arraylist));
    lista->vetor = (int*)calloc(capacidade, sizeof(int));
    lista->quantidade = 0;
    lista->capacidade = capacidade;
    return lista;
}

int obterElementoEmPosicao(struct arraylist* lista, int posicao) {
    if (posicao >= 0 && posicao < lista->capacidade) {
        return lista->vetor[posicao];
   }
    return 0;
}

void duplicarCapacidade(struct arraylist* lista) {
    lista->vetor = (int*)realloc(lista->vetor, 2 * lista->capacidade * sizeof(int));
    lista->capacidade = 2 * lista->capacidade;
}

void inserirElementoNoFim(struct arraylist* lista, int valor) {
    if (lista->quantidade == lista->capacidade) {
     duplicarCapacidade(lista);
    }
    lista->vetor[lista->quantidade] = valor; // vetor[0] = valor
    lista->quantidade++; // 0+1
}

void inserirElementoEmPosicao(struct arraylist* lista, int valor, int posicao) {
   if (posicao >= 0 && posicao <= lista->quantidade) {
        if (lista->quantidade == lista->capacidade) {
            duplicarCapacidade(lista);
        }
        int indice = lista->quantidade;
        while (posicao < indice) {
            lista->vetor[indice] = lista->vetor[indice-1];
            indice--;
        }
        lista->vetor[posicao] = valor;
        lista->quantidade++;
    }
}

void atualizarElemento(struct arraylist* lista, int valor, int posicao) {
    if (posicao >= 0 && posicao < lista->quantidade) {
        lista->vetor[posicao] = valor;
    }
}

void removerElementoNoFim(struct arraylist* lista) {
    lista->quantidade = lista->quantidade - 1;
}

void removerElementoEmPosicao(struct arraylist* lista, int posicao) {
    if (posicao >= 0 && posicao < lista->quantidade) {
        for (int indice = posicao; indice < lista->quantidade - 1; indice++) {
            lista->vetor[indice] = lista->vetor[indice + 1];
        }
        lista->quantidade--;
    }
}

void exibirLista(struct arraylist* lista) {
    printf("[");
    for (int i = 0; i < lista->quantidade; i++) {
        printf("%d", lista->vetor[i]);
        if (i < lista->quantidade - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void inverterLista (struct arraylist* lista, int n){

    int inicio = 0;
    int fim = n-1;
    //printf("%d", fim);
    int aux = 0;

    while(inicio<fim){
        aux =lista->vetor[inicio];
        lista->vetor[inicio] = lista->vetor[fim];
        lista->vetor[fim] = aux;
        inicio++;
        fim--;
    }
}

void ordenarCrescente (struct arraylist* lista, int tamanho){
    int temporariaTroca;

    for(int i=0; i<tamanho; i++){
        for(int j=i; j<tamanho; j++){
            if(lista->vetor[j] < lista->vetor[i]){
                temporariaTroca = lista->vetor[j];
                lista->vetor[j] = lista->vetor[i];
                lista->vetor[i] = temporariaTroca;
            }
        }
    }
}

void ordenarDecrescente(struct arraylist* lista, int tamanho){
    int temporariaTroca;
    
    for(int i=0; i<tamanho; i++){
        for(int j=i; j<tamanho; j++){
            if(lista->vetor[j] > lista->vetor[i]){
                temporariaTroca = lista->vetor[j];
                lista->vetor[j] = lista->vetor[i];
                lista->vetor[i] = temporariaTroca;
            }
        }
    }
}