#include <iostream> 
#include <cstdlib>  // Biblioteca para a função rand()
#include <ctime>    // Biblioteca para manipulação de tempo
#include "Sorting.h" 
using namespace std; 

// Função para inicializar o vetor
void inicializaVetor(Array &array, int n) {
    array.tamanho = n; // Define o tamanho do vetor
    array.dado = new int[array.tamanho]; // Aloca dinamicamente um vetor de inteiros
    array.comparacoes = 0; // Inicializa o contador de comparações
    array.trocas = 0; // Inicializa o contador de trocas
}

// Função para imprimir o vetor
void imprimeVetor(const Array &array) {
    if (array.tamanho == 0) { // Verifica se o vetor está vazio
        cout << "O vetor está vazio!" << endl; // Exibe mensagem se o vetor está vazio
        return; // Sai da função
    }

    cout << "Elementos do vetor: "; // Inicia a impressão dos elementos
    for (int i = 0; i < array.tamanho; i++) { // Loop para percorrer o vetor
        cout << array.dado[i] << " "; // Imprime cada elemento
    }
    cout << endl; // Nova linha após a impressão
}

// Função para preencher o vetor com valores aleatórios
void vetorAleatorio(Array &array) {
    srand(static_cast<unsigned int>(time(0))); // Inicializa o gerador de números aleatórios com a hora atual
    for (int i = 0; i < array.tamanho; i++) { // Loop para preencher o vetor
        array.dado[i] = rand() % array.tamanho; // Atribui um valor aleatório entre 0 e o número de elementos do vetor
    }
}

// Função para preencher o vetor com valores em ordem decrescente
void vetorDecrescente(Array &array) {
    for (int i = 0; i < array.tamanho; i++) { // Loop para preencher o vetor
        array.dado[i] = array.tamanho - i; // Atribui valores decrescentes
    }
}

// Função para realizar o Bubble Sort
void bubbleSort(Array &array) {
    for (int i = 0; i < array.tamanho - 1; i++) { // Loop externo para controle das passagens
        for (int j = 0; j < array.tamanho - i - 1; j++) { // Loop interno para comparar elementos adjacentes
            array.comparacoes++; // Incrementa o contador de comparações
            if (array.dado[j] > array.dado[j + 1]) { // Verifica se os elementos estão fora de ordem
                int aux = array.dado[j]; // Armazena o valor de array.dado[j]
                array.dado[j] = array.dado[j + 1]; // Troca os elementos
                array.dado[j + 1] = aux; // Finaliza a troca
                array.trocas++; // Incrementa o contador de trocas
            }
        }
    }
}

// Função para particionar o vetor (usada no Quick Sort)
int particiona(Array &array, int esquerda, int direita) {
    int pivo = array.dado[esquerda]; // Seleciona o pivô
    int i = esquerda; // Inicializa o índice do menor elemento

    for (int j = esquerda + 1; j <= direita; j++) { // Loop para percorrer os elementos
        array.comparacoes++; // Incrementa o contador de comparações
        if (array.dado[j] <= pivo) { // Se o elemento atual for menor ou igual ao pivô
            i += 1; // Incrementa o índice do menor elemento
            int aux = array.dado[i]; // Armazena o valor de array.dado[i]
            array.dado[i] = array.dado[j]; // Troca os elementos
            array.dado[j] = aux; // Finaliza a troca
            array.trocas++; // Incrementa o contador de trocas
        }
    }

    int aux = array.dado[esquerda]; // Armazena o valor do pivô
    array.dado[esquerda] = array.dado[i]; // Troca o pivô com o elemento na posição i
    array.dado[i] = aux; // Finaliza a troca
    array.trocas++; // Incrementa o contador de trocas

    return i; // Retorna o índice do pivô
}

// Função para realizar o Quick Sort
void quickSort(Array &array, int esquerda, int direita) {
    if (esquerda < direita) { // Se houver mais de um elemento
        int indexPivo = particiona(array, esquerda, direita); // Chama a função de particionamento
        quickSort(array, esquerda, indexPivo - 1); // Ordena a parte esquerda do vetor
        quickSort(array, indexPivo + 1, direita); // Ordena a parte direita do vetor
    }
}

// Função para realizar o Counting Sort
void countingSort(Array &array) {
    int valorMaximo = array.dado[0]; // Inicializa o maior valor como o primeiro elemento
    array.comparacoes++;  // Contagem da comparação inicial

    for (int i = 1; i < array.tamanho; i++) { // Loop para encontrar o maior valor
        array.comparacoes++;  // Incrementa contador de comparações
        if (array.dado[i] > valorMaximo) { // Se o valor atual for maior que o maior encontrado
            valorMaximo = array.dado[i]; // Atualiza o maior valor
        }
    }

    // Cria um array de contagem inicializado com zero
    int* contagem = new int[valorMaximo + 1]{0}; // Array de contagem

    // Contagem de cada elemento
    for (int i = 0; i < array.tamanho; i++) { // Loop para contar os elementos
        contagem[array.dado[i]]++; // Incrementa a contagem para o valor atual
        array.trocas++;  // Incrementa contador de "trocas" ao incrementar
    }

    // Modifica o array de contagem para que ele contenha a posição de cada elemento
    for (int i = 1; i <= valorMaximo; i++) { // Loop para modificar as contagens
        contagem[i] += contagem[i - 1]; // Acumula as contagens
    }

    // Array de saída ordenado
    int* saida = new int[array.tamanho]; // Cria um array para os elementos ordenados
    for (int i = array.tamanho - 1; i >= 0; i--) { // Loop para preencher o array de saída
        saida[contagem[array.dado[i]] - 1] = array.dado[i]; // Coloca o elemento na posição correta
        contagem[array.dado[i]]--; // Decrementa a contagem
        array.trocas++;  // Incrementa contador de "trocas" ao colocar o valor no array de saída
    }

    // Copia os elementos do array de saída para o array original
    for (int i = 0; i < array.tamanho; i++) { // Loop para copiar os valores
        array.dado[i] = saida[i]; // Copia o valor do array de saída para o array original
        array.trocas++;  // Incrementa contador de "trocas" ao copiar o valor de volta
    }
}
