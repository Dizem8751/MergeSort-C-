/**
 * @file MergeSort.cpp
 * @brief Plik Ÿród³owy z implementacj¹ metod klasy MergeSort.
 *
 * Zawiera definicje metod sortowania, scalania oraz jawn¹ instancjacjê szablonów.
 */

#include "MergeSort.h"
#include <iostream>

// --- Implementacja metod klasy MergeSort ---

/**
 * @brief Implementacja publicznej metody sortuj¹cej.
 *
 * Metoda sprawdza, czy wektor nie jest pusty. Jeœli zawiera elementy,
 * uruchamia rekurencyjn¹ metodê sortInternal dla ca³ego zakresu tablicy.
 *
 * @tparam T Typ danych w wektorze.
 * @param arr Referencja do wektora, który ma zostaæ posortowany.
 */

template <typename T>
void MergeSort<T>::sort(std::vector<T>& arr) {
    if (arr.empty()) return;
    sortInternal(arr, 0, static_cast<int>(arr.size()) - 1);
}

/**
 * @brief Implementacja metody scalaj¹cej dwie posortowane podtablice.
 *
 * Algorytm wykonuje nastêpuj¹ce kroki:
 * 1. Oblicza rozmiary dwóch podtablic.
 * 2. Tworzy tymczasowe wektory L (lewy) i R (prawy) i kopiuje do nich dane.
 * 3. Scala te wektory z powrotem do wektora g³ównego, sortuj¹c elementy rosn¹co.
 * 4. Kopiuje ewentualne pozosta³e elementy z wektorów tymczasowych.
 *
 * @tparam T Typ danych w wektorze.
 * @param arr Wektor g³ówny, do którego scalane s¹ dane.
 * @param left Indeks pocz¹tkowy lewej podtablicy.
 * @param mid Indeks koñcowy lewej podtablicy (œrodek).
 * @param right Indeks koñcowy prawej podtablicy.
 */
template <typename T>
void MergeSort<T>::merge(std::vector<T>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; // Rozmiar lewej podtablicy
    int n2 = right - mid;    // Rozmiar prawej podtablicy

    // Tworzenie tablic tymczasowych
    std::vector<T> L(n1);
    std::vector<T> R(n2);

    // Kopiowanie danych do tablic tymczasowych L[] i R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0; // Indeks pocz¹tkowy pierwszej podtablicy
    int j = 0; // Indeks pocz¹tkowy drugiej podtablicy
    int k = left; // Indeks pocz¹tkowy scalonej podtablicy

    // W³aœciwe scalanie dwóch podtablic
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Kopiowanie pozosta³ych elementów L[], jeœli s¹
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Kopiowanie pozosta³ych elementów R[], jeœli s¹
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
