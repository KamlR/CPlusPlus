#include "ArrayOperations.h"
#include <fstream>
#include <iostream>

// Просто отдельный класс для вызова методов, которые каждый массив прогоняют на сортировках по операциям
ArrayOperations::ArrayOperations(std::vector<int> &zeroToFive, std::vector<int> &zeroToFourThousand, std::vector<int> &almostSorted,
                                 std::vector<int> &reverseOrder, std::vector<std::string> &nameSort) {
    this->zeroToFive = zeroToFive;
    this->zeroToFourThousand = zeroToFourThousand;
    this->almostSorted = almostSorted;
    this->reverseOrder = reverseOrder;
    this->nameSort = nameSort;
}
void ArrayOperations::randomZeroToFive(uint64_t (*sortFunc)(std::vector<int> &, int), int index_name) {
    std::fstream fs;
    fs.open("random_zero_to_five 50 - 300.txt", std::fstream::out | std::fstream::app);
    fs << "N" + nameSort[index_name] << "\n";
    std::cout << "RandomZeroToFive " << nameSort[index_name] << " 50 - 300\n";
    for (int i = 50; i <= 300; i += 50) {
        std::vector<int> vec;
        std::copy(zeroToFive.begin(), zeroToFive.begin() + i, std::back_inserter(vec));
        fs << i << " " << sortFunc(vec, i) << "\n";
        std::cout << "Size: " << i << " operations: " << sortFunc(vec, i) << "\n";
    }
    fs.close();
    fs.open("random_zero_to_five 100 - 4100.txt", std::fstream::out | std::fstream::app);
    fs << "N" + nameSort[index_name] << "\n";
    std::cout << "RandomZeroToFive " << nameSort[index_name] << " 100 - 4100\n";
    for (int i = 100; i <= 4100; i += 100) {
        std::vector<int> vec;
        std::copy(zeroToFive.begin(), zeroToFive.begin() + i, std::back_inserter(vec));
        fs << i << " " << sortFunc(vec, i) << "\n";
        std::cout << "Size: " << i << " operations: " << sortFunc(vec, i) << "\n";
    }
    fs.close();
}
void ArrayOperations::randomZeroToFourThousand(uint64_t (*sortFunc)(std::vector<int> &, int), int index_name) {
    std::fstream fs;
    fs.open("random_zero_to_four_thousand 50 - 300.txt", std::fstream::out | std::fstream::app);
    fs << "N" + nameSort[index_name] << "\n";
    std::cout << "RandomZeroToFourThousand " << nameSort[index_name] << " 50 - 300\n";
    for (int i = 50; i <= 300; i += 50) {
        std::vector<int> vec;
        std::copy(zeroToFourThousand.begin(), zeroToFourThousand.begin() + i, std::back_inserter(vec));
        fs << i << " " << sortFunc(vec, i) << "\n";
        std::cout << "Size: " << i << " operations: " << sortFunc(vec, i) << "\n";
    }
    fs.close();
    fs.open("random_zero_to_four_thousand 100 - 4100.txt", std::fstream::out | std::fstream::app);
    fs << "N" + nameSort[index_name] << "\n";
    std::cout << "RandomZeroToFourThousand " << nameSort[index_name] << " 100 - 4100\n";
    for (int i = 100; i <= 4100; i += 100) {
        std::vector<int> vec;
        std::copy(zeroToFourThousand.begin(), zeroToFourThousand.begin() + i, std::back_inserter(vec));
        fs << i << " " << sortFunc(vec, i) << "\n";
        std::cout << "Size: " << i << " operations: " << sortFunc(vec, i) << "\n";
    }
    fs.close();
}
void ArrayOperations::randomAlmostSorted(uint64_t (*sortFunc)(std::vector<int> &, int), int index_name) {
    std::fstream fs;
    fs.open("random_almost_sorted 50 - 300.txt", std::fstream::out | std::fstream::app);
    fs << "N" + nameSort[index_name] << "\n";
    std::cout << "RandomAlmostSorted " << nameSort[index_name] << " 50 - 300\n";
    for (int i = 50; i <= 300; i += 50) {
        std::vector<int> vec;
        std::copy(almostSorted.begin(), almostSorted.begin() + i, std::back_inserter(vec));
        fs << i << " " << sortFunc(vec, i) << "\n";
        std::cout << "Size: " << i << " operations: " << sortFunc(vec, i) << "\n";
    }
    fs.close();
    fs.open("random_almost_sorted 100 - 4100.txt", std::fstream::out | std::fstream::app);
    fs << "N" + nameSort[index_name] << "\n";
    std::cout << "RandomAlmostSorted " << nameSort[index_name] << " 100 - 4100\n";
    for (int i = 100; i <= 4100; i += 100) {
        std::vector<int> vec;
        std::copy(almostSorted.begin(), almostSorted.begin() + i, std::back_inserter(vec));
        fs << i << " " << sortFunc(vec, i) << "\n";
        std::cout << "Size: " << i << " operations: " << sortFunc(vec, i) << "\n";
    }
    fs.close();
}
void ArrayOperations::randomReverseOrder(uint64_t (*sortFunc)(std::vector<int> &, int), int index_name) {
    std::fstream fs;
    fs.open("random_reverse_order 50 - 300.txt", std::fstream::out | std::fstream::app);
    fs << "N" + nameSort[index_name] << "\n";
    std::cout << "RandomReverseOrder " << nameSort[index_name] << " 50 - 300\n";
    for (int i = 50; i <= 300; i += 50) {
        std::vector<int> vec;
        std::copy(reverseOrder.begin(), reverseOrder.begin() + i, std::back_inserter(vec));
        fs << i << " " << sortFunc(vec, i) << "\n";
        std::cout << "Size: " << i << " operations: " << sortFunc(vec, i) << "\n";
    }
    fs.close();
    fs.open("random_reverse_order 100 - 4100.txt", std::fstream::out | std::fstream::app);
    fs << "N" + nameSort[index_name] << "\n";
    std::cout << "RandomReverseOrder " << nameSort[index_name] << " 100 - 4100\n";
    for (int i = 100; i <= 4100; i += 50) {
        std::vector<int> vec;
        std::copy(reverseOrder.begin(), reverseOrder.begin() + i, std::back_inserter(vec));
        fs << i << " " << sortFunc(vec, i) << "\n";
        std::cout << "Size: " << i << " operations: " << sortFunc(vec, i) << "\n";
    }
    fs.close();
}
