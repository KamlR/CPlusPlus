#include "sorting_operations.h"
#include <string>
#ifndef ANALYZESORTINGS_SORTINGOPERATIONS_H
#define ANALYZESORTINGS_SORTINGOPERATIONS_H


class SortingOperations {
private:
    std::vector<int> zeroToFive;
    std::vector<int> zeroToFourThousand;
    std::vector<int> almostSorted;
    std::vector<int> reverseOrder;
    std::vector<std::string> nameSort;

public:
    SortingOperations(std::vector<int> &zeroToFive, std::vector<int> &zeroToFourThousand, std::vector<int> &almostSorted,
                      std::vector<int> &reverseOrder, std::vector<std::string> &nameSort);
    void randomZeroToFive(uint64_t (*sortFunc)(std::vector<int> &nums, int n), int index_name);
    void randomZeroToFourThousand(uint64_t (*sortFunc)(std::vector<int> &nums, int n), int index_name);
    void randomAlmostSorted(uint64_t (*sortFunc)(std::vector<int> &nums, int n), int index_name);
    void randomReverseOrder(uint64_t (*sortFunc)(std::vector<int> &nums, int n), int index_name);
};


#endif//ANALYZESORTINGS_SORTINGOPERATIONS_H
