#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

/**
 * @brief Szablon klasy realizuj¹cy algorytm sortowania przez scalanie (Merge Sort).
 * * Klasa obs³uguje sortowanie wektorów dowolnego typu, który posiada operator porównania.
 * * @tparam T Typ danych przechowywanych w tablicy (np. int, double).
 */
template <typename T>
class MergeSort {
public:
    /**
     * @brief Publiczna metoda sortuj¹ca.
     * * Wywo³uje wewnêtrzn¹, rekurencyjn¹ metodê sortowania.
     * * @param arr Referencja do wektora, który ma zostaæ posortowany.
     */
    void sort(std::vector<T>& arr);

private:
    /**
     * @brief Metoda scalaj¹ca dwie podtablice.
     * * @param arr Wektor danych.
     * @param left Indeks pocz¹tkowy.
     * @param mid Indeks œrodkowy.
     * @param right Indeks koñcowy.
     */
    void merge(std::vector<T>& arr, int left, int mid, int right);

    /**
     * @brief Rekurencyjna metoda dziel¹ca tablicê.
     * * @param arr Wektor danych.
     * @param left Indeks pocz¹tkowy.
     * @param right Indeks koñcowy.
     */
    void sortInternal(std::vector<T>& arr, int left, int right);
};

#endif 