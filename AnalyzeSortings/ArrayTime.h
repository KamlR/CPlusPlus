#include <vector>
#include <string>
#ifndef ANALYZESORTINGS_ARRAYTIME_H
#define ANALYZESORTINGS_ARRAYTIME_H


class ArrayTime {
private:
    std::vector<int> zeroToFive;
    std::vector<int> zeroToFourThousand;
    std::vector<int> almostSorted;
    std::vector<int> reverseOrder;
    std::vector<std::string> nameSort;

public:
    ArrayTime(std::vector<int> &zeroToFive, std::vector<int> &zeroToFourThousand, std::vector<int> &almostSorted,
              std::vector<int> &reverseOrder, std::vector<std::string> &nameSort);
    void randomZeroToFive(void (*sortFunc)(std::vector<int> &nums, int n), int index_name);
    void randomZeroToFourThousand(void (*sortFunc)(std::vector<int> &nums, int n), int index_name);
    void randomAlmostSorted(void (*sortFunc)(std::vector<int> &nums, int n), int index_name);
    void randomReverseOrder(void (*sortFunc)(std::vector<int> &nums, int n), int index_name);
};


#endif//ANALYZESORTINGS_ARRAYTIME_H
