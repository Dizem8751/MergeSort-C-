/**
 * @file test.cpp
 * @brief Plik zawieraj¹cy testy jednostkowe Google Test dla algorytmu Merge Sort.
 *
 * Plik ten definiuje zestaw przypadków testowych sprawdzaj¹cych poprawnoœæ
 * dzia³ania klasy MergeSort w ró¿nych scenariuszach, w tym przypadki brzegowe
 * (pusta tablica, jeden element) oraz typowe (tablice losowe, odwrotnie posortowane).
 */

#include "gtest/gtest.h"
#include "../MergeSortC++/MergeSort.h"
#include "../MergeSortC++/MergeSort.cpp"
#include <vector>
#include <algorithm>
#include <random>

template <typename T>
class MergeSortTest : public ::testing::Test {
protected:
    MergeSort<T> sorter;
};

/**
 * @brief Klasa (Fixture) testowa dla szablonu MergeSort.
 *
 * U³atwia organizacjê testów. Dziedziczy po ::testing::Test.
 * W tym prostym przypadku s³u¿y g³ównie do zgrupowania testów
 * i ewentualnej inicjalizacji obiektu sortera.
 *
 * @tparam T Typ danych, dla którego uruchamiane s¹ testy.
 */

TEST(MergeSortTests, AlreadySorted) {
    MergeSort<int> sorter;
    std::vector<int> arr{1, 2, 3, 4, 5};
    std::vector<int> expected{1, 2, 3, 4, 5};
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}