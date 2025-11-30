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

/**
 * @brief Test 5: Sprawdza sortowanie tablicy mieszanej (liczby dodatnie i ujemne).
 *
 * Weryfikuje, czy algorytm poprawnie obs³uguje przejœcie przez zero.
 */
TEST(MergeSortTests, MixedNumbers) {
    MergeSort<int> sorter;
    std::vector<int> arr = { -5, 10, 0, -2, 5 };
    std::vector<int> expected = { -5, -2, 0, 5, 10 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * @brief Test 6: Sprawdza obs³ugê pustej tablicy.
 *
 * Oczekiwane zachowanie: brak rzuconego wyj¹tku i tablica pozostaje pusta.
 */
TEST(MergeSortTests, EmptyArray) {
    MergeSort<int> sorter;
    std::vector<int> arr = {};
    EXPECT_NO_THROW(sorter.sort(arr));
    EXPECT_TRUE(arr.empty());
}

/**
 * @brief Test 7: Sprawdza zachowanie dla tablicy jednoelementowej.
 *
 * Oczekiwane zachowanie: Tablica pozostaje bez zmian.
 */
TEST(MergeSortTests, SingleElement) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 42 };
    std::vector<int> expected = { 42 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * @brief Test 8: Sprawdza sortowanie tablicy z duplikatami (liczby dodatnie).
 *
 * Weryfikuje, czy powtarzaj¹ce siê wartoœci s¹ poprawnie uk³adane obok siebie.
 */
TEST(MergeSortTests, DuplicatesPositive) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 3, 1, 2, 3, 1 };
    std::vector<int> expected = { 1, 1, 2, 3, 3 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * @brief Test 9: Sprawdza sortowanie tablicy z duplikatami (liczby ujemne).
 */
TEST(MergeSortTests, DuplicatesNegative) {
    MergeSort<int> sorter;
    std::vector<int> arr = { -2, -5, -2, -10 };
    std::vector<int> expected = { -10, -5, -2, -2 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * @brief Test 10: Sprawdza sortowanie tablicy mieszanej z duplikatami.
 *
 * Kombinacja liczb ujemnych, dodatnich oraz zera, z powtórzeniami.
 */
TEST(MergeSortTests, DuplicatesMixed) {
    MergeSort<int> sorter;
    std::vector<int> arr = { -1, 2, -1, 0, 2, 5 };
    std::vector<int> expected = { -1, -1, 0, 2, 2, 5 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * @brief Test 11: Sprawdza sortowanie ma³ej tablicy (2 elementy).
 */
TEST(MergeSortTests, TwoElementsSorted) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 1, 2 };
    std::vector<int> expected = { 1, 2 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * @brief Test 12: Test wydajnoœciowy/poprawnoœciowy dla du¿ej tablicy (>100 elementów).
 *
 * Generuje tablicê o rozmiarze 150 z losowymi danymi i sprawdza posortowanie.
 */
TEST(MergeSortTests, LargeArray) {
    MergeSort<int> sorter;
    std::vector<int> arr(150);
    // Generowanie losowych danych
    std::generate(arr.begin(), arr.end(), std::rand);

    sorter.sort(arr);
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end()));
    EXPECT_EQ(arr.size(), 150);
}

/**
 * @brief Test 13: Z³o¿ony test dla du¿ej tablicy z ró¿norodnymi danymi.
 *
 * Tablica zawiera >100 elementów, w tym:
 * - liczby ujemne (z duplikatami),
 * - liczby dodatnie (z duplikatami),
 * - liczby losowe.
 */
TEST(MergeSortTests, LargeArrayMixedAndDuplicates) {
    MergeSort<int> sorter;
    std::vector<int> arr;
    // Dodajemy 50 ujemnych
    for (int i = 0; i < 50; ++i) arr.push_back(-(i % 10)); // duplikaty
    // Dodajemy 50 dodatnich
    for (int i = 0; i < 50; ++i) arr.push_back(i % 10); // duplikaty
    // Dodajemy 20 losowych
    for (int i = 0; i < 20; ++i) arr.push_back(std::rand() % 100 - 50);

    EXPECT_GT(arr.size(), 100);

    sorter.sort(arr);
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end()));
}