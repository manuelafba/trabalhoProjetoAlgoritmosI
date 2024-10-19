#include <iostream> 
#include "Sorting.cpp" 
#include <chrono> // Inclui a biblioteca para medir o tempo de execução

using namespace std; 

int main() { // Função principal do programa.
    Array array; // Declara uma variável do tipo Array, que será usada para armazenar os elementos.
    int escolhaQuantidade, escolhaDisposicao, escolhaAlgoritmo, escolhaExibir; // Variáveis para armazenar as escolhas do usuário.

    // Solicita ao usuário a quantidade de elementos para o vetor.
    cout << "Escolha a opcao da quantidade de elementos para o vetor: " << endl;
    cout << "1 - 10 elementos" << endl;
    cout << "2 - 1000 elementos" << endl;
    cout << "3 - 10000 elementos" << endl;
    cin >> escolhaQuantidade; // Lê a escolha do usuário.

    // Inicializa o vetor com base na escolha da quantidade de elementos.
    switch(escolhaQuantidade) {
        case 1:
            inicializaVetor(array, 10); break; // Inicializa com 10 elementos.
        case 2:
            inicializaVetor(array, 1000); break; // Inicializa com 1000 elementos.
        case 3:
            inicializaVetor(array, 10000); break; // Inicializa com 10000 elementos.
    }

    // Solicita ao usuário a disposição dos valores do vetor.
    cout << "Escolha a opcao da disposicao dos valores do vetor: " << endl;
    cout << "1 - Valores em ordem decrescente" << endl;
    cout << "2 - Valores em ordem aleatoria" << endl;
    cin >> escolhaDisposicao; // Lê a escolha do usuário.

    // Preenche o vetor de acordo com a escolha da disposição.
    switch(escolhaDisposicao) {
        case 1:
            vetorDecrescente(array); break; // Preenche com valores em ordem decrescente.
        case 2: 
            vetorAleatorio(array); break; // Preenche com valores aleatórios.
    }

    // Pergunta ao usuário se deseja exibir o vetor antes da ordenação.
    cout << "Deseja exibir o vetor antes da ordenacao? " << endl;
    cout << "1 - Sim " << endl;
    cout << "2 - Nao " << endl;
    cin >> escolhaExibir; // Lê a escolha do usuário.

    // Se o usuário deseja exibir o vetor, imprime o vetor.
    if (escolhaExibir == 1) {
        imprimeVetor(array); // Exibe os elementos do vetor.
    }

    // Solicita ao usuário a escolha do algoritmo de ordenação.
    cout << "Escolha a opcao do algoritmo de ordenacao desejado: " << endl;
    cout << "1 - Bubble Sort" << endl;
    cout << "2 - Quick Sort" << endl;
    cout << "3 - Counting Sort" << endl;
    cin >> escolhaAlgoritmo; // Lê a escolha do usuário.

    // Marca o tempo de início da execução.
    auto start = chrono::high_resolution_clock::now();

    // Executa o algoritmo de ordenação de acordo com a escolha do usuário.
    switch(escolhaAlgoritmo) {
        case 1:
            bubbleSort(array); break; // Chama a função Bubble Sort.
        case 2:
            quickSort(array, 0, array.tamanho - 1); break; // Chama a função Quick Sort.
        case 3:
            countingSort(array); break; // Chama a função Counting Sort.
    }

    // Marca o tempo de fim da execução.
    auto end = chrono::high_resolution_clock::now();
    // Calcula a duração da execução.
    chrono::duration<double> duration = end - start;

    // Exibe o vetor após a ordenação.
    imprimeVetor(array);
    // Exibe o número de comparações feitas durante a ordenação.
    cout << "Numero de comparacoes: " << array.comparacoes << endl;
    // Exibe o número de trocas feitas durante a ordenação.
    cout << "Numero de trocas: " << array.trocas << endl;
    // Exibe o tempo de execução em segundos.
    cout << "Tempo de execucao: " << duration.count() << " segundos" << endl;

    return 0; 
}
