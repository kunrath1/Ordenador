#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <numeric>
#include "ordenadores.h"
using namespace std;

int main() {
    srand(static_cast<unsigned>(time(0))); // Seed random number generator

    int M, N, X;
    cout << "Digite a quantidade de vetores (M): ";
    cin >> M;
    cout << "Digite o tamanho de cada vetor (N): ";
    cin >> N;
    cout << "Digite o número de vezes a executar cada algoritmo (X): ";
    cin >> X;

    vector<vector<int>> vectors(M);
    vector<long long> elapsedTimeSelection(X), elapsedTimeBubble(X), elapsedTimeMerge(X), elapsedTimeInsertion(X);

    for (int i = 0; i < M; ++i) {
        vectors[i] = generateRandomVector(N);
    }

    vector<int> bestCase = generateRandomVector(N);
    sort(bestCase.begin(), bestCase.end());

    vector<int> worstCase = generateRandomVector(N);
    sort(worstCase.begin(), worstCase.end(), greater<int>());

    for (int i = 0; i < X; ++i) {
        for (int j = 0; j < M; ++j) {
            vector<int> arr;

            if (j == 0) {
                arr = bestCase;
            } else if (j == 1) {
                arr = worstCase;
            } else {
                arr = copyVector(vectors[j - 2]);
            }

            chrono::high_resolution_clock::time_point start, end;

            // Algoritmo de Ordenação por Seleção
            start = chrono::high_resolution_clock::now();
            selectionSort(arr);
            end = chrono::high_resolution_clock::now();
            elapsedTimeSelection[i] = getElapsedTime(start, end);

            // Algoritmo de Ordenação por Trocas (Bubble Sort)
            arr = copyVector(vectors[j]);
            start = chrono::high_resolution_clock::now();
            bubbleSort(arr);
            end = chrono::high_resolution_clock::now();
            elapsedTimeBubble[i] = getElapsedTime(start, end);

            // Algoritmo de Ordenação por Intercalação (Merge Sort)
            arr = copyVector(vectors[j]);
            start = chrono::high_resolution_clock::now();
            mergeSort(arr, 0, arr.size() - 1);
            end = chrono::high_resolution_clock::now();
            elapsedTimeMerge[i] = getElapsedTime(start, end);

            // Algoritmo de Ordenação por Inserção
            arr = copyVector(vectors[j]);
            start = chrono::high_resolution_clock::now();
            insertionSort(arr);
            end = chrono::high_resolution_clock::now();
            elapsedTimeInsertion[i] = getElapsedTime(start, end);
        }
    }

    // Cálculo das estatísticas
    long long maxSelection = *max_element(elapsedTimeSelection.begin(), elapsedTimeSelection.end());
    long long minSelection = *min_element(elapsedTimeSelection.begin(), elapsedTimeSelection.end());
    double avgSelection = accumulate(elapsedTimeSelection.begin(), elapsedTimeSelection.end(), 0.0) / X;

    long long maxBubble = *max_element(elapsedTimeBubble.begin(), elapsedTimeBubble.end());
    long long minBubble = *min_element(elapsedTimeBubble.begin(), elapsedTimeBubble.end());
    double avgBubble = accumulate(elapsedTimeBubble.begin(), elapsedTimeBubble.end(), 0.0) / X;

    long long maxMerge = *max_element(elapsedTimeMerge.begin(), elapsedTimeMerge.end());
    long long minMerge = *min_element(elapsedTimeMerge.begin(), elapsedTimeMerge.end());
    double avgMerge = accumulate(elapsedTimeMerge.begin(), elapsedTimeMerge.end(), 0.0) / X;

    long long maxInsertion = *max_element(elapsedTimeInsertion.begin(), elapsedTimeInsertion.end());
    long long minInsertion = *min_element(elapsedTimeInsertion.begin(), elapsedTimeInsertion.end());
    double avgInsertion = accumulate(elapsedTimeInsertion.begin(), elapsedTimeInsertion.end(), 0.0) / X;

    // Exibição dos resultados
    cout << "Resultados:" << endl;
    cout << "Algoritmo de Ordenação por Seleção:" << endl;
    cout << "Maior tempo: " << maxSelection << " ms" << endl;
    cout << "Menor tempo: " << minSelection << " ms" << endl;
    cout << "Média: " << avgSelection << " ms" << endl;
    cout << endl;

    cout << "Algoritmo de Ordenação por Trocas (Bubble Sort):" << endl;
    cout << "Maior tempo: " << maxBubble << " ms" << endl;
    cout << "Menor tempo: " << minBubble << " ms" << endl;
    cout << "Média: " << avgBubble << " ms" << endl;
    cout << endl;

    cout << "Algoritmo de Ordenação por Intercalação (Merge Sort):" << endl;
    cout << "Maior tempo: " << maxMerge << " ms" << endl;
    cout << "Menor tempo: " << minMerge << " ms" << endl;
    cout << "Média: " << avgMerge << " ms" << endl;
    cout << endl;

    cout << "Algoritmo de Ordenação por Inserção:" << endl;
    cout << "Maior tempo: " << maxInsertion << " ms" << endl;
    cout << "Menor tempo: " << minInsertion << " ms" << endl;
    cout << "Média: " << avgInsertion << " ms" << endl;

    return 0;
}
