#include <vector>
#include <iostream>
#ifndef ANALYZESORTINGS_SORTING_OPERATIONS_H
#define ANALYZESORTINGS_SORTING_OPERATIONS_H

uint64_t selectionSortOp(std::vector<int> &nums, int n);
uint64_t bubbleSortOp(std::vector<int> &nums, int n);
uint64_t bubbleSortIverson1Op(std::vector<int> &nums, int n);
uint64_t bubbleSortIverson2Op(std::vector<int> &nums, int n);
uint64_t insertionSortOp(std::vector<int> &nums, int n);
uint64_t binaryInsertionSortOp(std::vector<int> &nums, int n);
uint64_t countSortOp(std::vector<int> &nums, int n);
uint64_t radixSortOp(std::vector<int> &nums, int n);
uint64_t mergeSortSOp(std::vector<int> &nums, int n);
uint64_t quickSortQOp(std::vector<int> &nums, int n);
uint64_t heapSortOp(std::vector<int> &nums, int n);
uint64_t shellSortOp(std::vector<int> &nums, int n);
uint64_t cyuSequenceSortOp(std::vector<int> &nums, int n);
#endif//ANALYZESORTINGS_SORTING_OPERATIONS_H
