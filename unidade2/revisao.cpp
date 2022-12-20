#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int const MAX = 10000;

void troca(int *v, int i, int j)
{
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
// in-place

void merge(int *v, int tv, int *e, int te, int *d, int td)
{
    int indexV = 0;
    int indexE = 0;
    int indexD = 0;

    while (indexE < te && indexD < td)
    {
        if (e[indexE] <= d[indexD])
        {
            v[indexV] = e[indexE];
            indexE++;
        }
        else
        {
            v[indexV] = d[indexD];
            indexD++;
        }

        indexV++;
    }

    while (indexE < te)
    {
        v[indexV] = e[indexE];
        indexE++;
        indexV++;
    }

    while (indexD < td)
    {
        v[indexV] = d[indexD];
        indexD++;
        indexV++;
    }

}

void mergeSort(int *v, int tamanho)
{

    if (tamanho > 1)
    {
        int meio = tamanho/2;
        int t1 = meio;
        

        int *v1 = (int *)calloc(t1, sizeof(int));
        for (int i = 0; i < t1; i++)
        {
            v1[i] = v[i];
        }

        int t2 = tamanho - meio;
        int *v2 = (int *)calloc(t2, sizeof(int));
        for (int i = meio; i < tamanho; i++)
        {
            v2[i - meio] = v[i];
        }

        mergeSort(v1, t1);
        mergeSort(v2, t2);
        merge(v, tamanho, v1, t1, v2, t2);

        free(v1);
        free(v2);
    }
}

int main()
{
    // Write C++ code here
    int *vDes1 = (int *)calloc(10, sizeof(int));
    vDes1[0] = 10;
    vDes1[1] = -5;
    vDes1[2] = 3;
    vDes1[3] = 80;
    vDes1[4] = 11;
    vDes1[5] = -3;

    for (int i = 0; i < 6; i++)
    {
        cout << vDes1[i] << ", ";
    }
    cout << endl;
    mergeSort(vDes1, 6);

    for (int i = 0; i < 6; i++)
    {
        cout << vDes1[i] << ", ";
    }

    return 0;
}