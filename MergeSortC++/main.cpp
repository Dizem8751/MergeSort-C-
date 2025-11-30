/**
 * @file main.cpp
 * @brief Główny plik programu demonstrujący działanie algorytmu Merge Sort.
 *
 * Plik zawiera funkcję main, która tworzy instancje klasy MergeSort dla
 * typów int oraz double, a następnie wykonuje przykładowe sortowanie
 * i wyświetla wyniki na standardowym wyjściu.
 */

#include <iostream>
#include <vector>
#include "MergeSort.h"

 /**
  * @brief Funkcja pomocnicza do wyświetlania zawartości wektora na standardowe wyjście.
  *
  * Funkcja iteruje po wszystkich elementach wektora i wypisuje je oddzielone spacją.
  * Na końcu wypisywany jest znak nowej linii.
  *
  * @tparam T Typ danych przechowywanych w wektorze (musi obsługiwać operator wyjścia <<).
  * @param vec Referencja do wektora stałego (const), który ma zostać wyświetlony.
  */
template <typename T>
void printVector(const std::vector<T>& vec) {
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

/**
 * @brief Główna funkcja programu (Entry Point).
 *
 * Realizuje scenariusz demonstracyjny wymagany w zadaniu:
 * 1. Tworzy instancję klasy MergeSort dla liczb całkowitych (int).
 * 2. Inicjalizuje, wyświetla, sortuje i ponownie wyświetla tablicę int.
 * 3. Tworzy instancję klasy MergeSort dla liczb zmiennoprzecinkowych (double).
 * 4. Inicjalizuje, wyświetla, sortuje i ponownie wyświetla tablicę double.
 *
 * @return Zwraca 0, sygnalizując poprawne zakończenie programu.
 */
int main() {
    std::cout << "=== Demonstracja Merge Sort ===" << std::endl;

    // --- Instancja 1: Liczby całkowite (int) ---
    MergeSort<int> intSorter;
    std::vector<int> intArr = { 12, 7, 14, 9, 10, 11 };
    std::cout << "\nTablica int przed sortowaniem: ";
    printVector(intArr);

    intSorter.sort(intArr);
    std::cout << "Tablica int po sortowaniu:     ";
    printVector(intArr);

    // --- Instancja 2: Liczby zmiennoprzecinkowe (double) ---
    MergeSort<double> doubleSorter;
    std::vector<double> doubleArr = { 3.5, 1.2, 9.9, 0.1, 5.5, 2.3 };

    std::cout << "\nTablica double przed sortowaniem: ";
    printVector(doubleArr);

    doubleSorter.sort(doubleArr);

    std::cout << "Tablica double po sortowaniu:     ";
    printVector(doubleArr);

	return 0;

};