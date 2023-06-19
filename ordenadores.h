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
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
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
void merge(vector<int>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
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

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
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
vector<int> generateRandomVector(int size) {
    vector<int> arr(size);
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100; // Altere o intervalo dos números aleatórios conforme necessário
    }
    return arr;
}

// Função para copiar um vetor
vector<int> copyVector(const vector<int>& arr) {
    vector<int> copy(arr.size());
    copy = arr;
    return copy;
}

// Função para calcular a diferença de tempo em milissegundos
long long getElapsedTime(const chrono::high_resolution_clock::time_point& start, const chrono::high_resolution_clock::time_point& end) {
    return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

// Função para imprimir os elementos de um vetor
void printVector(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

#endif