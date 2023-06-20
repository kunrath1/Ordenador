#ifndef ORDENADORES_H
#define ORDENADORES_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>

using namespace std;


// Algoritmo de Ordenação por Seleção
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int indice = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[indice])
                indice = j;
        }
        swap(arr[i], arr[indice]);
    }
}

// Algoritmo de Ordenação por Trocas (Bubble Sort)
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

// Algoritmo de Ordenação por Intercalação (Merge Sort)
void merge(vector<int>& arr, int esq, int meio, int dir) {
    int n1 = meio - esq + 1;
    int n2 = dir - meio;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[esq + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[meio + 1 + j];

    int i = 0, j = 0, k = esq;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        }
        else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSort(vector<int>& arr, int esq, int dir) {
    if (esq < dir) {
        int meio = esq + (dir - esq) / 2;

        mergeSort(arr, esq, meio);
        mergeSort(arr, meio + 1, dir);

        merge(arr, esq, meio, dir);
    }
}

// Algoritmo de Ordenação por Inserção
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Função para gerar um vetor aleatório
vector<int> geradorVetAleatorios(int size) {
    vector<int> arr(size);
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100; // Altere o intervalo dos números aleatórios conforme necessário
    }
    return arr;
}

// Função para copiar um vetor
vector<int> copiarVet(const vector<int>& arr) {
    vector<int> copy(arr.size());
    copy = arr;
    return copy;
}

// Função para calcular a diferença de tempo em milissegundos
long long tempoCorrido(const chrono::high_resolution_clock::time_point& comeco, const chrono::high_resolution_clock::time_point& end) {
    return chrono::duration_cast<chrono::milliseconds>(end - comeco).count();
}

// Função para imprimir os elementos de um vetor
void exibirVet(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

#endif