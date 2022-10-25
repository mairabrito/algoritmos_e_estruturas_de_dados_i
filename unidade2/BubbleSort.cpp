#include <stdio.h>
#include <stdlib.h>
#include <iostream>
/**
 * "O que o BubbleSort propõe que varramos esse array da esquerda para direita, múltiplas vezes. Em cada passada, iremos comparar os elementos vizinhos, e trocamos eles de posição caso o elemento da esquerda seja maior que o elemento da direita. Isto deve ser feito até chegar ao fim do array (ou pelo menos até a parte do array que ainda está desordenada)."
 * In-place, estável, O(n²) no pior caso, O(n) no melhor caso.
*/
using namespace std;

void troca(int* v, int i, int j){
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int bubbleSort (int *vDesordenado, int tamanho){
    for (int i=0; i<tamanho-1; i++){
        bool trocou = false;
        for(int j = 0; j < tamanho-i-1; j++){
            if(vDesordenado[j] > vDesordenado[j+1] ){
                troca(vDesordenado, j, j+1);
                trocou = true;
            }
        }
        if (trocou == false){
            return 0;
        }
    }
}

int main(){
    int *vetor = (int*)calloc(10, sizeof(int));
     for (int i=0; i<6; i++){
        vetor[i] = rand();
    }

    cout << "Vetor Desordenado:" << endl;
    for (int i=0; i<6; i++){
         cout << vetor[i] <<",";
    }
    cout << endl;
    
    bubbleSort(vetor, 6);
    
    cout << "Ordenado BubbleSort" << endl;
    for (int i=0; i<6; i++){
         cout << vetor[i] <<",";
    }


    return 0;
}