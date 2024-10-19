#include <iostream>
#include "Sorting.cpp"
#include <chrono>
using namespace std;

int main(){
    Array array;
    int escolhaQuantidade, escolhaDisposicao, escolhaAlgoritmo, escolhaExibir;

    cout << "Escolha a opcao da quantidade de elementos para o vetor: " << endl;
    cout << "1 - 10 elementos" << endl;
    cout << "2 - 1000 elementos" << endl;
    cout << "3 - 10000 elementos" << endl;
    cin >> escolhaQuantidade;

    switch(escolhaQuantidade) {
        case 1:
        inicializaVetor(array, 10); break;
        case 2:
        inicializaVetor(array, 1000); break;
        case 3:
        inicializaVetor(array, 10000); break;
    }

    cout << "Escolha a opcao da disposicao dos valores do vetor: " << endl;
    cout << "1 - Valores em ordem decrescente" << endl;
    cout << "2 - Valores em ordem aleatoria" << endl;
    cin >> escolhaDisposicao;

    switch(escolhaDisposicao) {
        case 1:
        vetorDecrescente(array); break;
        case 2: 
        vetorAleatorio(array); break;
    }

    cout << "Deseja exibir o vetor antes da ordenacao? " << endl;
    cout << "1 - Sim " << endl;
    cout << "2 - Nao " << endl;
    cin >> escolhaExibir;

    if (escolhaExibir == 1){
        imprimeVetor(array);
    }

    cout << "Escolha a opcao do algoritmo de ordenacao desejado: " << endl;
    cout << "1 - Bubble Sort" << endl;
    cout << "2 - Merge Sort" << endl;
    cin >> escolhaAlgoritmo;
    auto start = std::chrono::high_resolution_clock::now();

    switch(escolhaAlgoritmo){
        case 1:
        bubbleSort(array); break;
        case 2:
        mergeSort(array, 0, array.tamanho - 1);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    cout << "Tempo de execucao: " << duration.count() << " segundos" << endl;
    cout << "Vetor ordenado: " << endl;
    imprimeVetor(array);
    cout << "Numero de comparacoes: " << array.comparacoes << endl;
    cout << "Numero de trocas: " << array.trocas << endl;

    return 0;
}

