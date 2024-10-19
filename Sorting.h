#include <iostream>

// Definição do TAD para o vetor
typedef struct Array{
    int* dado;
    int tamanho;
    int comparacoes;
    int trocas;
} Array;

// Cabeçalho das funções definidas
void inicializaVetor(Array &array, int n);
void imprimeVetor(const Array &array);
void vetorAleatorio(Array &array);
void vetorDecrescente(Array &array);
void bubbleSort(Array &array);
int particiona(Array &array, int esquerda, int direita);
void quickSort(Array &array, int esquerda, int direita);
void countingSort(Array &array);


