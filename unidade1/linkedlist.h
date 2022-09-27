#include <stdio.h>
#include <stdlib.h>

// Listas ligadas são compostas por nós. Cada nó tem um valor e o ponteiro para o próximo nó. A primeira coisa que devemos fazer é criar a estrutura que representa o nó.
struct no
{
    int valor;
    struct no *proximo;
};

// Ao criar uma LinkedList precisamos criar uma variável para guardar o endereço do primeiro nó da lista. Este elemento é chamado de cabeça
struct linkedlist
{
    struct no *cabeca;
    int tamanho;
};

struct no *inicializarNo(int valor)
{
    struct no *novo_no = (struct no *)malloc(sizeof(struct no));
    novo_no->valor = valor;
    novo_no->proximo = NULL;

    return novo_no;
};

struct linkedlist *inicializarLista()
{
    struct linkedlist *nova_lista = (struct linkedlist *)malloc(sizeof(struct linkedlist));

    nova_lista->cabeca = NULL;
    nova_lista->tamanho = 0;
};

// Funções

void imprimirLista(struct linkedlist *lista)
{
    // usamos a aux para percorrer a lista
    if (lista->cabeca != NULL)
    {
        struct no *aux = lista->cabeca;
        // navega partindo da cabeça até chegar NULL
        printf("[");
        do
        {
            printf("%d", aux->valor);
            aux = aux->proximo;
            if (aux != NULL)
            {
                printf(", ");
            }
        } while (aux != NULL);
        printf("]\n");
    }
    else
    {
        printf("A lista está vazia!");
    }
}

void inserirElementoNoFim(struct linkedlist *lista, int valor)
{

    struct no *novo_no = inicializarNo(valor);

    if (lista->cabeca == NULL)
    { // quando a lista está vazia.
        lista->cabeca = novo_no;
    }
    else
    { // quando a lista não está vazia.
        struct no *aux = lista->cabeca;
        while (aux->proximo != NULL)
        {
            aux = aux->proximo;
        }
        aux->proximo = novo_no;
    }
    lista->tamanho += 1;
}

void inserirElementoNoInicio(struct linkedlist *lista, int valor)
{
    struct no *novo_no = inicializarNo(valor);

    novo_no->proximo = lista->cabeca;
    lista->cabeca = novo_no;

    lista->tamanho++;
}
void inserirElementoEmPosicao(struct linkedlist *lista, int valor, int posicao)
{
    if (posicao >= 0 && posicao < lista->tamanho)
    {
        struct no *novo_no = inicializarNo(valor), *anterior, *atual;
        atual = lista->cabeca;

        for (int i = 0; i < posicao; i++)
        {
            anterior = atual;
            atual = atual->proximo;
        }
        novo_no->proximo = atual;
        anterior->proximo = novo_no;

        lista->tamanho++;
    }
}
int obterElementoEmPosicao(struct linkedlist *lista, int posicao)
{
    if (posicao < lista->tamanho && posicao >= 0)
    {
        struct no *novo_no = lista->cabeca;

        for (int i = 0; i < posicao; i++)
        {
            novo_no = novo_no->proximo;
        }

        return novo_no->valor;
    }
    else
    {
        printf("Posicao invalida!");
    }
}
void removerElementoEmPosicao(struct linkedlist *lista, int posicao)
{
    if (posicao >= 0 && posicao < lista->tamanho)
    {
        if (posicao == 0)
        {
            lista->cabeca = lista->cabeca->proximo;
        }
        else
        {
            struct no* atual = lista->cabeca, *anterior;
            anterior = atual;

            for (int i = 0; i < posicao; i++)
            {
                anterior = atual;
                atual = atual->proximo;
            }

            anterior->proximo = atual->proximo;

            free(atual);
            lista->tamanho--;
        }
    }
}

void inverterLista (struct linkedlist* lista){
    
    struct no* anterior = NULL;   // o ponteiro anterior
    struct no* atual = lista->cabeca;   // o ponteiro atual
 
    // percorre a lista
    while (atual != NULL)
    {
        // complicado: observe o próximo nó
        struct no* proximo = atual->proximo;
 
        atual->proximo = anterior;    // corrige o nó atual
 
        // avança os dois ponteiros
        anterior = atual;
        atual = proximo;
    }
 
    // corrige o ponteiro de cabeça para apontar para a nova frente
    lista->cabeca = anterior;
}

void sortedInsert(struct Node** head, struct Node* newNode)
{
    struct Node dummy;
    struct Node* current = &dummy;
    dummy.next = *head;
 
    while (current->next != NULL && current->next->data < newNode->data) {
        current = current->next;
    }
 
    newNode->next = current->next;
    current->next = newNode;
    *head = dummy.next;
}


