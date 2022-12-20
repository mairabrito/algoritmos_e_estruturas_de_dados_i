// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

void swap(int* v, int i, int j){
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int particiona(int* v, int ini, int fim){
    int pIndex = ini;
    int pivo = v[fim];
    //int pivo = rand () % (fim-0+1);
    for(int i = ini; i < fim; i++){
        if(v[i] <= pivo){
            swap(v,i,pIndex);
            pIndex++;
        }
    }
    swap(v,pIndex,fim);
    return pIndex;
}

void quickSort(int *v, int inicio, int fim){
    if(fim>inicio){
        int indexPivor = particiona(v, inicio, fim);
        quickSort(v, inicio, indexPivor-1);
        quickSort(v, indexPivor+1, fim);
    }
}

int main() {

    int *vDes = (int*)calloc(10, sizeof(int));
    vDes[0] = 5;
    vDes[1] = 2;
    vDes[2] = 7;
    vDes[3] = 1;
    vDes[4] = 88;
    vDes[5] =-8;
   
    cout << "Desordenado:" << endl;
    for (int i=0; i<6; i++){
         cout << vDes[i] <<",";
    }
    cout << endl;
    
    quickSort(vDes, 0, 5);
    
    cout << "Ordenado:" << endl;
    for (int i=0; i<6; i++){
         cout << vDes[i] <<",";
    }
    return 0;
}