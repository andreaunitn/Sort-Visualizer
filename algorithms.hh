#ifndef ALGORITHM_HH
#define ALGORITHM_HH

#include <vector>

void bubble_sort(std::vector<int>& vec, bool& is_sorting, bool& swapped, int& index);
void insertion_sort(std::vector<int>& vec, bool& is_sorting, int& index);
void selection_sort(std::vector<int>& vec, bool& is_sorting, int& index, int& min_index);

//void merge(std::vector<int>& vec, const int left, const int mid, const int right);
//void merge_sort(std::vector<int>& vec, bool& is_sorting, int& current_size, int& left_start);

#endif