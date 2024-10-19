#include <iostream>
#include <cstdlib> 
#include <ctime>
#include "Sorting.h"
using namespace std;

void inicializaVetor(Array &array, int n) {
    array.tamanho = n;
    array.dado = new int[array.tamanho];
    array.comparacoes = 0;
    array.trocas = 0;
}

void imprimeVetor(const Array &array) {
    if (array.tamanho == 0) {
        cout << "O vetor está vazio!" << endl;
        return;
    }

    cout << "Elementos do vetor: ";
    for (int i = 0; i < array.tamanho; i++) {
        cout << array.dado[i] << " ";
    }
    cout << endl;
}

void vetorAleatorio(Array &array) {
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < array.tamanho; i++) {
        array.dado[i] = rand() % array.tamanho; 
    }
}

void vetorDecrescente(Array &array) {
    for (int i = 0; i < array.tamanho; i++) {
        array.dado[i] = array.tamanho - i;  
    }
}

void bubbleSort(Array &array) {
    for (int i = 0; i < array.tamanho - 1; i++) {
        for (int j = 0; j < array.tamanho - i - 1; j++) {
            array.comparacoes++;
            if (array.dado[j] > array.dado[j + 1]) {
                int aux = array.dado[j];
                array.dado[j] = array.dado[j + 1];
                array.dado[j + 1] = aux;
                array.trocas++;
            }
        }
    }
}

void merge(Array &array, int left, int mid, int right) {
    int n1 = mid - left + 1; // Tamanho do primeiro subarray
    int n2 = right - mid;    // Tamanho do segundo subarray

    // Criar arrays temporários
    int* L = new int[n1];
    int* R = new int[n2];

    // Copiar dados para os arrays temporários L[] e R[]
    for (int i = 0; i < n1; i++)
        L[i] = array.dado[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = array.dado[mid + 1 + j];

    // Mesclar os arrays temporários de volta em array[left..right]
    int i = 0; // Índice inicial do primeiro subarray
    int j = 0; // Índice inicial do segundo subarray
    int k = left; // Índice inicial da mesclagem

    while (i < n1 && j < n2) {
        array.comparacoes++;
        if (L[i] <= R[j]) {
            array.dado[k] = L[i];
            i++;
        } else {
            array.dado[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar os elementos restantes de L[], se houver
    while (i < n1) {
        array.dado[k] = L[i];
        i++;
        k++;
    }

    // Copiar os elementos restantes de R[], se houver
    while (j < n2) {
        array.dado[k] = R[j];
        j++;
        k++;
    }
}

// Função principal do Merge Sort
void mergeSort(Array &array, int left, int right) {
    if (left < right) {
        // Encontrar o ponto médio
        int mid = left + (right - left) / 2;

        // Ordenar as duas metades
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);

        // Mesclar as duas metades
        merge(array, left, mid, right);
    }
}