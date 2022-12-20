// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

void countSort(int *v, int tamanho){
    int menor = v[0];
    int maior = v[0];
    
    for(int i= 0; i<tamanho; i++){
        if(v[i] < menor){
            menor = v[i];
        } else if (v[i] > maior){
            maior = v[i];
        }
    }
    
    int tamanhoAux = maior-menor+1;
    int *contagem = (int*)calloc(tamanhoAux, sizeof(int));
    int *o = (int*)calloc(tamanho, sizeof(int));
    

    for(int i = 0; i <tamanhoAux; i++){
        for(int j= 0; j<tamanho; j++){
            if(v[j] == i+2){
                contagem[i] = 1;
            } 
        }
    }
    
     for(int i=0; i<tamanhoAux; i++){
        cout << contagem[i] << ",";
    }
   
    for(int i = 1; i <tamanhoAux; i++){
        contagem[i] =  contagem[i] +contagem[i-1];
    }
    
    cout << endl;
    for(int i=0; i<tamanhoAux; i++){
        cout << contagem[i] << ",";
    }
    
    for(int i=0; i<tamanho; i++){
        o[(contagem[v[i]-menor]-1)] = v[i];
    }
    cout << endl;
    for(int i=0; i<tamanho; i++){
        cout << o[i] << ",";
    }
}
//1 2 2 3 4 4 5

int main() {
    // Write C

    int tamanho = 5;
    int *vetor = (int*)calloc(tamanho, sizeof(int));
    
    vetor[0] = 6;
    vetor[1] = 2;
    vetor[2] = 8;
    vetor[3] = 5;
    vetor[4] = 3;
    
    for(int i=0; i<tamanho; i++){
        cout << vetor[i] << ",";
    }
    cout << endl;
    
    countSort(vetor, tamanho);

    return 0;
}