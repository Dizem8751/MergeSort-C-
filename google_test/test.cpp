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

 /**
  * @brief Klasa (Fixture) testowa dla szablonu MergeSort.
  *
  * U³atwia organizacjê testów. Dziedziczy po ::testing::Test.
  * W tym prostym przypadku s³u¿y g³ównie do zgrupowania testów
  * i ewentualnej inicjalizacji obiektu sortera.
  *
  * @tparam T Typ danych, dla którego uruchamiane s¹ testy.
  */

template <typename T>
class MergeSortTest : public ::testing::Test {
protected:
    MergeSort<T> sorter;
};

/**
 * @brief Test 1: Sprawdza zachowanie dla tablicy ju¿ posortowanej.
 *
 * Weryfikuje, czy algorytm nie zmienia kolejnoœci elementów,
 * jeœli s¹ one ju¿ u³o¿one rosn¹co.
 */
TEST(MergeSortTests, AlreadySorted) {
    MergeSort<int> sorter;
    std::vector<int> arr{1, 2, 3, 4, 5};
    std::vector<int> expected{1, 2, 3, 4, 5};
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * @brief Test 2: Sprawdza sortowanie tablicy posortowanej odwrotnie.
 *
 * Weryfikuje, czy algorytm poprawnie sortuje tablicê u³o¿on¹ malej¹co.
 */
TEST(MergeSortTests, ReverseSorted) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 5, 4, 3, 2, 1 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * @brief Test 3: Sprawdza sortowanie losowej tablicy liczb.
 *
 * Weryfikuje poprawnoœæ sortowania dla typowych, losowych danych wejœciowych.
 * U¿ywa std::is_sorted do sprawdzenia wyniku.
 */
TEST(MergeSortTests, RandomArray) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 12, 5, 1, 99, 23, 4 };
    sorter.sort(arr);
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end()));
}

/**
 * @brief Test 4: Sprawdza sortowanie tablicy zawieraj¹cej tylko liczby ujemne.
 */
TEST(MergeSortTests, NegativeNumbersOnly) {
    MergeSort<int> sorter;
    std::vector<int> arr = { -5, -1, -10, -3 };
    std::vector<int> expected = { -10, -5, -3, -1 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

