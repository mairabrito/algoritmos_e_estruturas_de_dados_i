#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int const MAX = 10000;

void troca(int* v, int i, int j){
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
//in-place
void selectionSortIP (int *vDesordenado, int tamanho){

    for (int i=0; i<tamanho; i++){
        int menor = i;
        for (int j=i+1; j<tamanho; j++){
            if(vDesordenado[j] < vDesordenado[menor]){
                menor = j;
            }
        }
        troca(vDesordenado, i, menor);
    }
}

//out-of-place
void selectionSortOut (int *vDesordenado, int tamanho){
    int *vOrdenado = (int*)calloc(tamanho, sizeof(int));
    for (int i=0; i<tamanho; i++){
        int menor = i;
        for (int j=0; j<tamanho; j++){
            if(vDesordenado[j] < vDesordenado[menor]){
                menor = j;
            }
        }
        
        vOrdenado[i] = vDesordenado[menor];
        vDesordenado[menor] = MAX;
    }
    for (int i=0; i<tamanho; i++){
        cout << vOrdenado[i] <<",";
    }
}

int main() {
    // Write C++ code here
    int *vDes1 = (int*)calloc(10, sizeof(int));
    vDes1[0] = 10;
    vDes1[1] = -5;
    vDes1[2] = 3;
    vDes1[3] = 80;
    vDes1[4] = 11;
    vDes1[5] =-3;

    int *vDes2 = (int*)calloc(10, sizeof(int));
    vDes2[0] = 105;
    vDes2[1] = -45;
    vDes2[2] = 35;
    vDes2[3] = 8;
    vDes2[4] = 1;
    vDes2[5] =-3;
  
    cout << "Vetor Desordenado:" << endl;
    for (int i=0; i<6; i++){
         cout << vDes1[i] <<",";
    }
    cout << endl;
    
    selectionSortIP(vDes1, 6);
    
    cout << "Ordenado SelectionSort In-Place:" << endl;
    for (int i=0; i<6; i++){
         cout << vDes1[i] <<",";
    }

    cout << endl << endl;
    cout << "Vetor Desordenado:" << endl;
    for (int i=0; i<6; i++){
         cout << vDes2[i] <<",";
    }
    cout << endl;
    cout << "Ordenado SelectionSort Out-of-Place:" << endl;
    selectionSortOut(vDes2, 6);
    
    
 
    return 0;
}