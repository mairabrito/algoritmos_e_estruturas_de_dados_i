# Preview 
    Algoritmos de ordenação geralmete são classificados quando a:
    - Complexidade de tempo;
    - Complexidade de espaço (ou uso de memória):
        - in-place (quantidade de memória usada é constante).
        - out-place (quantidade de memória usada cresce com o tamanho de entrada). // chamadas recursivas
    - estabilidade
        - imagine a seguinte combinação de cartas: [3(espada),6(coração),2(espada),5(paus),3(ouro)]
            - Um algoritmo estável preserva a ordem relativa de elementos: [2(espada),3(espada),3(ouro),5(paus),6(coração)];
            - Um algoritmo instável não garante preservar a ordem relativa de elementos: [2(espada),3(ouro),3(espada),5(paus),6(coração)].
    - interna ou externa
        -interna: o algoritmo executa completamente usando apenas memória primária
        -externa: o algoritmo executa usando tanto memória primária como memória secundária
    - recursivo (MergeSort e QuickSort) ou iterativo (SelectionSort, InsertionSort)
