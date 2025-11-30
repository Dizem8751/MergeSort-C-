#include "MergeSort.h"
#include <iostream>

// --- Implementacja metod klasy MergeSort ---

template <typename T>
void MergeSort<T>::sort(std::vector<T>& arr) {
    if (arr.empty()) return;
    sortInternal(arr, 0, static_cast<int>(arr.size()) - 1);
}
