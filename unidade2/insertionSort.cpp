#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/**
 * No melhor caso, um array ordenado, InsertionSort é O(n). O for interno nunca é executado.
 * No pior caso, um array ordenado de forma decrescente, InsertionSort é O(n²).
 */

void troca(int *v, int i, int j)
{
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/*void insertionSort(int *vDesordenado, int tamanho)
{
    int *vOrdenado = (int *)calloc(tamanho, sizeof(int));
    vOrdenado[0] = vDesordenado[0];
    for (int i = 1; i < tamanho; i++)
    {
        vOrdenado[i] = vDesordenado[i];
        for (int j = 0; j < i; j++)
        {
            if (vOrdenado[j] > vOrdenado[i])
            {
                troca(vOrdenado, i, j);
            }
        }
    }

    for (int i = 0; i < tamanho; i++)
    {
        cout << vOrdenado[i] << ",";
    }
}*/
void insertionSortIP(int* v, int tamanho) {
    for (int i = 1; i < tamanho; i++) {   //i = indice da carta a ser inserida ordenada
        for (int j = i; j > 0; j--) {
            if (v[j - 1] > v[j]) {
                int temp = v[j - 1];
                v[j - 1] = v[j];
                v[j] = temp;
            }
            else {
                break;
            }
        }
    }
}


int main()
{

    int *vDes1 = (int *)calloc(10, sizeof(int));
    vDes1[0] = 10; // 10
    vDes1[1] = 5;  // 10 5 => 5 10
    vDes1[2] = 3;  // 5 10 3 => 3 10 5 => 3 5 10
    vDes1[3] = 85; // 3 5 10 85
    vDes1[4] = 11; // 3 5 10 85 11 => 3 5 10 85 11 => 3 5 10 85 11 => 3 5 10 11 85
    vDes1[5] = -3; //-3 5 10 11 85 3 => -3 3 10 11 85 5 => -3 3 5 11 85 10 => -3 3 5 10 85 11 => -3 3 5 10 11 85

    cout << "Vetor Desordenado:" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << vDes1[i] << ",";
    }
    cout << endl;

    insertionSortIP(vDes1, 6);

    for (int i = 0; i < 6; i++)
    {
        cout << vDes1[i] << ",";
    }

    return 0;
}