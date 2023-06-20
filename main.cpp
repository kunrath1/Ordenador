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
    cout << "Digite o numero de vezes a executar cada algoritmo (X): ";
    cin >> X;

    vector<vector<int>> vectors(M);
    vector<long long> elapsedTimeSelection(X), elapsedTimeBubble(X), elapsedTimeMerge(X), elapsedTimeInsertion(X);

    for (int i = 0; i < M; ++i) {
        vectors[i] = geradorVetAleatorios(N);
    }

    vector<int> melhorCaso = geradorVetAleatorios(N);
    sort(melhorCaso.begin(), melhorCaso.end());

    vector<int> piorCaso = geradorVetAleatorios(N);
    sort(piorCaso.begin(), piorCaso.end(), greater<int>());

    for (int i = 0; i < X; ++i) {
        for (int j = 0; j < M; ++j) {
            vector<int> arr;

            if (j == 0) {
                arr = melhorCaso;
            }
            else if (j == 1) {
                arr = piorCaso;
            }
            else {
                arr = copiarVet(vectors[j - 2]);
            }

            chrono::high_resolution_clock::time_point comeco, fim;

            // Algoritmo de Ordenação por Seleção
            comeco = chrono::high_resolution_clock::now();
            selectionSort(arr);
            fim = chrono::high_resolution_clock::now();
            elapsedTimeSelection[i] = tempoCorrido(comeco, fim);

            // Algoritmo de Ordenação por Trocas (Bubble Sort)
            arr = copiarVet(vectors[j]);
            comeco = chrono::high_resolution_clock::now();
            bubbleSort(arr);
            fim = chrono::high_resolution_clock::now();
            elapsedTimeBubble[i] = tempoCorrido(comeco, fim);

            // Algoritmo de Ordenação por Intercalação (Merge Sort)
            arr = copiarVet(vectors[j]);
            comeco = chrono::high_resolution_clock::now();
            mergeSort(arr, 0, arr.size() - 1);
            fim = chrono::high_resolution_clock::now();
            elapsedTimeMerge[i] = tempoCorrido(comeco, fim);

            // Algoritmo de Ordenação por Inserção
            arr = copiarVet(vectors[j]);
            comeco = chrono::high_resolution_clock::now();
            insertionSort(arr);
            fim = chrono::high_resolution_clock::now();
            elapsedTimeInsertion[i] = tempoCorrido(comeco, fim);
        }
    }

    // Cálculo das estatísticas
    long long maiorSelection = *max_element(elapsedTimeSelection.begin(), elapsedTimeSelection.end());
    long long menorSelection = *min_element(elapsedTimeSelection.begin(), elapsedTimeSelection.end());
    double mediaSelection = accumulate(elapsedTimeSelection.begin(), elapsedTimeSelection.end(), 0.00000) / X;

    long long maiorBubble = *max_element(elapsedTimeBubble.begin(), elapsedTimeBubble.end());
    long long menorBubble = *min_element(elapsedTimeBubble.begin(), elapsedTimeBubble.end());
    double mediaBubble = accumulate(elapsedTimeBubble.begin(), elapsedTimeBubble.end(), 0.00000) / X;

    long long maiorMerge = *max_element(elapsedTimeMerge.begin(), elapsedTimeMerge.end());
    long long menorMerge = *min_element(elapsedTimeMerge.begin(), elapsedTimeMerge.end());
    double mediaMerge = accumulate(elapsedTimeMerge.begin(), elapsedTimeMerge.end(), 0.00000) / X;

    long long maiorInsertion = *max_element(elapsedTimeInsertion.begin(), elapsedTimeInsertion.end());
    long long menorInsertion = *min_element(elapsedTimeInsertion.begin(), elapsedTimeInsertion.end());
    double mediaInsertion = accumulate(elapsedTimeInsertion.begin(), elapsedTimeInsertion.end(), 0.00000) / X;

    // Exibição dos resultados
    cout << "Resultados:" << endl;
    cout << "Algoritmo de Ordenacao por Selecao:" << endl;
    cout << "Maior tempo: " << maiorSelection << " ms" << endl;
    cout << "Menor tempo: " << menorSelection << " ms" << endl;
    cout << "Media: " << mediaSelection << " ms" << endl;
    cout << endl;

    cout << "Algoritmo de Ordenacao por Trocas (Bubble Sort):" << endl;
    cout << "Maior tempo: " << maiorBubble << " ms" << endl;
    cout << "Menor tempo: " << menorBubble << " ms" << endl;
    cout << "Media: " << mediaBubble << " ms" << endl;
    cout << endl;

    cout << "Algoritmo de Ordenacao por Intercalacao (Merge Sort):" << endl;
    cout << "Maior tempo: " << maiorMerge << " ms" << endl;
    cout << "Menor tempo: " << menorMerge << " ms" << endl;
    cout << "Media: " << mediaMerge << " ms" << endl;
    cout << endl;

    cout << "Algoritmo de Ordenacao por Insercao:" << endl;
    cout << "Maior tempo: " << maiorInsertion << " ms" << endl;
    cout << "Menor tempo: " << menorInsertion << " ms" << endl;
    cout << "Media: " << mediaInsertion << " ms" << endl;

    return 0;
}
