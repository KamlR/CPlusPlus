
#include <vector>
#include <string>
#ifndef ANALYZESORTINGS_ARRAYOPERATIONS_H
#define ANALYZESORTINGS_ARRAYOPERATIONS_H


class ArrayOperations {
private:
    std::vector<int> zeroToFive;
    std::vector<int> zeroToFourThousand;
    std::vector<int> almostSorted;
    std::vector<int> reverseOrder;
    std::vector<std::string> nameSort;

public:
    ArrayOperations(std::vector<int> &zeroToFive, std::vector<int> &zeroToFourThousand, std::vector<int> &almostSorted,
                      std::vector<int> &reverseOrder, std::vector<std::string> &nameSort);
    void randomZeroToFive(uint64_t (*sortFunc)(std::vector<int> &nums, int n), int index_name);
    void randomZeroToFourThousand(uint64_t (*sortFunc)(std::vector<int> &nums, int n), int index_name);
    void randomAlmostSorted(uint64_t (*sortFunc)(std::vector<int> &nums, int n), int index_name);
    void randomReverseOrder(uint64_t (*sortFunc)(std::vector<int> &nums, int n), int index_name);
};


#endif//ANALYZESORTINGS_ARRAYOPERATIONS_H
